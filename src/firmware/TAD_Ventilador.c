#include <xc.h>
#include "TAD_Ventilador.h"
#include "TAD_Config.h"
#include "TAD_Timer.h"

//Variables globals
static unsigned char estat[2];
static unsigned char timers[2];

void VENT_InitVent(){
    estat[0] = VENT_CRITICAL;
    TI_NewTimer(&timers[0]);
    estat[1] = VENT_CRITICAL;
    TI_NewTimer(&timers[0]);
    LAT_VENT1 = VENT_ESPERA;
    LAT_VENT2 = VENT_ESPERA;
}

void VENT_setVelocity(unsigned char tempLevel){
    static const unsigned char valors[4][2] = {
        {VENT_LOW, VENT_LOW},           // TEMP_LOW
        {VENT_MODERATE, VENT_MODERATE}, // TEMP_MODERATE
        {VENT_HIGH, VENT_HIGH},         // TEMP_HIGH
        {VENT_CRITICAL, VENT_CRITICAL}  // TEMP_CRITICAL
    };
    
    //Actualitzar l'estat dels ventiladors en funcio de la temperatura llegida
    estat[VENT1] = valors[tempLevel][VENT1];
    estat[VENT2] = valors[tempLevel][VENT2];
}

void motorVentilador(unsigned char v) {
    switch(estat[v]){
        case VENT_LOW:
            //Temperatura = LOW
            if (TI_GetTics(timers[v]) >= VENT_PWM) {
                //Generar el PWM del ventilador 1 (velocitat moderada)
                if (v == VENT1) LAT_VENT1 ^= VENT_ACTIVA;
                else LAT_VENT2 = VENT_ESPERA;   //Ventilador dos sempre apagar
                TI_ResetTics(timers[v]);
            }
            break;

        case VENT_MODERATE:
            //Temperatura = MODERATE
            if (TI_GetTics(timers[v]) >= VENT_PWM) {
                //Generar els PWMs dels dos ventiladors (velocitat moderada)
                if (v == VENT1) LAT_VENT1 ^= VENT_ACTIVA;
                else LAT_VENT2 ^= VENT_ACTIVA;
                TI_ResetTics(timers[v]);
            }
            break;

        case VENT_HIGH:
            //Temperatura = HIGH
            // Posar els dos ventiladors sempre a '1' -> Velocitat alta
            if (v == VENT1) LAT_VENT1 = VENT_ACTIVA;
            else LAT_VENT2 = VENT_ACTIVA;
            break;

        case VENT_CRITICAL:
            //Temperatura = CRITICA -> Els dos ventiladors sempre apagats
            if (v == VENT1) LAT_VENT1 = VENT_ESPERA;
            else LAT_VENT2 = VENT_ESPERA;
            break;
    }
}
