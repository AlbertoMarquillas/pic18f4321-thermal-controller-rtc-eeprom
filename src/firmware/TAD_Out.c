#include <xc.h>
#include "TAD_Out.h"

void OUT_Init(void) {
    LAT_LED_R = 0;
    LAT_LED_G = 0;
    LAT_LED_B = 0;
}

void OUT_EncenLed(unsigned char led) {
    if (led == LED_COLOR_RED)       LAT_LED_R = 1;
    else if (led == LED_COLOR_GREEN) LAT_LED_G = 1;
    else if (led == LED_COLOR_BLUE)  LAT_LED_B = 1;
}

void OUT_ApagaLed(unsigned char led) {
    if (led == LED_COLOR_RED)       LAT_LED_R = 0;
    else if (led == LED_COLOR_GREEN) LAT_LED_G = 0;
    else if (led == LED_COLOR_BLUE)  LAT_LED_B = 0;
}
