#ifndef XC_TAD_LED_H
#define	XC_TAD_LED_H

#include <xc.h>
#include "TAD_Config.h"

/**
 * @brief Inicialitza el sistema de control del LED RGB. 
 *        Crea un temporitzador intern per controlar el parpelleig.
 * 
 * PRE: Cap.
 * POST: El LED queda preparat per ser usat i el temporitzador queda inicialitzat.
 */
void LED_InitLed(void);

/**
 * @brief Estableix el color que ha de mostrar el LED RGB.
 * 
 * @param ledColor Valor de color (LED_COLOR_RED, LED_COLOR_GREEN, LED_COLOR_BLUE...).
 * 
 * PRE: El LED ha estat inicialitzat.
 * POST: El LED mostrarà aquest color si no està en mode parpelleig.
 */
void LED_setLedColor(unsigned char ledColor);

/**
 * @brief Activa o desactiva el mode parpelleig del LED RGB.
 * 
 * @param blinkMode Valor (LED_CERT per activar el blink, LED_FALS per desactivar).
 * 
 * PRE: El LED ha estat inicialitzat.
 * POST: Si està activat, el LED alternarà entre vermell i magenta.
 */
void LED_setBlinkMode(unsigned char blinkMode);

/**
 * @brief Motor cooperatiu del LED. Alterna entre mostrar el color fix o parpellejar
 *        entre vermell i magenta segons el mode seleccionat.
 * 
 * PRE: LED_InitLed() ha estat cridat prèviament.
 * POST: El LED mostra el color indicat o fa parpelleig segons estat i configuració.
 */
void LED_motorLed(void);

#endif	/* XC_TAD_LED_H */
