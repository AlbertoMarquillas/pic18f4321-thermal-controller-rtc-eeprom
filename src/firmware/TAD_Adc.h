#ifndef XC_TAD_ADC_H
#define	XC_TAD_ADC_H

#include <xc.h>
#include "TAD_Config.h"

/**
 * @brief Inicialitza el sistema ADC amb la configuraci� adequada
 *        (format, canal, temps d'adquisici�, etc.).
 * 
 * PRE: Cap.
 * POST: L'ADC queda inicialitzat i llest per comen�ar conversions.
 */
void ADC_InitADC(void);

/**
 * @brief Selecciona el canal actiu per a la propera conversi� ADC.
 * 
 * @param channel Identificador del canal (CH_JOYX, CH_JOYY o CH_TEMP).
 * 
 * PRE: ADC inicialitzat amb ADC_InitADC().
 * POST: Es configura el canal corresponent en el registre ADCON0.
 */
void ADC_selectCH(unsigned char channel);

/**
 * @brief Motor cooperatiu que gestiona el proc�s de conversi� dels canals ADC.
 *        Llegeix c�clicament els canals: temperatura, JoyX i JoyY.
 * 
 * PRE: ADC ha estat inicialitzat amb ADC_InitADC().
 * POST: Es guarda internament el valor dels tres canals. Cal llegir-los amb les funcions get.
 */
void ADC_motorADC(void);

/**
 * @brief Obt� el valor actual del sensor de temperatura (0-255).
 * 
 * PRE: S'ha executat almenys un cicle de conversi� amb ADC_motorADC().
 * POST: Retorna el valor ADC del canal de temperatura.
 */
unsigned char ADC_getTemp(void);

/**
 * @brief Obt� el valor actual de l'eix X del joystick (0-255).
 * 
 * PRE: S'ha executat almenys un cicle de conversi� amb ADC_motorADC().
 * POST: Retorna el valor ADC del canal de JoyX.
 */
unsigned char ADC_getJoyX(void);

/**
 * @brief Obt� el valor actual de l'eix Y del joystick (0-255).
 * 
 * PRE: S'ha executat almenys un cicle de conversi� amb ADC_motorADC().
 * POST: Retorna el valor ADC del canal de JoyY.
 */
unsigned char ADC_getJoyY(void);

#endif	/* XC_TAD_ADC_H */
