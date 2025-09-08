#ifndef XC_TAD_RAM_H
#define	XC_TAD_RAM_H

#include <xc.h>
#include "TAD_Config.h"

/**
 * @brief Inicialitza les línies de control, adreces i bus de dades per a la RAM externa.
 * 
 * PRE: El sistema ha estat inicialitzat i la RAM està connectada correctament.
 * POST: Els pins del microcontrolador queden configurats per accedir a la RAM 62256.
 */
void RAM_Init(void);

/**
 * @brief Escriu una dada a una posició de memòria de la RAM externa.
 * 
 * @param address Direcció de memòria (0 a 32767).
 * @param data Dada a escriure a la memòria.
 * 
 * PRE: La RAM ha estat inicialitzada amb RAM_Init().
 * POST: La dada queda escrita a l?adreça especificada.
 */
void RAM_Write(unsigned int address, unsigned char data);

/**
 * @brief Llegeix una dada d?una posició de la RAM externa.
 * 
 * @param address Direcció de memòria (0 a 32767).
 * @return Dada llegida de la memòria.
 * 
 * PRE: La RAM ha estat inicialitzada amb RAM_Init().
 * POST: Retorna el valor de la memòria a l?adreça especificada.
 */
unsigned char RAM_Read(unsigned int address);


unsigned char RAM_resetRAM(unsigned int ramAddress);

#endif	/* XC_TAD_RAM_H */
