#include "TAD_Config.h"


// Variables globals
static unsigned char estatController;
static unsigned char tempTimer;
static unsigned char temperature, llindar;
static unsigned char lowTemp, highTemp, moderateTemp, tempsMesura;
static unsigned char mes, dia, hora, min, sec;
static unsigned int year; 
unsigned char cadenaEEPROM[15];
unsigned char esticRam = 1, esticEEprom = 1;
unsigned static char flagEE = 0;
static unsigned int ramAddress = 0;
static unsigned char temperatureToSave = 0;
char logComplet[40] = "DATALOGS:00-00-0000 a les 00:00:00\r\n";

void CONTROLLER_initController() {
    EEPROM_restaurarEstat();
    estatController = ESPERA_CONFIG;
    TI_NewTimer(&tempTimer);
}

void CONTROLER_resetController(){
    estatController = ESPERA_CONFIG;
    esticRam = 1;
    flagEE = 0;
    ramAddress = 0;
    temperatureToSave = 0;
}

unsigned char CONTROLLER_GetLlindar(unsigned char temp) {
    if (temp < lowTemp) return TEMP_LOW;
    else if (temp < moderateTemp) return TEMP_MODERATE;
    else if (temp < highTemp) return TEMP_HIGH;
    else return TEMP_CRITICAL;
}

void CONTROLLER_setTempsMostreig(unsigned char nouTemps) {
    TEMP_setTempsMostreig(nouTemps);
    tempsMesura = nouTemps;
}

void CONTROLLER_actualitzaEstat() {
    if (TEMP_hiHaNewTemp() && esticRam == 1 && esticEEprom == 1) estatController = TEMP_SENSOR;
    if (MENU_hiHaNewConfig()) estatController = ESPERA_CONFIG;
}

void CONTROLLER_MotorControlador() {
    CONTROLLER_actualitzaEstat();

    switch (estatController) {
        case ESPERA_CONFIG:
            if (MENU_hiHaNewConfig()) {
                //Agafar els llindars de temperatura
                lowTemp = MENU_getTempBaixa();
                highTemp = MENU_getTempAlta();
                moderateTemp = MENU_getTempModerada();
                estatController = TEMP_SENSOR;
            }
            break;

        case TEMP_SENSOR:
            //Agafar el valor de temperatura
            temperature = TEMP_getTemp();     
            LED_setBlinkMode(LED_FALS);
            llindar = CONTROLLER_GetLlindar(temperature);
            
            //Llegir hora actual per després guardar les dades a la RAM
            RTC_readRTC(&sec, &min, &hora, &dia, &mes, &year);
            
            //Modificar els leds i els ventiladores en funció del valor de temperatura llegit
            switch (llindar) {
                case TEMP_LOW:
                    flagEE = 0;
                    LED_setLedColor(LED_COLOR_GREEN);
                    VENT_setVelocity(VENT_LOW);
                    break;

                case TEMP_MODERATE:
                    flagEE = 0;
                    LED_setLedColor(LED_COLOR_BLUE);
                    VENT_setVelocity(VENT_MODERATE);
                    break;

                case TEMP_HIGH:
                    flagEE = 0;
                    LED_setLedColor(LED_COLOR_RED);
                    VENT_setVelocity(VENT_HIGH);
                    break;

                case TEMP_CRITICAL:
                    //Si la temperatura es crítica i no estem escribint a la EEPROM -> Anem a la EEPROM
                    if (flagEE == 0) {
                        estatController = TEMP_EEPROM; 
                        esticEEprom = 0;
                        flagEE = 1;
                    }
                    LED_setBlinkMode(LED_CERT);
                    VENT_setVelocity(VENT_CRITICAL);
                    break;
            }
            esticRam = 0;
            
            //Si no hem de anar a la EEPROM -> Anem a la RAM
            if (estatController != TEMP_EEPROM) {
                estatController = TEMP_RAM;
            }
            break;

        case TEMP_RAM:
            //Estat de pas per guardar la temperatura llegida
            temperatureToSave = temperature;
            estatController = TEMP_RAM_INIT;
            break;

        case TEMP_RAM_INIT:
            //Escriure nova temperatura a la RAM
            RAM_Write(ramAddress++, temperatureToSave);
            estatController = TEMP_RAM_ESCRIVINT;
            break;

        case TEMP_RAM_ESCRIVINT:
            //Actualitzar l'adreça de la RAM
            if(ramAddress == 32767){    //Si s'arriba a la ultima adreça -> Tornem a la 0
                ramAddress = 0x00;
            }
            estatController = TEMP_RAM_ESPERA;
            break;

        case TEMP_RAM_ESPERA:
            estatController = ESPERA_MOSTREIG;
            esticRam = 1;
            break;

        case TEMP_EEPROM:
            //Formatejar cadena a guardar amb la info llegida del RTC
            cadenaEEPROM[0] = (hora / 10) + '0';
            cadenaEEPROM[1] = (hora % 10) + '0';
            cadenaEEPROM[2] = (min / 10) + '0';
            cadenaEEPROM[3] = (min % 10) + '0';
            cadenaEEPROM[4] = (sec / 10) + '0';
            cadenaEEPROM[5] = (sec % 10) + '0';
            cadenaEEPROM[6] = (dia / 10) + '0';
            cadenaEEPROM[7] = (dia % 10) + '0';
            cadenaEEPROM[8] = (mes / 10) + '0';
            cadenaEEPROM[9] = (mes % 10) + '0';
            cadenaEEPROM[10] = 2 + '0'; //Sempre es el mateix segle
            cadenaEEPROM[11] = (year / 100) % 10 + '0';
            cadenaEEPROM[12] = (year / 10) % 10 + '0';
            cadenaEEPROM[13] = (year % 10) + '0';
            cadenaEEPROM[14] = '\0';

            //!!!!!!!!!!!!
            //EN AQUEST PUNT cadenaEEPROM ES PRINTA BÉ
            //!!!!!!!!!!!!!!
            if (!EEPROM_esticEscriptura()) {
                EEPROM_iniciaEscriptura(cadenaEEPROM);
            } 
            
            //Escriure a la EEPROM
            EEPROM_motorEscriptura();
            estatController = ESPERA_ACABAR_EEPROM;
            
            break;
            
        case ESPERA_ACABAR_EEPROM:
            
            //Esperar que acabi d'escriure
            if (!EEPROM_esticEscriptura() && EEPROM_HasAcabat()) {
                estatController = TEMP_RAM; //Quan hem acabat d'escriure -> Anem a guardar dades a la RAM
                esticEEprom = 1;
            } 
            break;

        case ESPERA_MOSTREIG:
            //Estat d'espera fins que es llegeixi un nou valor
            break;
    }
}

//Calcula l'índex de la EEPROM
unsigned char CONTROLLER_getLogIndex(unsigned char logicalIndex) {
    
    //Agafar el número de logs guardats i  mirar si ha fet una volta sencera
    unsigned char count = EEPROM_getContadorCadenes();
    unsigned char full = EEPROM_getFullTurn();
    unsigned char first = 0;
    if (full) {
        //Si la eeprom esta plena, calcula l'index a partir de l'última adreça
        unsigned char ultima = EEPROM_getUltimaAddr() / (EEPROM_TAM_CADENA + 1); // = 1   
        first = (ultima) % EEPROM_MAX_CADENES; 
    } 
    
    //Retorna índex
    return (first + logicalIndex) % EEPROM_MAX_CADENES; // 2
}

unsigned char CONTROLLER_getLogFormatted(unsigned char logicalIndex, char* cadena) {
    //Agafar l'index i llegir el valor en aquella posició
    unsigned char physicalIndex = CONTROLLER_getLogIndex(logicalIndex);
    if (logicalIndex >= EEPROM_getContadorCadenes()) return 0;
    EEPROM_iniciaLectura(physicalIndex, cadenaEEPROM); 
    
    //Espera a que acabi de llegir
    while (!EEPROM_lecturaCompleta()) {
        EEPROM_motorLectura();
    }
    
    //Modificar els valors de temps amb les dades que s'han llegit
    //HHMMSSDDMMYYYY
    cadena[9]  = cadenaEEPROM[6]; // dia
    cadena[10] = cadenaEEPROM[7];
    cadena[12] = cadenaEEPROM[8]; // mes
    cadena[13] = cadenaEEPROM[9];
    cadena[15] = cadenaEEPROM[10]; // año
    cadena[16] = cadenaEEPROM[11];
    cadena[17] = cadenaEEPROM[12];
    cadena[18] = cadenaEEPROM[13];
    cadena[26] = cadenaEEPROM[0]; // hora
    cadena[27] = cadenaEEPROM[1];
    cadena[29] = cadenaEEPROM[2]; // min
    cadena[30] = cadenaEEPROM[3];
    cadena[32] = cadenaEEPROM[4]; // sec
    cadena[33] = cadenaEEPROM[5];
    cadena[34] = '\r';
    cadena[35] = '\n';
    cadena[36] = '\0';
    
    return 1;
}

unsigned int Controller_getRamAddr(){
    return ramAddress;
}

void Controller_clearRamAddr(){
    ramAddress = 0;;
}
