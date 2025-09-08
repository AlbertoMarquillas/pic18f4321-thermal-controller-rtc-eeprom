#ifndef TAD_EEPROM_H
#define TAD_EEPROM_H

#define EEPROM_TAM_CADENA     14
#define EEPROM_MAX_CADENES    15
#define EEPROM_TAM_TOTAL      ((EEPROM_TAM_CADENA + 1) * EEPROM_MAX_CADENES)

// Lectura/escriptura directa
unsigned char EEPROM_Llegeix(unsigned char addr);
void EEPROM_Escriu(unsigned char addr, unsigned char dada);
unsigned char EEPROM_HasAcabat(void);

// Motors cooperatius
void EEPROM_iniciaEscriptura(const unsigned char* cadena);
void EEPROM_motorEscriptura(void);
void EEPROM_iniciaLectura(unsigned char index, char* dest);
void EEPROM_motorLectura(void);

// Estats dels motors
unsigned char EEPROM_esticEscriptura(void);
unsigned char EEPROM_lecturaCompleta(void);

// Impressió de logs
void EEPROM_printCadenaFormatejada(const char* cadena);
void EEPROM_printUltimaCadena(void);
void EEPROM_printTotsElsLogs(void);

// Gestió de memòria i estat
void EEPROM_reset(void);
void EEPROM_restaurarEstat(void);

// Informació de posicions
unsigned char EEPROM_getContadorCadenes(void);
unsigned char EEPROM_getFullTurn(void);
unsigned char EEPROM_getUltimaAddr(void);
unsigned char EEPROM_getPrimerIndex(void);
unsigned char EEPROM_getIndexSeguent(void);

char EEPROM_formataLogDatalogs(const char* cadena, char* dest);

unsigned char EEPROM_resetEEPROM(void);

void EEPROM_initEEprom();
void resetEEPROMmain();
#endif // TAD_EEPROM_H
