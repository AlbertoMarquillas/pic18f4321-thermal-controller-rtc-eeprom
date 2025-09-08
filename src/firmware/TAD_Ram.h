#ifndef XC_TAD_RAM_H
#define	XC_TAD_RAM_H

#include <xc.h>
#include "TAD_Config.h"

/**
 * @brief Inicialitza les l�nies de control, adreces i bus de dades per a la RAM externa.
 * 
 * PRE: El sistema ha estat inicialitzat i la RAM est� connectada correctament.
 * POST: Els pins del microcontrolador queden configurats per accedir a la RAM 62256.
 */
void RAM_Init(void);

/**
 * @brief Escriu una dada a una posici� de mem�ria de la RAM externa.
 * 
 * @param address Direcci� de mem�ria (0 a 32767).
 * @param data Dada a escriure a la mem�ria.
 * 
 * PRE: La RAM ha estat inicialitzada amb RAM_Init().
 * POST: La dada queda escrita a l?adre�a especificada.
 */
void RAM_Write(unsigned int address, unsigned char data);

/**
 * @brief Llegeix una dada d?una posici� de la RAM externa.
 * 
 * @param address Direcci� de mem�ria (0 a 32767).
 * @return Dada llegida de la mem�ria.
 * 
 * PRE: La RAM ha estat inicialitzada amb RAM_Init().
 * POST: Retorna el valor de la mem�ria a l?adre�a especificada.
 */
unsigned char RAM_Read(unsigned int address);


unsigned char RAM_resetRAM(unsigned int ramAddress);

#endif	/* XC_TAD_RAM_H */
