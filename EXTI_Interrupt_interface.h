/*
 * EXIT_Interrupt_interface.h
 *
 * Created: 3/10/2024 3:44:36 AM
 *  Author: Dr. Roqaia Khalid
 */ 


#ifndef EXTI_INTERRUPT_INTERFACE_H_
#define EXTI_INTERRUPT_INTERFACE_H_


typedef enum{
	EXTI_INT0,
	EXTI_INT1,
	EXTI_INT2
}EXTI_source;


typedef enum{
	EXTI_RISING_EDGE,
	EXTI_FALLING_EDGE,
	EXTI_LOW_LEVEL,
	EXTI_ANY_LOGICAL
	
}EXTI_senseContorl;
typedef void (*EXTI_Callback)(void);

static EXTI_Callback PRV_pFunCallBackINT0 = NULL;
static EXTI_Callback PRV_pFunCallBackINT1 = NULL;
static EXTI_Callback PRV_pFunCallBackINT2 = NULL;

void EXTU_voidEnable(EXTI_source copy_enumInterruptSource,EXTI_source Ecopy_enumSenseControl);
void EXTU_voidDisable(EXTI_source copy_enumInterruptSource);
void EXTI_voidSetCallBackINT0(void(*copy_pFunAction)(void));
void EXTI_voidSetCallBackINT1(void(*copy_pFunAction)(void));
void EXTI_voidSetCallBackINT2(void(*copy_pFunAction)(void));
//void EXTI_voidSetCallBack(EXTI_source interruptSource, EXTI_Callback callback);




#endif /* EXTI_INTERRUPT_INTERFACE_H_ */