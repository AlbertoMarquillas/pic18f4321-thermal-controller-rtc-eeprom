#include <xc.h>
#include "TAD_Adc.h"

// Estat del motor ADC
static unsigned char estat = SELECT_CHANNEL;
static unsigned char canal = 0;

// Variables de sortida
static unsigned char valor_joyx = 0;
static unsigned char valor_joyy = 0;
static unsigned char valor_temp = 0;

void ADC_InitADC(void){
    AD0_ON = ADC_CERT;

    AD1_CONFIG0_ADC = ADC_FALS;
    AD1_CONFIG1_ADC = ADC_FALS;
    AD1_CONFIG2_ADC = ADC_CERT;
    AD1_CONFIG3_ADC = ADC_CERT;

    AD2_FORMAT = ADC_FALS;

    AD2_CONVERSION0 = ADC_CERT;
    AD2_CONVERSION1 = ADC_FALS;
    AD2_CONVERSION2 = ADC_FALS;

    AD2_ACQUISITION0 = ADC_CERT;
    AD2_ACQUISITION1 = ADC_CERT;
    AD2_ACQUISITION2 = ADC_FALS;
}

void ADC_motorADC(void){
    switch(estat){
        case SELECT_CHANNEL:
            AD0_CH = canal;
            estat = INICIA_CONVERSIO;
            break;

        case INICIA_CONVERSIO:
            AD0_DONE = ADC_CERT;
            estat = CONVERSIO;
            break;

        case CONVERSIO:
            if (AD0_DONE == ADC_FALS){
                unsigned char valor = ADRESH;
                
                if (canal == CH_TEMP)   valor_temp = valor;
                else if (canal == CH_JOYY) valor_joyx = valor;
                else if (canal == CH_JOYX) valor_joyy = valor;

                //Passar al següent canal
                canal++;
                if (canal >= NUM_CHANNELS) canal = 0;

                estat = SELECT_CHANNEL;
            }
            break;
    }
}

unsigned char ADC_getTemp(void){ return valor_temp; }
unsigned char ADC_getJoyX(void){ return valor_joyx; }
unsigned char ADC_getJoyY(void){ return valor_joyy; }
