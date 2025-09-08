/*
 * File:   TAD_RB0.c
 * Author: albert & alba
 *
 * Created on 10 de marzo de 2025, 9:26
 */


#include <xc.h>
#include <pic18f4321.h>
#include "TAD_Polsador.h"

//Variables globals
unsigned static char estat, hiHaPolsacio;
unsigned static char timerRB0;


void InitPolsador(){
    TI_NewTimer(&timerRB0);
    hiHaPolsacio = POLS_FALS;
    estat = POLS_NO_PREMUT;
    TRIS_POLS = 1;
}

void POLSADOR_MotorPolsador(){
    switch(estat){
        case POLS_NO_PREMUT:
            //Mirar s'ha premut una polsació
            hiHaPolsacio = POLS_FALS;
            if(PORT_POLS){
                TI_ResetTics(timerRB0);
                estat = POLS_REBOTS_IN;
            }
            break;
            
        case POLS_REBOTS_IN:
            //Comprovar els rebots d'entrada
            if(TI_GetTics(timerRB0) >= REBOTS) estat = POLS_PREMUT;
            break;
        case POLS_PREMUT:
            //Mirar si despres dels rebots, el polsador encara està premut
            if(!PORT_POLS){
                TI_ResetTics(timerRB0);
                estat = POLS_REBOTS_OUT;
            }
            break;
            
        case POLS_REBOTS_OUT:
            //Controlar els rebosts de sortida
            if(TI_GetTics(timerRB0) >= REBOTS){
                //Si no està premut després dels rebots -> Hi ha polsació
                hiHaPolsacio = POLS_CERT; 
                estat = POLS_NO_PREMUT;
            }
            break;
    }    
}

unsigned char POLSADOR_HiHaPolsacio(){
    if(hiHaPolsacio == 1){
        return 1;
    } else {
        return 0;
    }
}