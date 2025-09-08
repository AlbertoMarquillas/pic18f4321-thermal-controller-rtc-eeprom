#ifndef XC_TAD_TEMP_H
#define	XC_TAD_TEMP_H

#include <xc.h>
#include "TAD_Config.h"

/**
 * @brief Inicialitza el sistema de lectura de temperatura.
 * 
 * PRE: Cap.
 * POST: Es crea un temporitzador per controlar la freqüència de lectura.
 */
void TEMP_initTemp(void);

/**
 * @brief Estableix el temps de mostreig entre dues lectures del sensor.
 * 
 * @param nouTemps Temps en tics entre cada lectura (ex: 500 = 1s si TI_GetTics és cada 2ms).
 * 
 * PRE: TEMP_initTemp() ha estat cridat.
 * POST: Les lectures es faran amb la freqüència definida.
 */
void TEMP_setTempsMostreig(unsigned char nouTemps);

/**
 * @brief Retorna l?última temperatura mesurada en °C (enter sense decimals).
 * 
 * PRE: El motor ha fet almenys una lectura vàlida.
 * POST: Retorna un valor entre 0 i 100 (aprox) segons el sensor TMP36.
 */
unsigned char TEMP_getTemp(void);

/**
 * @brief Motor cooperatiu per a la lectura del sensor de temperatura.
 * 
 * PRE: TEMP_initTemp() ha estat cridat, i ADC_motorADC() s?està executant periòdicament.
 * POST: Si ha passat el temps de mostreig, llegeix del ADC i guarda el valor convertit a °C.
 */
void motorTemp(void);


unsigned char TEMP_hiHaNewTemp();

#endif	/* XC_TAD_TEMP_H */
