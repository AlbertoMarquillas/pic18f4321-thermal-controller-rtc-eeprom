#ifndef TAD_RTC_H
#define TAD_RTC_H

// Inicialització del RTC i configuració bàsica d'alarma
char RTC_Init(void);

// Configura hora completa al RTC (valors en decimal)
unsigned char RTC_ConfigurarHora(unsigned char sec, unsigned char min, unsigned char hora,
                                  unsigned char dia, unsigned char mes, unsigned char any);

// Motor cooperatiu per detectar alarma RTC
void RTC_motor(void);

// Llegeix l?hora (minuts i hores) del RTC
void RTC_readRTC(unsigned char *sec, unsigned char *min, unsigned char *hora, unsigned char *dia, unsigned char *mes, unsigned char *year);



#endif // TAD_RTC_H
