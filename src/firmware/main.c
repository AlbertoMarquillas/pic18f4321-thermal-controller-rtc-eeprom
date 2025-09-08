#include <xc.h>
#include "TAD_Config.h"
#include "TAD_Timer.h"
#include "TAD_Controlador.h"
#include "TAD_Menu.h"
#include "TAD_Eeprom.h"
#include "TAD_Joystick.h"
#include "TAD_Temp.h"
#include "TAD_Polsador.h"
#include "TAD_Rtc.h"
#include "TAD_Ventilador.h"
#include "TAD_Led.h"
#include "TAD_I2C.h"
#include "TAD_Sio.h"

// Configuració del microcontrolador
#pragma config OSC = INTIO2
#pragma config PBADEN = DIG
#pragma config WDT = OFF
#pragma config WDTPS = 32768
#pragma config CCP2MX = RC1
#pragma config MCLRE = ON
#pragma config STVREN = ON
#pragma config LVP = OFF

extern void __interrupt (high_priority) HighRSI(void) {
    if (TMR_FLAG == TI_CERT) RSI_Timer0();
}

void InitOsc(void) {
    OSCCON = 120;
    OSCTUNEbits.PLLEN = 1;
}

void InitPorts(void) {
    TRIS_TEMP = ENTRADA;
    TRIS_JOYX = ENTRADA;
    TRIS_JOYY = ENTRADA;
    TRIS_POLS = ENTRADA;
    TRIS_VENT1 = SORTIDA;
    TRIS_VENT2 = SORTIDA;
    TRIS_LED_R = SORTIDA;
    TRIS_LED_G = SORTIDA;
    TRIS_LED_B = SORTIDA;
    TRIS_RTC_SQW = ENTRADA;
    TRIS_RTC_SCL = ENTRADA;
    TRIS_RTC_SDA = ENTRADA;
    TRIS_TX = ENTRADA;
    TRIS_RX = ENTRADA;
    TRISAbits.TRISA6 = 0;
}

void InitMain(void) {
    InitPorts();
    InitOsc();
    TI_Init();
    SIO_Init();
    InitI2C();

    if(RTC_Init() == 1){
        LATAbits.LATA6 = 1;
    } else {
        LATAbits.LATA6 = 0;
    }
    LED_InitLed();
    ADC_InitADC();
    TEMP_initTemp();
    initMenu();
    CONTROLLER_initController();
    InitPolsador();
    RAM_Init();
    //resetEEPROMmain();
    VENT_InitVent();

}
void main(void) {
    InitMain();
    while(1){
        ADC_motorADC();
        JOY_MotorJoystick();
        MENU_MotorMenu();
        POLSADOR_MotorPolsador();
        motorTemp();
        CONTROLLER_MotorControlador();
        motorVentilador(0);
        motorVentilador(1);
        LED_motorLed();
        RTC_motor();
        EEPROM_motorEscriptura();
    }
}
