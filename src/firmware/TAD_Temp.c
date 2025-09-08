#include <xc.h>
#include "TAD_Temp.h"

static unsigned char estatTemp = ESPERA_CONFIG;
static unsigned char valor_temp = 0;
static unsigned char tempsMesura = TEMP_FALS;
static unsigned char hiHaNewTemp = TEMP_FALS;
static unsigned char tempTimer;

void TEMP_initTemp(){
    estatTemp = ESPERA_CONFIG;
    TI_NewTimer(&tempTimer);
    tempsMesura = TEMP_FALS;
}

void TEMP_setTempsMostreig(unsigned char nouTemps){
    tempsMesura = nouTemps;
}

unsigned char TEMP_getTemp(){
    return valor_temp;
}

unsigned char conversioADC_a_Temp(unsigned char adc) {
    return (unsigned char)(((adc * 5000UL / 255) - 500 + 5) / 10);
}




void motorTemp(){
    switch(estatTemp){      
        case ESPERA_CONFIG:
            //Espera una nova configuració (init del java)
            if(MENU_hiHaNewConfig()){
                estatTemp = LLEGINT_TEMP;
            }
            break;

        case ESPERA_TEMPS:
            //Esperar que hagi pasat el temps de conversió per agafar una nova mostra
            hiHaNewTemp = TEMP_FALS;
            if (TI_GetTics(tempTimer) >= (tempsMesura * TEMPS_TICS)){
                estatTemp = LLEGINT_TEMP;
            }
            break;

        case LLEGINT_TEMP:
            //Agafar una nova mostra del sensor i resetejar el timer
            valor_temp = conversioADC_a_Temp(ADC_getTemp());
            TI_ResetTics(tempTimer);
            hiHaNewTemp = TEMP_CERT;
            estatTemp = ESPERA_TEMPS;
            break;
    }
}

unsigned char TEMP_hiHaNewTemp(){
    return hiHaNewTemp;
}
