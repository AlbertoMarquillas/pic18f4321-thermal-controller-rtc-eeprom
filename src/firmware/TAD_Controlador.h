#ifndef TAD_CONTROLADOR_H
#define TAD_CONTROLADOR_H

#include <xc.h>
#include "TAD_Config.h"

// Inicialización del controlador
void CONTROLLER_initController(void);

// Motor principal del controlador
void CONTROLLER_MotorControlador(void);

// Actualiza el estado del controlador
void CONTROLLER_actualitzaEstat(void);

// Establece el tiempo de muestreo
void CONTROLLER_setTempsMostreig(unsigned char nouTemps);

// Clasifica la temperatura actual según los umbrales configurados
unsigned char CONTROLLER_GetLlindar(unsigned char temp);

// Devuelve el índice físico en la EEPROM dado un índice lógico (orden cronológico)
unsigned char CONTROLLER_getLogIndex(unsigned char logicalIndex);

// Formatea una cadena tipo "18-03-2025 a les 19:24:55\r\n" a partir del buffer de EEPROM
void CONTROLLER_formatCadena(char* dest, const char* buffer);

// Obtiene una cadena formateada desde EEPROM por índice cronológico
unsigned char CONTROLLER_getLogFormatted(unsigned char logicalIndex, char* cadena);

unsigned int Controller_getRamAddr();
void Controller_clearRamAddr();

void CONTROLER_resetController();
#endif  // TAD_CONTROLADOR_H
