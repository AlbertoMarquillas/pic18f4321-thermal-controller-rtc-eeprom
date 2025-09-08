/*
 * @file TAD_eusartTX.c
 * @author alberto.marquillas & alba.falcon
 * @date 19 de febrer de 2025
 * @brief Gestió de la comunicació UART en mode asíncron per al PIC18F4321.
 */

 #include <xc.h>
 #include "TAD_Sio.h"
 
/**
  * @brief Inicialitza la comunicaci� UART a 19200 bps.
  * @details Configura els registres de l'EUSART en mode as�ncron amb BRG de 8 bits,
  *          sense alta velocitat (BRGH = 0), ni BRG16. El valor de SPBRG = 25 per aconseguir
  *          una velocitat propera a 19200 bps amb Fosc = 32 MHz.
  * @note Es configuren TRISC6 (TX) i TRISC7 (RX) com a entrades segons la recomanaci� del datasheet.
  */
void SIO_Init(void) {
    
    SPBRG = 25;                 // Valor per a 9600 bps amb Fosc = 32 MHz
    SPBRGH = 0;
    SIO_BAUDRATE = 0;          // BRGH = 0 ? baixa velocitat
    SIO_ASYNC = 0;             // Mode as�ncron
    SIO_TX_ENABLE = 1;         // Habilita transmissi�
    SIO_RX_ENABLE = 1;         // Habilita recepci� cont�nua
    SIO_PORT_ENABLE = 1;       // Habilita el m�dul s�rie
    SIO_BAUDCON_GEN = 0;       // BRG16 = 0 ? generador de 8 bits
}

 /**
  * @brief Comprova si es pot enviar un nou caràcter per UART.
  * @return 1 si el registre de transmissió està buit, 0 en cas contrari.
  */
 char SIOTx_pucEnviar() {
     return SIO_PUC_ENVIAR;
 }
 
 /**
  * @brief Envia un caràcter per UART.
  * @param c Caràcter a enviar.
  */
 void SIOTx_sendChar(char c) {
     TXREG = c;
 }
 
 /**
  * @brief Comprova si s'ha rebut un nou caràcter per UART.
  * @return 1 si hi ha un caràcter disponible, 0 en cas contrari.
  */
 char SIORX_heRebut() {
     return SIO_HE_REBUT;
 }
 
 /**
  * @brief Llegeix un caràcter rebut per UART.
  * @return Caràcter rebut.
  */
 char SIORX_rebreChar(){
     return RCREG;
 }
 