/*
 * GI_program.c
 *
 * Created: 3/10/2024 3:46:21 AM
 *  Author: Dr. Roqaia Khalid
 */ 

//UTILES_LIB
#include "BIT_MATH.h"
#include "STD_TYPES.h"

//MCAL
#include "GI_interface.h"
#include "GI_register.h"


void GI_voidEnable(void){
	SET_BIT(SREG_REG,I);
}
void GI_voidDisable(void){
	CLR_BIT(SREG_REG,I);
}