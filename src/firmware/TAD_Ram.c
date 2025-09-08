#include "TAD_Ram.h"
#include <xc.h>

// ------------------ RAM ------------------

#define RAM_WR                LATEbits.LATE0   // WE
#define RAM_RD                LATEbits.LATE1   // OE
#define RAM_CE                LATEbits.LATE2   // CE

#define TRIS_RAM_WR           TRISEbits.TRISE0
#define TRIS_RAM_RD           TRISEbits.TRISE1
#define TRIS_RAM_CE           TRISEbits.TRISE2

// ------------------ DIRECCIONES ------------------
// Parte baja de dirección (A0?A7) directamente en puerto B
#define RAM_ADDR_LOW          LATB
#define TRIS_RAM_ADDR_LOW     TRISB

// Parte alta de dirección (A8?A14) a través de registros latch 74LS173
#define RAM_ADDR_HIGH         LATB  // misma fuente de datos
#define TRIS_RAM_ADDR_HIGH    TRISB

#define RAM_CLK               LATAbits.LATA7  // Clock de los registros
#define TRIS_RAM_CLK          TRISAbits.TRISA7

// ------------------ DATOS ------------------
// Bus de datos (bidireccional) conectado al puerto D
#define RAM_DATA_OUT          LATD
#define RAM_DATA_IN           PORTD
#define TRIS_RAM_DATA         TRISD

// ------------------ Modos ------------------
#define RAM_INPUT_MODE        0xFF
#define RAM_OUTPUT_MODE       0x00


static unsigned char estat_reset_ram = 0;
static unsigned char index_reset_ram = 0;


void RAM_Init(void) {
    //Configurar els pins com a outputs
    TRIS_RAM_WR = 0;
    TRIS_RAM_RD = 0;
    TRIS_RAM_CE = 0;
    
    //Estat inicial de lectura per evitar col·lisions
    RAM_WR = 1;  
    RAM_RD = 0;  //Sempre llegint
    RAM_CE = 0;  //Enable sempre activat
    
    //COnfigurar adreçes com a sortida
    TRIS_RAM_ADDR_LOW = 0;
    TRIS_RAM_ADDR_HIGH = 0;
    TRIS_RAM_CLK = 0;
    RAM_CLK = 0;
    
    //Bus de dades com input (per defecte estem en lectura)
    TRIS_RAM_DATA = RAM_INPUT_MODE;
    estat_reset_ram = 0;
}

void RAM_Write(unsigned int address, unsigned char data) {
    //Posar el les adreces high pels registres A[8..14]
    RAM_ADDR_HIGH = (address >> 8) & 0x7F;
    RAM_CLK = 0;
    asm("NOP");
    //Activar clock dels registres per shiftar les adreces a la sortida dels registres
    RAM_CLK = 1;
    asm("NOP");
    RAM_CLK = 0;
    
    //Posar el valor de la adreça que va directa a les entrades de la RAM A[0..7]
    RAM_ADDR_LOW = (unsigned char) address;
    
    //Desactivar la lectura
    RAM_RD = 1;   
    asm("NOP");
    
    // Ara, canviar la direcció del bus de dades per fer-la d'entrada
    TRIS_RAM_DATA = RAM_OUTPUT_MODE;
    RAM_DATA_OUT = data;
    
    //Activa escriptura
    RAM_WR = 0;   // Start write cycle
    asm("NOP");
    asm("NOP");   
    RAM_WR = 1;   //Desactiva escripura
    
    //Tornar a mode lectura
    TRIS_RAM_DATA = RAM_INPUT_MODE;  
    asm("NOP");   
    RAM_RD = 0; 
}

unsigned char RAM_Read(unsigned int address) {
    unsigned char data;
    
    //Posar el les adreces high pels registres A[8..14]
    RAM_ADDR_HIGH = (address >> 8) & 0x7F;
    RAM_CLK = 0;
    asm("NOP");
    //Activar clock dels registres per shiftar les adreces a la sortida dels registres
    RAM_CLK = 1;
    asm("NOP");
    RAM_CLK = 0;
    
    //Posar el valor de la adreça que va directa a les entrades de la RAM A[0..7]
    RAM_ADDR_LOW = (unsigned char) address;
    
    //Assegurar que estem en mode lectura
    TRIS_RAM_DATA = RAM_INPUT_MODE;
    RAM_RD = 0;   // Make sure output enable is active
    
    //Nops perquè s'estabillitzin bé les dades
    asm("NOP");
    asm("NOP");
    
    //Llegir les dades 
    data = RAM_DATA_IN;
  
    return data;
}


unsigned char RAM_resetRAM(unsigned int ramAddress) {
    static unsigned char flagSortida = 0;
    switch (estat_reset_ram) {
        case 0:
            //Posar els index a 0
            index_reset_ram = 0;
            estat_reset_ram = 1;
            break;
        case 1:
            //Escriure 0 a totes les adreces de la RAM en les que hem escrit
            if (index_reset_ram < ramAddress) {
                RAM_Write(index_reset_ram, 0);
                index_reset_ram++;
            } else {
                //Hem arribat a l'ultima adreça en la que hem escrit
                flagSortida = 1;
                estat_reset_ram = 0;
            }
            break;
    }
    
    return flagSortida;
}
