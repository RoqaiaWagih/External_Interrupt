
# External Interrupts in AVR ATmega32

## Introduction

External interrupts play a crucial role in microcontroller applications by allowing the system to respond to external events or signals. In AVR ATmega32, there are three external interrupt pins: INT0, INT1, and INT2. This documentation provides an overview of external interrupts and their configuration on the ATmega32 microcontroller.

## Table of Contents

- [External Interrupt Pins](#external-interrupt-pins)
- [Interrupt Registers](#interrupt-registers)
- [Configuring External Interrupts](#configuring-external-interrupts)
- [Interrupt Service Routines (ISRs)](#interrupt-service-routines-isrs)
- [Driver Overview](#driver-overview)
- [Data Sheet](data-sheet)
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


## Driver Overview

### Files

- **Header Files:**
  - `BIT_MATH.h`: A library providing bit manipulation macros.
  - `STD_TYPES.h`: A library containing standard data types.
  - `EXTI_Interrupt_interface.h`: Interface file for external interrupt functions.
  - `EXTI_Interrupt_register.h`: Register definitions for external interrupt configuration.

### Functions

1. **`EXTU_voidEnable`:**
   - **Description:** Enables external interrupts based on the specified interrupt source and sense control.
   - **Parameters:**
     - `copy_enumInterruptSource`: The chosen external interrupt source (INT0, INT1, INT2).
     - `copy_enumSenseControl`: The desired sense control (rising edge, falling edge, low level, any logical change).
   - **Usage Example:**
     ```c
     EXTU_voidEnable(EXTI_INT0, EXTI_RISING_EDGE);
     ```

2. **`EXTU_voidDisable`:**
   - **Description:** Disables the specified external interrupt source.
   - **Parameters:**
     - `copy_enumInterruptSource`: The chosen external interrupt source (INT0, INT1, INT2).
   - **Usage Example:**
     ```c
     EXTU_voidDisable(EXTI_INT1);
     ```

3. **`EXTI_voidSetCallBackINT0`, `EXTI_voidSetCallBackINT1`, `EXTI_voidSetCallBackINT2`:**
   - **Description:** Sets callback functions for the corresponding external interrupt sources.
   - **Parameters:**
     - `copy_pFunAction`: Pointer to the callback function.
   - **Usage Example:**
     ```c
     void myCallbackFunction(void) {
         // Your code here
     }

     EXTI_voidSetCallBackINT0(myCallbackFunction);
     ```

## Interrupt Service Routines (ISRs)

- **ISR(INT0_vect):**
  - **Description:** Interrupt Service Routine for external interrupt INT0.
  - **Usage Example:**
    ```c
    void __vector_1(void) __attribute__((signal));
    void __vector_1(void) {
        // Your code here
    }
    ```

- **ISR(INT1_vect):**
  - **Description:** Interrupt Service Routine for external interrupt INT1.
  - **Usage Example:**
    ```c
    void __vector_2(void) __attribute__((signal));
    void __vector_2(void) {
        // Your code here
    }
    ```

- **ISR(INT2_vect):**
  - **Description:** Interrupt Service Routine for external interrupt INT2.
  - **Usage Example:**
    ```c
    void __vector_3(void) __attribute__((signal));
    void __vector_3(void) {
        // Your code here
    }
    ```

## Example Usage

Here's a simple example demonstrating how to use the external interrupt module:

```c
#include "EXTI_Interrupt_interface.h"

void myCallbackFunction(void) {
    // Your code here
}

int main(void) {
    // Configure external interrupts and other necessary settings

    // Set callback functions
    EXTI_voidSetCallBackINT0(myCallbackFunction);
    EXTI_voidSetCallBackINT1(myCallbackFunction);
    EXTI_voidSetCallBackINT2(myCallbackFunction);

    // Main application code

    while (1) {
        // Your main loop code
    }

    return 0;
}
```
## Data Sheet

[extirnal interrupt](https://github.com/RoqaiaWagih/External_Interrupt/blob/main/interrupt.pdf)



## Conclusion

External interrupts provide a powerful mechanism for responding to external events in AVR ATmega32 microcontroller applications. Understanding the configuration and usage of these interrupts is essential for building responsive and efficient embedded systems.
```

Feel free to customize and expand this documentation based on your project's specific requirements and any additional details you want to include.
