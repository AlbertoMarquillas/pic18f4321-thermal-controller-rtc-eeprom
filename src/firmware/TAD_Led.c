#include <xc.h>
#include "TAD_Led.h"

static unsigned char estat = LED_FALS;
static unsigned char color = LED_FALS;
static unsigned char blink = LED_FALS;
static unsigned char timer;

void LED_InitLed() {
    TI_NewTimer(&timer);
    OUT_ApagaLed(LED_COLOR_BLUE);
    OUT_ApagaLed(LED_COLOR_GREEN);
    OUT_ApagaLed(LED_COLOR_RED);
    color = 0;
    blink = 0;
    estat = LED_FALS;
}

void LED_setLedColor(unsigned char ledColor) {
    color = ledColor;
}

void LED_setBlinkMode(unsigned char blinkMode) {
    blink = blinkMode;
}

void LED_motorLed() {
    if (estat == MIRAR_BLINK) {
        //Mirar si estem en blink (crític) per anar a estat blink o no
        estat = (blink == LED_CERT) ? BLINK_MODE : MIRAR_COLOR;
        return;
    }

    //Si estem en estat blink del LED (vermell + magenta)
    if (estat == BLINK_MODE) {
        
        unsigned int tics = (unsigned int)TI_GetTics(timer);
        
        //Cada 500 tics (1 segon) es canvia l'estat del LED
        if (tics < 500) {
            //El led es posa de color vermell
            OUT_EncenLed(LED_COLOR_RED);
            OUT_ApagaLed(LED_COLOR_BLUE);
        } else if (tics < 1000) {
            //El led es posa de color magenta
            OUT_EncenLed(LED_COLOR_RED);
            OUT_EncenLed(LED_COLOR_BLUE);
        } else {
            TI_ResetTics(timer);
        }

        OUT_ApagaLed(LED_COLOR_GREEN);
        estat = MIRAR_BLINK;
        return;
    }

    // Mirar color que cal activar i activar-lo apagant els altres colors
    if(color == LED_COLOR_RED){
        OUT_ApagaLed(LED_COLOR_GREEN);
        OUT_ApagaLed(LED_COLOR_BLUE);
    }
    
    if(color == LED_COLOR_GREEN){
        OUT_ApagaLed(LED_COLOR_RED);
        OUT_ApagaLed(LED_COLOR_BLUE);
    }
    if(color == LED_COLOR_BLUE){
        OUT_ApagaLed(LED_COLOR_RED);
        OUT_ApagaLed(LED_COLOR_GREEN);
    }
    
    OUT_EncenLed(color);
    estat = MIRAR_BLINK;
}
