#include <xc.h>
#include "TAD_Rtc.h"
#include "TAD_Sio.h"
#include "TAD_I2C.h"
#include <stdio.h>

#define _XTAL_FREQ 32000000


static char last_A1F = 0;


char configura_alarma1(void);
char configura_INTCN_A1IE(void);
char configura_limpiar_flags(void);


char RTC_Init() {
    //Control per assegurar que el RTC s'inicialitza bé
    if (!configura_alarma1()) return 0;
    if (!configura_INTCN_A1IE()) return 0;
    if (!configura_limpiar_flags()) return 0;
        
    return 1;
}


unsigned char decimal_a_bcd(unsigned char valor) {
    return (unsigned char)((valor / 10) << 4) | (valor % 10);
}


unsigned char bcd_a_decimal(unsigned char bcd) {
    return (bcd >> 4) * 10 + (bcd & 0x0F);
}


/**
 * @brief Configura el RTC perqu? comenci a l'hora 00:04:58 (BCD).
 * @return 1 si s'ha escrit correctament, 0 si hi ha hagut error I2C.
 * @note Aquesta funci? ?s opcional i nom?s s'ha d'utilitzar si es vol for?ar l'hora cada vegada.
 */
unsigned char RTC_ConfigurarHora(unsigned char sec, unsigned char min, unsigned char hora,unsigned char dia, unsigned char mes, unsigned char any) {
    if (!StartI2C(0xD0)) return 0;

    if (I2C_Write(0x00) != 2) { I2C_Stop_(); return 0; }

    //Escriure els segons, minuts i hores als registres del RTC
    if (I2C_Write(decimal_a_bcd(sec)) != 2) { I2C_Stop_(); return 0; }
    if (I2C_Write(decimal_a_bcd(min)) != 2) { I2C_Stop_(); return 0; }
    if (I2C_Write(decimal_a_bcd(hora)) != 2) { I2C_Stop_(); return 0; }

    //Escriure el dia, mes i any als registres del RTC
    if (I2C_Write(decimal_a_bcd(1)) != 2) { I2C_Stop_(); return 0; } 
    if (I2C_Write(decimal_a_bcd(dia)) != 2) { I2C_Stop_(); return 0; }
    if (I2C_Write(decimal_a_bcd(mes) & 0x1F) != 2) { I2C_Stop_(); return 0; } //Només bits 0-4
    if (I2C_Write(decimal_a_bcd(any)) != 2) { I2C_Stop_(); return 0; }

    I2C_Stop_();
    return 1;
}



// --- Configuraci?n alarma cada minuto ---
char configura_alarma1(){
    if (!StartI2C(0xD0))return 0;
    if (I2C_Write(0x07) != 2) { I2C_Stop_(); return 0; }
    if (I2C_Write(0x00) != 2) { I2C_Stop_(); return 0; } // A1M1 = 0 ? match second == 00
    if (I2C_Write(0x80) != 2) { I2C_Stop_(); return 0; } // A1M2 = 1
    if (I2C_Write(0x80) != 2) { I2C_Stop_(); return 0; } // A1M3 = 1
    if (I2C_Write(0x80) != 2) { I2C_Stop_(); return 0; } // A1M4 = 1
    I2C_Stop_();
    return 1;
}

char configura_INTCN_A1IE(){
    if (!StartI2C(0xD0)) return 0;
    if (I2C_Write(0x0E) != 2) { I2C_Stop_(); return 0; }
    if (I2C_Write(0x05) != 2) { I2C_Stop_(); return 0; } // INTCN = 1, A1IE = 1
    I2C_Stop_();
    return 1;
}

char configura_limpiar_flags(){
    if (!StartI2C(0xD0)) return 0;
    if (I2C_Write(0x0F) != 2) return 0;
    if (I2C_Write(0x00) != 2) return 0; // Clear A1F
    I2C_Stop_();
    return 1;
}

// --- Motor cooperatiu del RTC ---
void RTC_motor() {

    char valor;
        
    //Llegir el següent registre
    if (!StartI2C(0xD0)) return;
    if (I2C_Write(0x0F) != 2) { I2C_Stop_(); return; }
    if (!ReStartI2C_(0xD1)) return;
    valor = I2C_Read(1);  //Hem acabat de llegir
    I2C_Stop_();
    
    
    // Si A1F = 1 vol dir que ha saltat l'alarma
    if ((valor & 0x01) && !last_A1F) {
        //Setejar alarma al menu ii activar flag
        configura_limpiar_flags();
        MENU_setAlarma(1);
        last_A1F = 1;
    }
    
    // Reset del flag si l'alarma ja no esta activa
    if (!(valor & 0x01)) {
        last_A1F = 0;
    }
}

void RTC_readRTC(unsigned char *sec, unsigned char *min, unsigned char *hora, unsigned char *dia, unsigned char *mes, unsigned char *year) {
    if (!StartI2C(0xD0)) return;
    if (I2C_Write(0x00) != 2) { I2C_Stop_(); return; }
    if (!ReStartI2C_(0xD1)) return;

    //Llegir totes les dades del RTC
    *sec = bcd_a_decimal(I2C_Read(0));   
    *min = bcd_a_decimal(I2C_Read(0));   
    *hora = bcd_a_decimal(I2C_Read(0)); 
    I2C_Read(0);
    *dia = bcd_a_decimal(I2C_Read(0));  
    *mes = bcd_a_decimal(I2C_Read(0) & 0x1F);
    *year = bcd_a_decimal(I2C_Read(1));  
    
    //Parar lectura
    I2C_Stop_();
}

