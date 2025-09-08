#ifndef XC_TAD_POLSADOR_H
#define	XC_TAD_POLSADOR_H

#include <xc.h>
#include "TAD_Config.h"
#include "TAD_Timer.h"

/**
 * @brief Inicialitza el TAD del polsador connectat a PORT_POLS.
 * 
 * PRE: Cap.
 * POST: El polsador s?inicialitza en estat "no premut", i el temporitzador de rebots queda actiu.
 */
void InitPolsador(void);

/**
 * @brief Motor cooperatiu que detecta la pulsació del polsador mitjançant una FSM
 *        amb gestió de rebots.
 * 
 * PRE: POLSADOR_InitPolsador() ha estat cridat.
 * POST: Si es detecta una pulsació vàlida, es marca internament com a POLS_CERT.
 */
void POLSADOR_MotorPolsador(void);

/**
 * @brief Informa si s?ha detectat una nova pulsació del polsador.
 * 
 * @return POLS_CERT (1) si hi ha hagut polsació, POLS_FALS (0) si no.
 * 
 * PRE: S?ha executat el motor de polsador periòdicament.
 * POST: Retorna l?estat intern de detecció de polsació.
 */
unsigned char POLSADOR_HiHaPolsacio(void);

#endif	/* XC_TAD_POLSADOR_H */
