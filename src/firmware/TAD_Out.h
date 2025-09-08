#ifndef XC_TAD_OUT_H
#define	XC_TAD_OUT_H

#include <xc.h>
#include "TAD_Config.h"

/**
 * @brief Inicialitza el m�dul de sortida per controlar LEDs RGB.
 * 
 * PRE: Cap.
 * POST: Els pins dels LEDs queden configurats com a sortida i els LEDs apagats.
 */
void OUT_Init(void);

/**
 * @brief Enc�n un dels LEDs RGB segons el par�metre indicat.
 * 
 * @param led Valor del LED a encendre: LED_COLOR_RED, LED_COLOR_GREEN o LED_COLOR_BLUE.
 * 
 * PRE: OUT_Init() ha estat cridat i el LED especificat �s v�lid.
 * POST: El LED corresponent queda enc�s.
 */
void OUT_EncenLed(unsigned char led);

/**
 * @brief Apaga un dels LEDs RGB segons el par�metre indicat.
 * 
 * @param led Valor del LED a apagar: LED_COLOR_RED, LED_COLOR_GREEN o LED_COLOR_BLUE.
 * 
 * PRE: OUT_Init() ha estat cridat i el LED especificat �s v�lid.
 * POST: El LED corresponent queda apagat.
 */
void OUT_ApagaLed(unsigned char led);

#endif	/* XC_TAD_OUT_H */
