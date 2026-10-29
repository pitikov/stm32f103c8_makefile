/******************************************************************************
 * @file     startup_stm32f103c8.c
 * @brief    CMSIS-Core(M) Device Startup File for
 *           Device STM32F013C8
 * @version  V1.0.0
 * @date     20. January 2021
 ******************************************************************************/
/*
 * Copyright (c) 2009-2021 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include "stm32f103c8.h"

/*---------------------------------------------------------------------------
  External References
 *---------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint64_t __STACK_SEAL;
#endif

extern __NO_RETURN void __PROGRAM_START(void);

/*---------------------------------------------------------------------------
  Internal References
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler  (void);
__NO_RETURN void Default_Handler(void);

/*---------------------------------------------------------------------------
  Exception / Interrupt Handler
 *---------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler      (void) __attribute__ ((weak));
void MemManage_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));
void SecureFault_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));


void WWDG_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));           // Window watchdog interrupt
void PVDP_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));           // VD through EXTI Line detection interrupt
void TAMPER_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));         // Tamper interrupt
void RTC_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));            // RTC global interrupt
void FLASH_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));          // Flash global interrupt
void RCC_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));            // RCC global interrupt
void EXTI0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));          // EXTI Line0 interrupt
void EXTI1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));          // EXTI Line1 interrupt
void EXTI2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));          // EXTI Line2 interrupt
void EXTI3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));          // EXTI Line3 interrupt
void EXTI4_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));          // EXTI Line4 interrupt
void DMA1_Channel1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));  // DMA1 Channel1 global interrupt
void DMA1_Channel2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));  // DMA1 Channel2 global interrupt
void DMA1_Channel3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));  // DMA1 Channel3 global interrupt
void DMA1_Channel4_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));  // DMA1 Channel4 global interrupt
void DMA1_Channel5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));  // DMA1 Channel5 global interrupt
void DMA1_Channel6_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));  // DMA1 Channel6 global interrupt
void DMA1_Channel7_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));  // DMA1 Channel7 global interrupt
void ADC1_2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));         // ADC1 and ADC2 global interrupt
void USB_HP_CAN_TX_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));  // USB High Priority or CAN TX interrupts
void USB_LP_CAN_RX0_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn)); // USB Low Priority or CAN RX0 interrupts
void CAN_RX1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));        // CAN RX1 interrupt
void CAN_SCE_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));        // CAN SCE interrupt
void EXTI9_5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));        // EXTI Line[9:5] interrupts
void TIM1_BRK_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));       // TIM1 Break interrupt
void TIM1_UP_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));        // TIM1 Update interrupt
void TIM1_TRG_COM_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));   // TIM1 Trigger and Commutation interrupts
void TIM1_CC_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));        // TIM1 Capture Compare interrupt
void TIM2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));           // TIM2 global interrupt
void TIM3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));           // TIM3 global interrupt
void TIM4_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));           // TIM4 global interrupt
void I2C1_EV_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));        // I2C1 event interrupt
void I2C1_ER_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));        // I2C1 error interrupt
void I2C2_EV_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));        // I2C2 event interrupt
void I2C2_ER_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));        // I2C2 error interrupt
void SPI1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));           // SPI1 global interrupt
void SPI2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));           // SPI2 global interrupt
void USART_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));          // 1USART1 global interrupt
void USART2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));         // USART2 global interrupt
void USART3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));         // USART3 global interrupt
void EXTI15_10_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));      // EXTI Line[15:10] interrupts
void RTCAlarm_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));       // RTC alarm through EXTI line interrupt
void USBWakeup_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));      // USB wakeup from suspend through EXTI line interrupt
void TIM8_BRK_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));       // TIM8 Break interrupt
void TIM8_UP_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));        // TIM8 Update interrupt
void TIM8_TRG_COM_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));   // TIM8 Trigger and Commutation interrupts
void TIM8_CC_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));        // TIM8 Capture Compare interrupt

#if (defined(DEVICE) && (DEVICE != STM32F103C8))
// Следующие вектора прерываний не доступны для STM32F103C8
void ADC3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));           // ADC3 global interrupt
void FSMC_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));           // FSMC global interrupt
void SDIO_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));           // SDIO global interrupt
void TIM5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));           // TIM5 global interrupt
void SPI3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));           // SPI3 global interrupt
void UART4_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));          // UART4 global interrupt
void UART5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));          // UART5 global interrupt
void TIM6_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));           // TIM6 global interrupt
void TIM7_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));           // TIM7 global interrupt
void DMA2_Channel1_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));  // DMA2 Channel1 global interrupt
void DMA2_Channel2_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));  // DMA2 Channel2 global interrupt
void DMA2_Channel3_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));  // DMA2 Channel3 global interrupt
void DMA2_Channel4_5_IRQHandler(void) __attribute__ ((weak, alias("Default_Handler"), noreturn));// DMA2 Channel4 and DMA2 Channel5 global interrupts
#endif

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

/* ToDo: Add Cortex exception vectors according the used Cortex-Core */
extern const VECTOR_TABLE_Type __VECTOR_TABLE[76];
const VECTOR_TABLE_Type __VECTOR_TABLE[76] __VECTOR_TABLE_ATTRIBUTE = {
    (VECTOR_TABLE_Type)(&__INITIAL_SP), /*     Initial Stack Pointer */
    Reset_Handler,                      /*     Reset Handler */
    NMI_Handler,                        /* -14 NMI Handler */
    HardFault_Handler,                  /* -13 Hard Fault Handler */
    MemManage_Handler,                  /* -12 MPU Fault Handler */
    BusFault_Handler,                   /* -11 Bus Fault Handler */
    UsageFault_Handler,                 /* -10 Usage Fault Handler */
    SecureFault_Handler,                /*  -9 Secure Fault Handler */
    0,                                  /*     Reserved */
    0,                                  /*     Reserved */
    0,                                  /*     Reserved */
    SVC_Handler,                        /*  -5 SVCall Handler */
    DebugMon_Handler,                   /*  -4 Debug Monitor Handler */
    0,                                  /*     Reserved */
    PendSV_Handler,                     /*  -2 PendSV Handler */
    SysTick_Handler,                    /*  -1 SysTick Handler */

    WWDG_IRQHandler,            // Window watchdog interrupt
    PVDP_IRQHandler,            // VD through EXTI Line detection interrupt
    TAMPER_IRQHandler,          // Tamper interrupt
    RTC_IRQHandler,             // RTC global interrupt
    FLASH_IRQHandler,           // Flash global interrupt
    RCC_IRQHandler,             // RCC global interrupt
    EXTI0_IRQHandler,           // EXTI Line0 interrupt
    EXTI1_IRQHandler,           // EXTI Line1 interrupt
    EXTI2_IRQHandler,           // EXTI Line2 interrupt
    EXTI3_IRQHandler,           // EXTI Line3 interrupt
    EXTI4_IRQHandler,           // EXTI Line4 interrupt
    DMA1_Channel1_IRQHandler,   // DMA1 Channel1 global interrupt
    DMA1_Channel2_IRQHandler,   // DMA1 Channel2 global interrupt
    DMA1_Channel3_IRQHandler,   // DMA1 Channel3 global interrupt
    DMA1_Channel4_IRQHandler,   // DMA1 Channel4 global interrupt
    DMA1_Channel5_IRQHandler,   // DMA1 Channel5 global interrupt
    DMA1_Channel6_IRQHandler,   // DMA1 Channel6 global interrupt
    DMA1_Channel7_IRQHandler,   // DMA1 Channel7 global interrupt
    ADC1_2_IRQHandler,          // ADC1 and ADC2 global interrupt
    USB_HP_CAN_TX_IRQHandler,   // USB High Priority or CAN TX interrupts
    USB_LP_CAN_RX0_IRQHandler,  // USB Low Priority or CAN RX0 interrupts
    CAN_RX1_IRQHandler,         // CAN RX1 interrupt
    CAN_SCE_IRQHandler,         // CAN SCE interrupt
    EXTI9_5_IRQHandler,         // EXTI Line[9:5] interrupts
    TIM1_BRK_IRQHandler,        // TIM1 Break interrupt
    TIM1_UP_IRQHandler,         // TIM1 Update interrupt
    TIM1_TRG_COM_IRQHandler,    // TIM1 Trigger and Commutation interrupts
    TIM1_CC_IRQHandler,         // TIM1 Capture Compare interrupt
    TIM2_IRQHandler,            // TIM2 global interrupt
    TIM3_IRQHandler,            // TIM3 global interrupt
    TIM4_IRQHandler,            // TIM4 global interrupt
    I2C1_EV_IRQHandler,         // I2C1 event interrupt
    I2C1_ER_IRQHandler,         // I2C1 error interrupt
    I2C2_EV_IRQHandler,         // I2C2 event interrupt
    I2C2_ER_IRQHandler,         // I2C2 error interrupt
    SPI1_IRQHandler,            // SPI1 global interrupt
    SPI2_IRQHandler,            // SPI2 global interrupt
    USART_IRQHandler,           // 1USART1 global interrupt
    USART2_IRQHandler,          // USART2 global interrupt
    USART3_IRQHandler,          // USART3 global interrupt
    EXTI15_10_IRQHandler,       // EXTI Line[15:10] interrupts
    RTCAlarm_IRQHandler,        // RTC alarm through EXTI line interrupt
    USBWakeup_IRQHandler,       // USB wakeup from suspend through EXTI line interrupt
    TIM8_BRK_IRQHandler,        // TIM8 Break interrupt
    TIM8_UP_IRQHandler,         // TIM8 Update interrupt
    TIM8_TRG_COM_IRQHandler,    // TIM8 Trigger and Commutation interrupts
    TIM8_CC_IRQHandler,         // TIM8 Capture Compare interrupt
    
    #if (defined(DEVICE) && (DEVICE != STM32F103C8))
    ADC3_IRQHandler,            // ADC3 global interrupt
    FSMC_IRQHandler,            // FSMC global interrupt
    SDIO_IRQHandler,            // SDIO global interrupt
    TIM5_IRQHandler,            // TIM5 global interrupt
    SPI3_IRQHandler,            // SPI3 global interrupt
    UART4_IRQHandler,           // UART4 global interrupt
    UART5_IRQHandler,           // UART5 global interrupt
    TIM6_IRQHandler,            // TIM6 global interrupt
    TIM7_IRQHandler,            // TIM7 global interrupt
    DMA2_Channel1_IRQHandler,   // DMA2 Channel1 global interrupt
    DMA2_Channel2_IRQHandler,   // DMA2 Channel2 global interrupt
    DMA2_Channel3_IRQHandler,   // DMA2 Channel3 global interrupt
    DMA2_Channel4_5_IRQHandler, // DMA2 Channel4 and DMA2 Channel5 global interrupts
    #else
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    #endif

};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*---------------------------------------------------------------------------
  Reset Handler called on controller reset
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void)
{
  __set_PSP((uint32_t)(&__INITIAL_SP));

  SystemInit();                    /* CMSIS System Initialization */
  __PROGRAM_START();               /* Enter PreMain (C library entry point) */
}


#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif

/*---------------------------------------------------------------------------
  Hard Fault Handler
 *---------------------------------------------------------------------------*/
void HardFault_Handler(void)
{
  while(1);
}

/*---------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *---------------------------------------------------------------------------*/
void Default_Handler(void)
{
  while(1);
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic pop
#endif
