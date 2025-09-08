#include <xc.h>
#include "TAD_Joystick.h"
#include "TAD_Sio.h"

static unsigned char estatJoy = GET_VALORS;
static unsigned char valor_x = 0, valor_y = 0;

unsigned char JOY_getPosicio() {
    //Agafar els valots de X i Y
    unsigned char centreX = (valor_x >= LLINDAR_INF && valor_x <= LLINDAR_SUP);
    unsigned char centreY = (valor_y >= LLINDAR_INF && valor_y <= LLINDAR_SUP);

    if (centreX) {
        if (centreY) return CENTRE;
        //Si eix Y no esta centrat -> Mirar si ha anat cap a la dreta o l'esquerra
        return (valor_y < LLINDAR_INF) ? DRETA : ESQUERRA;
    }

    if (centreY) {
        //Si eix X no esta centrat -> Mirar si ha anat adalt o abaix
        return (valor_x < LLINDAR_INF) ? ABAIX : ADALT;
    }

    return CENTRE;
}

void JOY_MotorJoystick() {
    //Agafar els valors del Joystick llegit pels ports ADC
    if (estatJoy == GET_VALORS) {
        valor_x = ADC_getJoyX();
        valor_y = ADC_getJoyY();
    }
}
