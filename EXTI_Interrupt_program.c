/*
 * EXIT_Interrupt.c
 *
 * Created: 3/10/2024 3:43:40 AM
 *  Author: Dr. Roqaia Khalid
 */ 
//UTILES_LIB
#include "BIT_MATH.h"
#include "STD_TYPES.h"
//MCAL
#include "EXTI_Interrupt_interface.h"
#include "EXTI_Interrupt_register.h"




void EXTU_voidEnable(EXTI_source copy_enumInterruptSource,EXTI_source copy_enumSenseControl){
	switch(copy_enumInterruptSource){
		case EXTI_INT0:
		switch(copy_enumSenseControl)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR_REG,ISC00);
			SET_BIT(MCUCR_REG,ISC01);
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR_REG,ISC00);
			SET_BIT(MCUCR_REG,ISC01);
			break;
			
			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR_REG,ISC00);
			CLR_BIT(MCUCR_REG,ISC01);
			break;
			
			case EXTI_ANY_LOGICAL :
			SET_BIT(MCUCR_REG,ISC00);
			CLR_BIT(MCUCR_REG,ISC01);
			break;
		}
		SET_BIT(GICR_REG,INT0);
		
		
		break;
		case EXTI_INT1:
		switch(copy_enumSenseControl)
		{
			case EXTI_RISING_EDGE:
			SET_BIT(MCUCR_REG,ISC10);
			SET_BIT(MCUCR_REG,ISC11);
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR_REG,ISC10);
			SET_BIT(MCUCR_REG,ISC11);
			break;
			
			case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR_REG,ISC10);
			CLR_BIT(MCUCR_REG,ISC11);
			break;
			
			case EXTI_ANY_LOGICAL:
			SET_BIT(MCUCR_REG,ISC10);
			CLR_BIT(MCUCR_REG,ISC11);
			break;
		}
		SET_BIT(GICR_REG,INT1);
		break;
		case EXTI_INT2:
		   switch(copy_enumSenseControl)
		   {
			case EXTI_RISING_EDGE:
			SET_BIT( MCUCSR_REG,ISC2);
			
			break;
			
			case EXTI_FALLING_EDGE:
			CLR_BIT( MCUCSR_REG,ISC2);
			
			break;
		}
		SET_BIT(GICR_REG,INT2);
		break;
		default:
		//invalid
		break;
		
	}
	
}
void EXTU_voidDisable(EXTI_source copy_enumInterruptSource){
	switch(copy_enumInterruptSource){
		case EXTI_INT0:
		CLR_BIT(GICR_REG,INT0);
		break;
		case EXTI_INT1:
		
		CLR_BIT(GICR_REG,INT1);
		break;
		
		case EXTI_INT2:
		CLR_BIT(GICR_REG,INT2);
		break;
		
	}
}
/*
void EXTI_voidSetCallBack(EXTI_source interruptSource, EXTI_Callback callback) {
	switch (interruptSource) {
		case EXTI_INT0:
		PRV_pFunCallBackINT0 = callback;
		break;

		case EXTI_INT1:
		PRV_pFunCallBackINT1 = callback;
		break;

		case EXTI_INT2:
		PRV_pFunCallBackINT2 = callback;
		break;

		default:
		// Invalid interrupt source
		break;
	}
}

*/
void EXTI_voidSetCallBackINT0(void(*copy_pFunAction)(void))
{
	if(copy_pFunAction!=NULL)
	{
		
		PRV_pFunCallBackINT0=copy_pFunAction;
		
	}
	else
	{
		//RETURN ERROR STATE
	}
}

void EXTI_voidSetCallBackINT1(void(*copy_pFunAction)(void))
{
	if(copy_pFunAction!=NULL)
	{
		
		PRV_pFunCallBackINT1=copy_pFunAction;
		
	}
	else
	{
		//RETURN ERROR STATE
	}
}

void EXTI_voidSetCallBackINT2(void(*copy_pFunAction)(void))
{
	if(copy_pFunAction!=NULL)
	{
		
		PRV_pFunCallBackINT2=copy_pFunAction;
		
	}
	else
	{
		//RETURN ERROR STATE
	}
}


void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	//DIO_voidTogglePinValue(DIO_PORTA,DIO_PIN4);
	if(PRV_pFunCallBackINT0!=NULL)
	{
		
		PRV_pFunCallBackINT0();
		
	}
}
void __vector_2(void)__attribute__((signal));
void __vector_2(void)
{
	//DIO_voidTogglePinValue(DIO_PORTA,DIO_PIN4);
	if(PRV_pFunCallBackINT1!=NULL)
	{
		
		PRV_pFunCallBackINT1();
		
	}
}

void __vector_3(void)__attribute__((signal));
void __vector_3(void)
{
	//DIO_voidTogglePinValue(DIO_PORTA,DIO_PIN4);
	if(PRV_pFunCallBackINT2!=NULL)
	{
		
		PRV_pFunCallBackINT2();
		
	}
}