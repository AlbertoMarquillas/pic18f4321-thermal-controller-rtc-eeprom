#ifndef XC_TAD_MENU_H
#define	XC_TAD_MENU_H

#include <xc.h>
#include "TAD_Config.h"

/**
 * @brief Retorna el llindar inferior per considerar la temperatura com a LOW.
 * 
 * PRE: El sistema ha rebut la configuració inicial des del Java via menú.
 * POST: Actualment retorna 0 (funció provisional).
 */
unsigned char MENU_getLowTemp(void);

/**
 * @brief Retorna el llindar per considerar la temperatura com a MODERATE.
 * 
 * PRE: El sistema ha rebut la configuració inicial des del Java via menú.
 * POST: Actualment retorna 0 (funció provisional).
 */
unsigned char MENU_getModerateTemp(void);

/**
 * @brief Retorna el llindar per considerar la temperatura com a HIGH.
 * 
 * PRE: El sistema ha rebut la configuració inicial des del Java via menú.
 * POST: Actualment retorna 0 (funció provisional).
 */
unsigned char MENU_getHighTemp(void);

/**
 * @brief Retorna el llindar per considerar la temperatura com a CRITICAL.
 * 
 * PRE: El sistema ha rebut la configuració inicial des del Java via menú.
 * POST: Actualment retorna 0 (funció provisional).
 */
unsigned char MENU_getCriticalTemp(void);

/**
 * @brief Retorna el valor de temps de mostreig per a la lectura de la temperatura.
 * 
 * PRE: El sistema ha rebut la configuració inicial des del Java via menú.
 * POST: Actualment retorna 0 (funció provisional).
 */
unsigned char MENU_getTempsMesuraTemp(void);

/**
 * @brief Actualitza l?estat del menú si s?ha detectat una pulsació.
 * 
 * PRE: El sistema està operatiu i monitoritza l?entrada del polsador.
 * POST: Si hi ha pulsació, l?estat del menú canvia a POLSACIO.
 */
void MENU_actualitzaEstat(void);

/**
 * @brief Motor cooperatiu del sistema de menú. Gestiona l?enviament de comandes
 *        de moviment del joystick i del polsador cap a la interfície Java.
 * 
 * PRE: El mòdul ha estat inicialitzat i està en execució periòdica.
 * POST: Es poden enviar comandes UART segons l?estat del menú.
 */
void MENU_MotorMenu(void);

unsigned int MENU_GetAny(void);
unsigned char MENU_GetMes(void);
unsigned char MENU_GetDia(void);
unsigned char MENU_GetHora(void);
unsigned char MENU_GetMinut(void);
unsigned char MENU_GetSec(void);

void initMenu(void);


unsigned char MENU_hiHaNewConfig();

unsigned char MENU_getTempsMostra();

unsigned char MENU_getTempBaixa();

unsigned char MENU_getTempModerada();

unsigned char MENU_getTempAlta();

void MENU_setAlarma(unsigned char alarma);

//unsigned char MENU_getTempCritica();
#endif	/* XC_TAD_MENU_H */
