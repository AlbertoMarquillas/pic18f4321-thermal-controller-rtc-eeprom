/*
 * @file TAD_eusartTX.c
 * @author alberto.marquillas & alba.falcon
 * @date 19 de febrer de 2025
 * @brief Gesti√≥ de la comunicaci√≥ UART en mode as√≠ncron per al PIC18F4321.
 */

 #include <xc.h>
 #include "TAD_Sio.h"
 
/**
  * @brief Inicialitza la comunicaciÛ UART a 19200 bps.
  * @details Configura els registres de l'EUSART en mode asÌncron amb BRG de 8 bits,
  *          sense alta velocitat (BRGH = 0), ni BRG16. El valor de SPBRG = 25 per aconseguir
  *          una velocitat propera a 19200 bps amb Fosc = 32 MHz.
  * @note Es configuren TRISC6 (TX) i TRISC7 (RX) com a entrades segons la recomanaciÛ del datasheet.
  */
void SIO_Init(void) {
    
    SPBRG = 25;                 // Valor per a 9600 bps amb Fosc = 32 MHz
    SPBRGH = 0;
    SIO_BAUDRATE = 0;          // BRGH = 0 ? baixa velocitat
    SIO_ASYNC = 0;             // Mode asÌncron
    SIO_TX_ENABLE = 1;         // Habilita transmissiÛ
    SIO_RX_ENABLE = 1;         // Habilita recepciÛ contÌnua
    SIO_PORT_ENABLE = 1;       // Habilita el mÚdul sËrie
    SIO_BAUDCON_GEN = 0;       // BRG16 = 0 ? generador de 8 bits
}

 /**
  * @brief Comprova si es pot enviar un nou car√†cter per UART.
  * @return 1 si el registre de transmissi√≥ est√† buit, 0 en cas contrari.
  */
 char SIOTx_pucEnviar() {
     return SIO_PUC_ENVIAR;
 }
 
 /**
  * @brief Envia un car√†cter per UART.
  * @param c Car√†cter a enviar.
  */
 void SIOTx_sendChar(char c) {
     TXREG = c;
 }
 
 /**
  * @brief Comprova si s'ha rebut un nou car√†cter per UART.
  * @return 1 si hi ha un car√†cter disponible, 0 en cas contrari.
  */
 char SIORX_heRebut() {
     return SIO_HE_REBUT;
 }
 
 /**
  * @brief Llegeix un car√†cter rebut per UART.
  * @return Car√†cter rebut.
  */
 char SIORX_rebreChar(){
     return RCREG;
 }
 