#ifndef XC_TAD_JOYSTICK_H
#define	XC_TAD_JOYSTICK_H

#include <xc.h>
#include "TAD_Config.h"

/**
 * @brief Detecta la direcci� actual del joystick a partir dels valors X i Y.
 *
 * PRE: S?han obtingut valors v�lids de l'ADC a trav�s de JOY_motorJoystick().
 * POST: Retorna una de les constants de posici�: CENTRE, ADALT, ABAIX, ESQUERRA, DRETA.
 */
unsigned char JOY_getPosicio(void);

/**
 * @brief Motor cooperatiu del joystick. Actualitza els valors X i Y a partir de l?ADC.
 *
 * PRE: El TAD ADC ha estat inicialitzat amb ADC_InitADC() i ADC_motorADC() s?est� cridant peri�dicament.
 * POST: Els valors del joystick queden emmagatzemats internament i poden ser consultats amb JOY_getPosicio().
 */
void JOY_MotorJoystick(void);

#endif	/* XC_TAD_JOYSTICK_H */
