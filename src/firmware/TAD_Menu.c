#include <xc.h>
#include <string.h>
#include "TAD_Config.h"
#include "TAD_Sio.h"
#include "TAD_Joystick.h"
#include "TAD_Polsador.h"
#include "TAD_Timer.h"
#include "TAD_Rtc.h"
#include "TAD_Eeprom.h"
#include "TAD_Ram.h"
#include "TAD_Out.h"


//Missatges per enviar a la interfície JAVA
static const char *missatges[] = {
    "UP\r\n", "DOWN\r\n", "CENTER\r\n", "LEFT\r\n", "RIGHT\r\n", "SELECT\r\n"
};
static char missatgeHora[20] = "UPDATETIME:00:00\r\n";
static char missatgeDataGraph[14] = "DATAGRAPH:00\r\n";
const char* endMsgGraph = "FINISH\r\n";
static char buffer[40] = "DATALOGS:00-00-0000 a les 00:00:00\r\n";

//Variables globals
static unsigned char i = 0;
static unsigned char c;
static unsigned char estatMenu = ESTAT_JOY, movimentJoy = CENTRE;
static unsigned char posicioMissatge = 0, TimerMenu;
static unsigned char indexMissatgeHora = 0, alarmaRTC = 0;
static unsigned char hiHaNewConfig = MENU_FALS;
static unsigned int year = 0;
static unsigned char hora = 0, minut = 0, day = 0, mes = 0, sec = 0;
static unsigned char tempsMostra, tempBaixa, tempAlta, tempModerada;
static unsigned char startingNewGraph = 1;
static unsigned char missatgeLlegit[50];
static char bufferLog[15];
static unsigned char enviantLogs = 0, indexLogActual = 0, posicioCarLog = 0;
static unsigned char contGraph = 0;
static unsigned int addr = 0;
static unsigned char flagInit = 0;

void initMenu() {
    TI_NewTimer(&TimerMenu);
    flagInit = 0;
}

void MENU_setAlarma(unsigned char alarma) {
    alarmaRTC = alarma;
}



unsigned int MENU_GetAny()   { return year; }
unsigned char MENU_GetMes()   { return mes; }
unsigned char MENU_GetDia()   { return day; }
unsigned char MENU_GetHora()  { return hora; }
unsigned char MENU_GetMinut() { return minut; }
unsigned char MENU_GetSec()   { return sec; }

unsigned char MENU_hiHaNewConfig() { return hiHaNewConfig; }

unsigned char MENU_getTempBaixa()    { return tempBaixa; }
unsigned char MENU_getTempModerada() { return tempModerada; }
unsigned char MENU_getTempAlta()     { return tempAlta; }

void updateHora() {
    //Llegim del RTC i actualitzem l'hora que s'ha llegit
    RTC_readRTC(&sec, &minut, &hora, &day, &mes, &year);
    missatgeHora[11] = (hora / 10) + '0';
    missatgeHora[12] = (hora % 10) + '0';
    missatgeHora[14] = (minut / 10) + '0';
    missatgeHora[15] = (minut % 10) + '0';

    estatMenu = ENVIA_HORA;
}


void separaInitializeCadena(const unsigned char *cadena) {
    
    //Separar la cadena de INITIALIZE que arriba del JAVA (INITIALIZE:2025-04-15 23:18$10$23$25$27$33)
    //Dades de temps i data
    year  = ((cadena[12] - '0') * 1000) + ((cadena[13] - '0') * 100) + ((cadena[14] - '0') * 10) + ((cadena[15] - '0'));
    mes   = (cadena[17] - '0') * 10 + (cadena[18] - '0');
    day   = (cadena[20] - '0') * 10 + (cadena[21] - '0');
    hora  = (cadena[23] - '0') * 10 + (cadena[24] - '0');
    minut = (cadena[26] - '0') * 10 + (cadena[27] - '0');
    //Dades de temperatura
    tempsMostra  = (cadena[29] - '0') * 10 + (cadena[30] - '0');
    tempBaixa    = (cadena[32] - '0') * 10 + (cadena[33] - '0');
    tempModerada = (cadena[35] - '0') * 10 + (cadena[36] - '0');
    tempAlta     = (cadena[38] - '0') * 10 + (cadena[39] - '0');
   
    //Modificar la hora i el temps de mostreig de la temperatura
    CONTROLLER_setTempsMostreig(tempsMostra);
    RTC_ConfigurarHora(0, minut, hora, day, mes, year % 100);
}

void MENU_actualitzaEstat() {
    if (POLSADOR_HiHaPolsacio()) {
        estatMenu = ENVIANT_JOY;
        movimentJoy = PREMUT;
        posicioMissatge = 0;
    }
    if (alarmaRTC && flagInit) {
        estatMenu = ACTUALITZA_HORA;
        alarmaRTC = 0;
    }
}

// 
void MENU_LlegirRamPerGraph(unsigned int address) {
    //Llegir el valor de la RAM en l'adreça indicada
    unsigned char valor = RAM_Read(address);
    // Actualizar el valor llegit en missatgeDataGraph[] que es la cadena que s'enviarà al JAVA
    missatgeDataGraph[10] = valor / 10 + '0';
    missatgeDataGraph[11] = valor % 10 + '0';  
}

void MENU_MotorMenu() {
    MENU_actualitzaEstat();

    switch (estatMenu) {
        case ESTAT_JOY:
            //Agafem el moviment en el que està el joystick
            posicioMissatge = 0;
            hiHaNewConfig = MENU_FALS;
            movimentJoy = JOY_getPosicio();
            //Si el joystick s'ha mogut -> Estat per enviar el moviment
            if (movimentJoy != CENTRE) {
                estatMenu = ENVIANT_JOY;
                
            }
            break;

        case ENVIANT_JOY:
            //Enviar el moviment que ha fet el joystick (guardat a *missatges[] )
            if (SIOTx_pucEnviar()) {
                SIOTx_sendChar(missatges[movimentJoy][posicioMissatge]);
                if (missatges[movimentJoy][posicioMissatge] == '\n') {
                    TI_ResetTics(TimerMenu);
                    posicioMissatge = 0;
                    //Si s'ha acabat d'enviar, mirem si s'ha premut un polsador i canviem d'estat
                    estatMenu = (movimentJoy == PREMUT) ? ESTAT_LLEGEIX : ESTAT_ESPERA;
                }
                posicioMissatge++;
            }
            break;

        case ESTAT_ESPERA:
            //Esperar 100 tics (200 ms) perquè el joystick no es torni loco
            if (TI_GetTics(TimerMenu) >= 100){               
                estatMenu = ESTAT_JOY;
            }
            break;

        case ESTAT_LLEGEIX:
            //Llegir la cadena que hem rebut del JAVA
            if (SIORX_heRebut()) {
                missatgeLlegit[posicioMissatge] = SIORX_rebreChar();
                if (missatgeLlegit[posicioMissatge] == '\n'){
                    estatMenu = ESTAT_AGAFA_DADES;
                } 
                posicioMissatge++;  
            }
            break;


        case ESTAT_AGAFA_DADES:    
            //Comparar la cadena amb les possibles opcions que hi ha i anar al corresponent estat
            if (!memcmp(missatgeLlegit + 1, "INITIALIZE:", 11)) {
                flagInit = 1;
                //Init del sistema
                separaInitializeCadena(missatgeLlegit);
                hiHaNewConfig = MENU_CERT;
                estatMenu = ESTAT_JOY;
            } else if (!memcmp(missatgeLlegit + 1, "SET_TIME:", 9)) {
                //Set una nova hora
                estatMenu = ESTAT_SET_TIME;
            } else if (!memcmp(missatgeLlegit + 1, "GET_LOGS", 8)) {
                //Mostrar EEPROM
                indexLogActual = 0;
                estatMenu = ESTAT_GET_LOGS;
            } else if (!memcmp(missatgeLlegit + 1, "GET_GRAPH", 9)) {
                //Mostra RAM
                startingNewGraph = 1;  
                estatMenu = ESTAT_GET_GRAPH;
            } else if (!memcmp(missatgeLlegit + 1, "RESET", 5)) {
                //Reset de tot el sistema
                addr = 0;
                estatMenu = ESTAT_RESET_EEPROM;
            } else {
                estatMenu = ESTAT_JOY;
            }
            
           // memset(missatgeLlegit, '\0', 50);

            break;

        case ESTAT_SET_TIME:
            //Modificar les variables de hora i minut amb els valors llegits del java
            hora  = (missatgeLlegit[10]  - '0') * 10 + (missatgeLlegit[11] - '0');
            minut = (missatgeLlegit[13] - '0') * 10 + (missatgeLlegit[14] - '0');
            //Actualitzar hora al RTC
            RTC_ConfigurarHora(0, minut, hora, day, mes, year % 100);
            estatMenu = ACTUALITZA_HORA;
            break;

        case ESTAT_GET_LOGS:
            if (!enviantLogs) {
                
                //Encara no estem enviant cap log (o ja hem acabat d'enviar un)
                if (indexLogActual < EEPROM_getContadorCadenes()) {
                    //Agafar un nou log per poder printat-lo
                    if (CONTROLLER_getLogFormatted(indexLogActual, buffer)) {
                        posicioCarLog = 0;
                        enviantLogs = 1; //Indicar que cal enviar un nou log
                    } else {
                        indexLogActual++;
                    }
                } else {
                    //Si hem acabat de enviar tots els logs -> Enviar el FINISH
                    const char* endMsg = "FINISH\r\n";
                    strcpy(buffer, endMsg);
                    posicioCarLog = 0;
                    enviantLogs = 2;  //Final
                }
            } else {
                if (SIOTx_pucEnviar()) {
                    //Enviar el log -> Enviar el caracter de la posició de la cadena en la que estem
                    SIOTx_sendChar(buffer[posicioCarLog]);
                    if (buffer[posicioCarLog] == '\n') {
                        if (enviantLogs == 1) {
                            //Encara estem enviant logs
                            enviantLogs = 0;
                            indexLogActual++;
                        } else {
                            //Hem acabat d'enviar el finish -> Posar a 0 les variables
                            enviantLogs = 0;
                            indexLogActual = 0;
                            addr = 0;              
                            contGraph = 0;     
                            strcpy(buffer, "DATALOGS:00-00-0000 a les 00:00:00\r\n");
                            
                            estatMenu = ESTAT_JOY;  
                        }
                    }
                    posicioCarLog++;
                }
            }
            break;

        case ACTUALITZA_HORA:
            //Actualitzar l'hora
            updateHora();
            indexMissatgeHora = 0;
            estatMenu = ENVIA_HORA;
            break;

        case ENVIA_HORA:
            //Enviar la cadena UPDATETIME:00:00\r\n amb l'hora actualitzada
            if (SIOTx_pucEnviar()) {
                SIOTx_sendChar(missatgeHora[indexMissatgeHora]);
                if (missatgeHora[indexMissatgeHora] == '\n') {
                    //Quan hem acabat, tornar l'estat del joystick
                    estatMenu = ESTAT_JOY;
                    indexMissatgeHora = 0;
                } else {
                    indexMissatgeHora++;
                }
            }
            break;

        
        case ESTAT_GET_GRAPH:
            //Estat per enviar les dades de la RAM
            if (startingNewGraph == 1) {
                addr = 0;                   //resetejar l'adreça a 0 per llegir des de l'inici
                enviantLogs = 0;
                startingNewGraph = 0;       //Indicar que ja estem enviant
            }
            contGraph = 0;

            if(addr < Controller_getRamAddr()) {
                //Mentres que l'adreça en la que estem, sigui mes petita que l'última adreça en la que hem escrit
                MENU_LlegirRamPerGraph(addr++);
                estatMenu = ESTAT_ENVIA_GRAPH;
            } else {
                //Hem acabat de llegir tota la info que hi ha guardada a la RAM
                estatMenu = ESTAT_SEND_FINISH;
            }
            break;
        case ESTAT_ENVIA_GRAPH:
            //Enviar el missatge "DATAGRAPH:00\r\n" amb la temperatura llegida de la RAM
            if (SIOTx_pucEnviar()) {
                SIOTx_sendChar(missatgeDataGraph[contGraph]);
                if (missatgeDataGraph[contGraph] == '\n') {
                    //Tornar a l'estat anterior per llegir la següent adreça i enviar el següent valor
                    estatMenu = ESTAT_GET_GRAPH;
                    contGraph = 0;
                }  else {
                    contGraph++;                
                }
            }
            
            break;
            
        case ESTAT_SEND_FINISH: 
            //S'han acabat d'ennviar tots els valors que hi havia guardats a la RAM -> Enviar el finish
            if (SIOTx_pucEnviar()) {
                SIOTx_sendChar(endMsgGraph[contGraph]);
                if (endMsgGraph[contGraph] == '\n') {
                    addr = 0;
                    startingNewGraph = 1;  //Indicar que ja no estem enviant les dades de la RAM
                    estatMenu = ESTAT_JOY;
                    contGraph = 0;
                } else {
                    contGraph++;                
                }
            }
            break;
                    
        case ESTAT_RESET_EEPROM:
            //Fer un reset de la EEPROM
            if (EEPROM_resetEEPROM()) {
                estatMenu = ESTAT_RESET_RAM;    //Anar a l'estat que fa reset de la RAM
            }   
            break;
        case ESTAT_RESET_RAM:
            //Fer un reset de la RAM
            if (RAM_resetRAM(Controller_getRamAddr())) {
                estatMenu = ESTAT_RESET_SYS;    //Anar a l'estat que fa reset a la resta de variables i perifèrics
            }
            break;
        case ESTAT_RESET_SYS:
            //Fer reset a la resta de TADs
            flagInit = 0;
            LED_InitLed();
            TEMP_initTemp();
            VENT_InitVent();
            EEPROM_initEEprom();
            RAM_Init();
            CONTROLER_resetController();
            estatMenu = ESTAT_JOY;
            break;
    }
}




   
