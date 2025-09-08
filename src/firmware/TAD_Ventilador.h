#ifndef XC_TAD_VENTILADOR_H
#define	XC_TAD_VENTILADOR_H

#include <xc.h>
#include "TAD_Config.h"

/**
 * @brief Inicialitza els dos ventiladors, configurant els temporitzadors i posant-los en estat inactiu.
 * 
 * PRE: Cap.
 * POST: Els ventiladors queden apagats (CRITICAL) i preparats per controlar-se amb PWM simulat.
 */
void VENT_InitVent(void);

/**
 * @brief Estableix el nivell de velocitat dels ventiladors segons el nivell de temperatura.
 * 
 * @param tempLevel Nivell de temperatura: VENT_LOW, VENT_MODERATE, VENT_HIGH o VENT_CRITICAL.
 * 
 * PRE: Els ventiladors han estat inicialitzats amb VENT_InitVent().
 * POST: Els ventiladors canvien el seu comportament segons la configuració especificada.
 */
void VENT_setVelocity(unsigned char tempLevel);

/**
 * @brief Motor cooperatiu per controlar el funcionament d?un ventilador concret.
 * 
 * @param ventilador Índex del ventilador (VENT1 o VENT2).
 * 
 * PRE: El ventilador ha estat inicialitzat. La funció ha de ser cridada periòdicament.
 * POST: El ventilador s?activa o desactiva segons el mode configurat, amb PWM si cal.
 */
void motorVentilador(unsigned char ventilador);

#endif	/* XC_TAD_VENTILADOR_H */
