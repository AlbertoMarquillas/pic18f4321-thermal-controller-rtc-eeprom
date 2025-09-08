#ifndef XC_TAD_CONFIG_H
#define	XC_TAD_CONFIG_H

#include <xc.h> 

#include "TAD_Adc.h"
#include "TAD_Controlador.h"
#include "TAD_Eeprom.h"
#include "TAD_I2C.h"
#include "TAD_Joystick.h"
#include "TAD_Led.h"
#include "TAD_Menu.h"
#include "TAD_Out.h"
#include "TAD_Polsador.h"
#include "TAD_Ram.h"
#include "TAD_Rtc.h"
#include "TAD_Sio.h"
#include "TAD_Temp.h"
#include "TAD_Timer.h"
#include "TAD_Ventilador.h"

// ------------------ PORTS ------------------
#define SORTIDA 0
#define ENTRADA 1

#define TRIS_TEMP     TRISAbits.TRISA0
#define PORT_TEMP     PORTAbits.RA0
#define TRIS_JOYX     TRISAbits.TRISA1
#define PORT_JOYX     PORTAbits.RA1
#define TRIS_JOYY     TRISAbits.TRISA2
#define PORT_JOYY     PORTAbits.RA2
#define TRIS_POLS     TRISAbits.TRISA3
#define PORT_POLS     PORTAbits.RA3

#define TRIS_VENT1    TRISAbits.TRISA4
#define LAT_VENT1     LATAbits.LATA4
#define TRIS_VENT2    TRISAbits.TRISA5
#define LAT_VENT2     LATAbits.LATA5

#define TRIS_LED_R    TRISCbits.TRISC0
#define LAT_LED_R     LATCbits.LATC0
#define TRIS_LED_B    TRISCbits.TRISC1
#define LAT_LED_B     LATCbits.LATC1
#define TRIS_LED_G    TRISCbits.TRISC2
#define LAT_LED_G     LATCbits.LATC2

#define TRIS_RTC_SQW  TRISBbits.TRISB0
#define TRIS_RTC_SCL  TRISCbits.TRISC3
#define TRIS_RTC_SDA  TRISCbits.TRISC4
#define TRIS_TX       TRISCbits.TRISC6
#define TRIS_RX       TRISCbits.TRISC7

#define PORT_RTC_SQW  PORTBbits.RB0
#define TMR_FLAG      INTCONbits.TMR0IF

// ------------------ TIMER ------------------
#define TI_FALS       0
#define TI_CERT       1
#define OSC_PLL       OSCTUNEbits.PLLEN

// ------------------ LED ------------------
#define LED_STATE_OFF     0
#define LED_STATE_ON      1

#define LED_COLOR_RED     1
#define LED_COLOR_GREEN   2
#define LED_COLOR_BLUE    3

#define LED_MODE_BLINK    3
#define LED_MODE_OFF      0

#define MIRAR_BLINK       0
#define BLINK_MODE        1
#define MIRAR_COLOR       2

#define LED_CERT          1
#define LED_FALS          0

// ------------------ POLSADOR ------------------
#define REBOTS            16
#define POLS_CERT         1
#define POLS_FALS         0

#define POLS_NO_PREMUT    0
#define POLS_REBOTS_IN    1
#define POLS_PREMUT       2
#define POLS_REBOTS_OUT   3

// ------------------ EEPROM ------------------
#define EEPROM_WRITE_FLAG     EECON1bits.WR
#define EEPROM_WRITE_ENABLE   EECON1bits.WREN
#define EEPROM_ACCES          EECON1bits.CFGS
#define EEPROM_SELECT         EECON1bits.EEPGD
#define EEPROM_READ_FLAG      EECON1bits.RD
#define COMBINACIO_0          0x55
#define COMBINACIO_1          0xAA

// ------------------ UART (SIO) ------------------
#define SIO_BAUDRATE       TXSTAbits.BRGH
#define SIO_ASYNC          TXSTAbits.SYNC
#define SIO_TX_ENABLE      TXSTAbits.TXEN
#define SIO_RX_ENABLE      RCSTAbits.CREN
#define SIO_PORT_ENABLE    RCSTAbits.SPEN
#define SIO_BAUDCON_GEN    BAUDCONbits.BRG16
#define SIO_PUC_ENVIAR     TXSTAbits.TRMT 
#define SIO_HE_REBUT       PIR1bits.RCIF

// ------------------ ADC ------------------
#define AD0_ON             ADCON0bits.ADON
#define AD0_CH             ADCON0bits.CHS
#define AD0_DONE           ADCON0bits.GODONE

#define AD1_CONFIG0_ADC    ADCON1bits.PCFG0
#define AD1_CONFIG1_ADC    ADCON1bits.PCFG1
#define AD1_CONFIG2_ADC    ADCON1bits.PCFG2
#define AD1_CONFIG3_ADC    ADCON1bits.PCFG3

#define AD2_CONVERSION0    ADCON2bits.ADCS0
#define AD2_CONVERSION1    ADCON2bits.ADCS1
#define AD2_CONVERSION2    ADCON2bits.ADCS2
#define AD2_ACQUISITION0   ADCON2bits.ACQT0
#define AD2_ACQUISITION1   ADCON2bits.ACQT1   
#define AD2_ACQUISITION2   ADCON2bits.ACQT2
#define AD2_FORMAT         ADCON2bits.ADFM

#define CH_TEMP            0
#define CH_JOYY            1
#define CH_JOYX            2

#define ADC_CERT           1
#define ADC_FALS           0

#define TEMP_CERT          1
#define TEMP_FALS          0
#define TEMPS_TICS         500
#define NUM_CHANNELS       3

#define SELECT_CHANNEL     0
#define INICIA_CONVERSIO   1
#define CONVERSIO          2

// ------------------ JOYSTICK ------------------
#define ADALT     0
#define ABAIX     1
#define CENTRE    2
#define ESQUERRA  3
#define DRETA     4
#define PREMUT    5
#define LLINDAR_INF        50
#define LLINDAR_SUP        200
#define GET_VALORS         0

// ------------------ TEMPERATURE ------------------
#define TEMP_ESPERA_TEMPS     0
#define TEMP_LLEGINT_TEMP     1
#define ESPERA_CONFIG         0
#define ESPERA_TEMPS          1
#define LLEGINT_TEMP          2
#define TEMP_LOW              0
#define TEMP_MODERATE         1
#define TEMP_HIGH             2
#define TEMP_CRITICAL         3

// ------------------ RTC ------------------
#define RTC_ESPERA_1S         0
#define RTC_START_WRITE       1
#define RTC_WRITE_REG_ADDR    2
#define RTC_RESTART_READ      3
#define RTC_READ_SECONDS      4
#define RTC_READ_MINUTES      5
#define RTC_READ_HOURS_STOP   6
#define RTC_RESET_TICS        7

#define ADDR_REG_INIT         0x00
#define RTC_ADDR_WRITE        0xD0
#define RTC_ADDR_READ         0xD1
#define READ_ACK              0
#define READ_READY            1

// ------------------ MENU ------------------
#define ESTAT_ESPERA_CONFIG   0
#define ESTAT_JOY             1
#define ENVIANT_JOY           2
#define ESTAT_ESPERA          3
#define ESTAT_LLEGEIX         4
#define ESTAT_AGAFA_DADES     5
#define ESTAT_INITIALIZE      6
#define ESTAT_SET_TIME        7
#define ESTAT_GET_LOGS        8
#define ESTAT_GET_GRAPH       9
#define ESTAT_RESET_SYS       10
#define ESTAT_FI_LOGS         11
#define ACTUALITZA_HORA       12
#define ENVIA_HORA            13
#define ESTAT_ENVIA_GRAPH     14
#define ESTAT_SEND_FINISH     15
#define ESTAT_RESET_EEPROM    16
#define ESTAT_RESET_RAM       17
#define ESTAT_RESET_SYS       18

#define MENU_CERT             1
#define MENU_FALS             0

// ------------------ CONTROLADOR ------------------
#define CONT_CERT             1
#define CONT_FALS             0
#define TEMP_RAM              1
#define TEMP_RAM_INIT         6
#define TEMP_RAM_ESCRIVINT    7
#define TEMP_RAM_ESPERA       8
#define TEMP_SENSOR           2
#define TEMP_EEPROM           3
#define ESPERA_ACABAR_EEPROM  4
#define ESPERA_MOSTREIG       5
#define REQ_JOY               0
#define REQ_RESET             1

// ------------------ VENTILADORS ------------------
#define VENT_ESPERA           0
#define VENT_ACTIVA           1
#define VENT_LOW              0
#define VENT_MODERATE         1
#define VENT_HIGH             2
#define VENT_CRITICAL         3
#define VENT_PWM              50
#define VENT1                 0
#define VENT2                 1


#endif	/* XC_TAD_CONFIG_H */