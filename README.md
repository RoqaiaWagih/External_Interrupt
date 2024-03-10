
# External Interrupts in AVR ATmega32

## Introduction

External interrupts play a crucial role in microcontroller applications by allowing the system to respond to external events or signals. In AVR ATmega32, there are three external interrupt pins: INT0, INT1, and INT2. This documentation provides an overview of external interrupts and their configuration on the ATmega32 microcontroller.

## Table of Contents

- [External Interrupt Pins](#external-interrupt-pins)
- [Interrupt Registers](#interrupt-registers)
- [Configuring External Interrupts](#configuring-external-interrupts)
- [Interrupt Service Routines (ISRs)](#interrupt-service-routines-isrs)
- [Example Code](#example-code)
- [Conclusion](#conclusion)

## External Interrupt Pins

1. **INT0 (PD2):** External Interrupt Request 0. It corresponds to pin PD2.
2. **INT1 (PD3):** External Interrupt Request 1. It corresponds to pin PD3.
3. **INT2 (PB2):** External Interrupt Request 2. It corresponds to pin PB2.

## Interrupt Registers

- **MCUCR (MCU Control Register):** Configures the sense control (rising/falling/low/any logical change) of INT0 and INT1.
- **MCUCSR (MCU Control and Status Register):** Configures the sense control (rising/falling) of INT2.
- **GICR (General Interrupt Control Register):** Enables/Disables external interrupts INT0, INT1, and INT2.
- **SREG (Status Register):** Global Interrupt Enable bit (I-bit) must be set for interrupts to be enabled.

## Configuring External Interrupts

To enable an external interrupt, follow these steps:

1. Configure the sense control for the corresponding interrupt pin using MCUCR and MCUCSR.
2. Enable the global interrupt flag by setting the I-bit in SREG.
3. Enable the specific external interrupt by setting the corresponding bit in GICR.
# My PDF Document

<iframe src="your_file.pdf" width="800" height="600"></iframe>


## Interrupt Service Routines (ISRs)

- **ISR(INT0_vect):** Interrupt Service Routine for INT0.
- **ISR(INT1_vect):** Interrupt Service Routine for INT1.
- **ISR(INT2_vect):** Interrupt Service Routine for INT2.

## Example Code

Here's a simple example demonstrating how to configure and use external interrupts:

```c
#include "EXTI_Interrupt_interface.h"
#include "GI_interface.h"
#include "DIO_Interface.h"

void fun(void);
int main(void)
{
    /* Replace with your application code */
		DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_INPUT);
		DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
		
		GI_voidEnable();
		EXTI_voidSetCallBackINT1(&fun);
		EXTU_voidEnable(EXTI_INT1,EXTI_FALLING_EDGE);
    while (1) 
    {

}
}


void fun(void)
{
	
	DIO_voidTogglePinValue(DIO_PORTA,DIO_PIN4);
}
```

## Conclusion

External interrupts provide a powerful mechanism for responding to external events in AVR ATmega32 microcontroller applications. Understanding the configuration and usage of these interrupts is essential for building responsive and efficient embedded systems.
```

Feel free to customize and expand this documentation based on your project's specific requirements and any additional details you want to include.
