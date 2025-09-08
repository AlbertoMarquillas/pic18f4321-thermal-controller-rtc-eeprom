#include <xc.h>
#include "TAD_Eeprom.h"
#include "TAD_Sio.h"

#define EEPROM_TAM_CADENA     14
#define EEPROM_MAX_CADENES    15
#define EEPROM_TAM_TOTAL      ((EEPROM_TAM_CADENA + 1) * EEPROM_MAX_CADENES)
#define EEPROM_START_ADDR     2

static unsigned char estat_motor_eeprom = 0;
static unsigned char index_escriptura = 0;
static unsigned char eeprom_addr_actual = EEPROM_START_ADDR;
static unsigned char contador_cadenes = 0;
static unsigned char full_turn = 0;
static const unsigned char* cadena_a_guardar = 0;

static unsigned char estat_motor_lectura = 0;
static unsigned char index_lectura = 0;
static unsigned char lectura_index_objetiu = 0;
static char* buffer_lectura = 0;
static unsigned char lectura_completa = 0;
static unsigned char estat_reset_eeprom = 0;

static unsigned char index_reset = 0;



void EEPROM_initEEprom(){
    estat_motor_eeprom = 0;
    index_escriptura = 0;
    eeprom_addr_actual = EEPROM_START_ADDR;
    contador_cadenes = 0;
    full_turn = 0;
    cadena_a_guardar = 0;
    estat_motor_lectura = 0;
    index_lectura = 0;
    lectura_index_objetiu = 0;
    buffer_lectura = 0;
    lectura_completa = 0;
    estat_reset_eeprom = 0;
    index_reset = 0;
}
void prepara_read() {
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EECON1bits.RD = 1;
}

void prepara_write() {
    EECON1bits.EEPGD = 0;
    EECON1bits.CFGS = 0;
    EECON1bits.WREN = 1;
}

unsigned char EEPROM_Llegeix(unsigned char addr) {
    EEADR = addr;
    prepara_read();
    return EEDATA;
}

void EEPROM_Escriu(unsigned char addr, unsigned char dada) {
    EEADR = addr;
    EEDATA = dada;
    prepara_write();
    di();
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;
    ei();
}

unsigned char EEPROM_HasAcabat() {
    unsigned char ha_acabat = !EECON1bits.WR;
    if (ha_acabat) EECON1bits.WREN = 0;
    return ha_acabat;
}

void EEPROM_iniciaEscriptura(const unsigned char* cadena) {
    cadena_a_guardar = cadena;
    estat_motor_eeprom = 1;
}

void EEPROM_motorEscriptura(void) {
    switch (estat_motor_eeprom) {
        case 0:
            //Estat de pas
            break;
        case 1:
            if (EEPROM_HasAcabat()) {
                //Escriure caràcter a caràcter la informació a la EEPROM 
                if (index_escriptura < EEPROM_TAM_CADENA + 1) {
                    unsigned char addr = eeprom_addr_actual + index_escriptura;
                    EEPROM_Escriu(addr, cadena_a_guardar[index_escriptura]);
                    index_escriptura++;
                } else {
                    //Si s'ha escrit tota la cadena -> Anem al següent estat
                    estat_motor_eeprom = 2;
                }
            }
            break;
        case 2:
            //Incrementar la adreça actual (des de on estem + 15 (la cadena són 15 caràcters)
            eeprom_addr_actual += EEPROM_TAM_CADENA + 1;
            if (eeprom_addr_actual >= EEPROM_TAM_TOTAL + EEPROM_START_ADDR) {
                //Si s'ha fet una volta sencera -> Posar eeprom_addr_actual a la primera adreça on escribim (2)
                eeprom_addr_actual = EEPROM_START_ADDR; 
                full_turn = 1;
            }
            contador_cadenes++;
            if (contador_cadenes > EEPROM_MAX_CADENES) contador_cadenes = EEPROM_MAX_CADENES;
            estat_motor_eeprom = 3;
            break;
        case 3:
            //Modifiquem el punter de la adreça actual (està escrit en la posició 0 de la EEPROM)
            if (EEPROM_HasAcabat()) {
                EEPROM_Escriu(0x00, eeprom_addr_actual);
                estat_motor_eeprom = 4;
            }
            break;
        case 4:
            //Modificar el valor que indica quantes cadenes hem escrit (està escrit en la posició 1 de la EEPROM)
            if (EEPROM_HasAcabat()) {
                EEPROM_Escriu(0x01, contador_cadenes);
                estat_motor_eeprom = 5;
            }
            break;
        case 5:
            //Si hem acabat estat = 0;
            if (EEPROM_HasAcabat()) {
                index_escriptura = 0;
                estat_motor_eeprom = 0;
            }
            break;
    }
}

void EEPROM_restaurarEstat(void) {
    //Llegir l'adreça actual (última on hem escrit) i la quantitat de cadenes que hem escrit
    eeprom_addr_actual = EEPROM_Llegeix(0x00);
    contador_cadenes = EEPROM_Llegeix(0x01);

    // Verifica si la EEPROM està buida o amb valors invàlids
    if (eeprom_addr_actual == 0xFF || contador_cadenes == 0xFF || contador_cadenes == 0) {
        eeprom_addr_actual = EEPROM_START_ADDR;
        contador_cadenes = 0;
        full_turn = 0;
        return;
    }
    
    //Verifica si el valor que hem llegit està fora dels limits de la EEPROM
    if (eeprom_addr_actual < EEPROM_START_ADDR || eeprom_addr_actual >= EEPROM_TAM_TOTAL + EEPROM_START_ADDR)
        eeprom_addr_actual = EEPROM_START_ADDR;

    //Mirar si la dade de contador_cadenes esta per sobre del límit, si esta al màxim, posar que hem fet un full turn
    if (contador_cadenes > EEPROM_MAX_CADENES) contador_cadenes = EEPROM_MAX_CADENES;
    full_turn = (contador_cadenes == EEPROM_MAX_CADENES) ? 1 : 0;
}

void EEPROM_iniciaLectura(unsigned char index, char* dest) {
    if (index >= EEPROM_MAX_CADENES) return;
    lectura_index_objetiu = index; 
    index_lectura = 0;
    estat_motor_lectura = 1;
    lectura_completa = 0;
    buffer_lectura = dest; // dentro de EEPROM_iniciaLectura()
}

void EEPROM_motorLectura(void) {
    static unsigned char base_addr;
    switch (estat_motor_lectura) {
        case 0: 
            //Estat de pas
            break;
        case 1:
            //Actualitzar la adreça de la que llegirem
            base_addr = EEPROM_START_ADDR + (lectura_index_objetiu) * (EEPROM_TAM_CADENA + 1); 
            estat_motor_lectura = 2;
            break;
 
        case 2:
            
            if (index_lectura < EEPROM_TAM_CADENA) {
                //Si encara no hem llegit tots els caràcters que ha de tenir la cadena -> Continuem llegint
                buffer_lectura[index_lectura] = EEPROM_Llegeix(base_addr + index_lectura);
                index_lectura++;
            } else {
                //Si hem acabat de llegir tota la cadena -> Tornar a l'estat 0
                buffer_lectura[EEPROM_TAM_CADENA] = '\0';
                lectura_completa = 1;
                estat_motor_lectura = 0;
            }
            break;
    }
}

unsigned char EEPROM_lecturaCompleta(void) {
    return lectura_completa;
}

unsigned char EEPROM_esticEscriptura(void) {
    return estat_motor_eeprom != 0;
}

unsigned char EEPROM_getFullTurn(void) {
    return full_turn;
}

unsigned char EEPROM_getContadorCadenes(void) {
    return contador_cadenes;
}

unsigned char EEPROM_getUltimaAddr(void) {
    return eeprom_addr_actual;
}


unsigned char EEPROM_resetEEPROM(void) {
    static unsigned char flagSortida = 0;
    switch (estat_reset_eeprom) {
        case 0:
            //Posar l'índex a 0
            index_reset = 0;
            estat_reset_eeprom = 1;
            break;
        case 1:
            if (EEPROM_HasAcabat()) {
                //Posar 0xFF a totes les adreces fins que arribem al final
                if (index_reset < EEPROM_TAM_TOTAL + EEPROM_START_ADDR) {
                    EEPROM_Escriu(index_reset, 0xFF);
                    index_reset++;
                } else {
                    estat_reset_eeprom = 2;
                }
            }
            break;
        case 2:
            //Hem acabat de posar 0xFF a totes les adreces de la EEPROM
            estat_reset_eeprom = 0;
            flagSortida = 1;
            break;
    }
    
    return flagSortida;
}


void resetEEPROMmain(){
    static unsigned char index = 0;
    while(index < EEPROM_TAM_TOTAL + EEPROM_START_ADDR){
        EEPROM_Escriu(index, 0xFF);
        index++;
    }
}