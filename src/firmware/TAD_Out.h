#ifndef XC_TAD_OUT_H
#define	XC_TAD_OUT_H

#include <xc.h>
#include "TAD_Config.h"

/**
 * @brief Inicialitza el mòdul de sortida per controlar LEDs RGB.
 * 
 * PRE: Cap.
 * POST: Els pins dels LEDs queden configurats com a sortida i els LEDs apagats.
 */
void OUT_Init(void);

/**
 * @brief Encén un dels LEDs RGB segons el paràmetre indicat.
 * 
 * @param led Valor del LED a encendre: LED_COLOR_RED, LED_COLOR_GREEN o LED_COLOR_BLUE.
 * 
 * PRE: OUT_Init() ha estat cridat i el LED especificat és vàlid.
 * POST: El LED corresponent queda encès.
 */
void OUT_EncenLed(unsigned char led);

/**
 * @brief Apaga un dels LEDs RGB segons el paràmetre indicat.
 * 
 * @param led Valor del LED a apagar: LED_COLOR_RED, LED_COLOR_GREEN o LED_COLOR_BLUE.
 * 
 * PRE: OUT_Init() ha estat cridat i el LED especificat és vàlid.
 * POST: El LED corresponent queda apagat.
 */
void OUT_ApagaLed(unsigned char led);

#endif	/* XC_TAD_OUT_H */
