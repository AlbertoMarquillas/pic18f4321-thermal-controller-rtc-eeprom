#ifndef _TAD_I2C_H
#define _TAD_I2C_H

/* Pinout I2C (per DS3231 amb PIC18F4321)
SDA: Serial Data  ? PIN RC4
SCL: Serial Clock ? PIN RC3
SQW: Active low interrupt (si es fa servir)
*/

#define BAUDRATE 79  // Fosc = 32 MHz ? 100 kHz = ((32e6 / (4 * (SSPADD + 1))) ? SSPADD = 79

// -------------- Funcions privades: --------------
void I2C_Ready();
void I2C_Ack();
void I2C_Nack();

// -------------- Funcions públiques I2C bàsic: --------------
void InitI2C();
char StartI2C(char slave_rw_addr);
char ReStartI2C_(char slave_rw_addr);
char I2C_Stop_(void);
char I2C_Write(unsigned char data);
char I2C_Read(char flag);  // Versió bloquejant (deprecated si treballes de forma cooperativa)

// -------------- Funcions per lectura cooperativa: --------------
void I2C_IniciaLectura(char flag);
void I2C_MotorLectura();
char I2C_HeLLegeix();
char I2C_getLectura();

#endif
