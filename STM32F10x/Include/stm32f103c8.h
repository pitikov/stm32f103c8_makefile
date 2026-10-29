/**************************************************************************//**
 * @file     stm32f103c8.h
 * @brief    CMSIS-Core(M) Device Header File for Device STM32F103C8
 *
 * @version  V1.0.0
 * @date     18. July 2023
 ******************************************************************************/
/*
 * Copyright (c) 2009-2023 Arm Limited. All rights reserved.
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

#ifndef STM32F103C8_H
#define STM32F103C8_H

#ifdef __cplusplus
extern "C" {
#endif


/* ========================================================================= */
/* ============           Interrupt Number Definition           ============ */
/* ========================================================================= */

typedef enum IRQn
{
/* ================     Cortex-M Core Exception Numbers     ================ */

  Reset_IRQn             = -15,  /*  1 Reset Vector
                                       invoked on Power up and warm reset */
  NonMaskableInt_IRQn    = -14,  /*  2 Non maskable Interrupt
                                       cannot be stopped or preempted */
  HardFault_IRQn         = -13,  /*  3 Hard Fault
                                       all classes of Fault */
  MemoryManagement_IRQn  = -12,  /*  4 Memory Management
                                       MPU mismatch, including Access Violation and No Match */
  BusFault_IRQn          = -11,  /*  5 Bus Fault
                                       Pre-Fetch-, Memory Access, other address/memory Fault */
  UsageFault_IRQn        = -10,  /*  6 Usage Fault
                                       i.e. Undef Instruction, Illegal State Transition */
  SecureFault_IRQn       =  -9,  /*  7 Secure Fault Interrupt */
  SVCall_IRQn            =  -5,  /* 11 System Service Call via SVC instruction */
  DebugMonitor_IRQn      =  -4,  /* 12 Debug Monitor */
  PendSV_IRQn            =  -2,  /* 14 Pendable request for system service */
  SysTick_IRQn           =  -1,  /* 15 System Tick Timer */

/* ================        STM32F103C8 Interrupt Numbers       ================ */

  WWDG_IRQn,           // Window watchdog interrupt
  PVDP_IRQn,           // VD through EXTI Line detection interrupt
  TAMPER_IRQn,         // Tamper interrupt
  RTC_IRQn,            // RTC global interrupt
  FLASH_IRQn,          // Flash global interrupt
  RCC_IRQn,            // RCC global interrupt
  EXTI0_IRQn,          // EXTI Line0 interrupt
  EXTI1_IRQn,          // EXTI Line1 interrupt
  EXTI2_IRQn,          // EXTI Line2 interrupt
  EXTI3_IRQn,          // EXTI Line3 interrupt
  EXTI4_IRQn,          // EXTI Line4 interrupt
  DMA1_Channel1_IRQn,  // DMA1 Channel1 global interrupt
  DMA1_Channel2_IRQn,  // DMA1 Channel2 global interrupt
  DMA1_Channel3_IRQn,  // DMA1 Channel3 global interrupt
  DMA1_Channel4_IRQn,  // DMA1 Channel4 global interrupt
  DMA1_Channel5_IRQn,  // DMA1 Channel5 global interrupt
  DMA1_Channel6_IRQn,  // DMA1 Channel6 global interrupt
  DMA1_Channel7_IRQn,  // DMA1 Channel7 global interrupt
  ADC1_2_IRQn,         // ADC1 and ADC2 global interrupt
  USB_HP_CAN_TX_IRQn,  // USB High Priority or CAN TX interrupts
  USB_LP_CAN_RX0_IRQn, // USB Low Priority or CAN RX0 interrupts
  CAN_RX1_IRQn,        // CAN RX1 interrupt
  CAN_SCE_IRQn,        // CAN SCE interrupt
  EXTI9_5_IRQn,        // EXTI Line[9:5] interrupts
  TIM1_BRK_IRQn,       // TIM1 Break interrupt
  TIM1_UP_IRQn,        // TIM1 Update interrupt
  TIM1_TRG_COM_IRQn,   // TIM1 Trigger and Commutation interrupts
  TIM1_CC_IRQn,        // TIM1 Capture Compare interrupt
  TIM2_IRQn,           // TIM2 global interrupt
  TIM3_IRQn,           // TIM3 global interrupt
  TIM4_IRQn,           // TIM4 global interrupt
  I2C1_EV_IRQn,        // I2C1 event interrupt
  I2C1_ER_IRQn,        // I2C1 error interrupt
  I2C2_EV_IRQn,        // I2C2 event interrupt
  I2C2_ER_IRQn,        // I2C2 error interrupt
  SPI1_IRQn,           // SPI1 global interrupt
  SPI2_IRQn,           // SPI2 global interrupt
  USART_IRQn,          // 1USART1 global interrupt
  USART2_IRQn,         // USART2 global interrupt
  USART3_IRQn,         // USART3 global interrupt
  EXTI15_10_IRQn,      // EXTI Line[15:10] interrupts
  RTCAlarm_IRQn,       // RTC alarm through EXTI line interrupt
  USBWakeup_IRQn,      // USB wakeup from suspend through EXTI line interrupt
  TIM8_BRK_IRQn,       // TIM8 Break interrupt
  TIM8_UP_IRQn,        // TIM8 Update interrupt
  TIM8_TRG_COM_IRQn,   // TIM8 Trigger and Commutation interrupts
  TIM8_CC_IRQn,        // TIM8 Capture Compare interrupt
  ADC3_IRQn,           // ADC3 global interrupt
  FSMC_IRQn,           // FSMC global interrupt
  SDIO_IRQn,           // SDIO global interrupt
  TIM5_IRQn,           // TIM5 global interrupt
  SPI3_IRQn,           // SPI3 global interrupt
  UART4_IRQn,          // UART4 global interrupt
  UART5_IRQn,          // UART5 global interrupt
  TIM6_IRQn,           // TIM6 global interrupt
  TIM7_IRQn,           // TIM7 global interrupt
  DMA2_Channel1_IRQn,  // DMA2 Channel1 global interrupt
  DMA2_Channel2_IRQn,  // DMA2 Channel2 global interrupt
  DMA2_Channel3_IRQn,  // DMA2 Channel3 global interrupt
  DMA2_Channel4_5_IRQn, // DMA2 Channel4 and DMA2 Channel5 global interrupts

} IRQn_Type;


/* ========================================================================= */
/* ============      Processor and Core Peripheral Section      ============ */
/* ========================================================================= */

/* ================ Start of section using anonymous unions ================ */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* --------  Configuration of Core Peripherals  ----------------------------------- */

#define __CM3_REV               0x0201U  /* Core Revision r2p1 */

#define __Vendor_SysTickConfig  0U       /* Set to 1 if different SysTick Config is used */
#define __NVIC_PRIO_BITS        4U       /* Number of Bits used for Priority Levels */
#define __VTOR_PRESENT          1U       /* Set to 1 if VTOR is present */
#define __MPU_PRESENT           1U       /* Set to 1 if MPU is present */
#define __FPU_PRESENT           0U       /* Set to 1 if FPU is present */
#define __FPU_DP                0U       /* Set to 1 if FPU is double precision FPU (default is single precision FPU) */
#define __DSP_PRESENT           0U       /* Set to 1 if DSP extension are present */
#define __SAUREGION_PRESENT     0U       /* Set to 1 if SAU regions are present */
#define __PMU_PRESENT           0U       /* Set to 1 if PMU is present */
#define __PMU_NUM_EVENTCNT      0U       /* Set number of PMU Event Counters */
#define __ICACHE_PRESENT        0U       /* Set to 1 if I-Cache is present */
#define __DCACHE_PRESENT        0U       /* Set to 1 if D-Cache is present */
#define __DTCM_PRESENT          0U       /* Set to 1 if DTCM is present */


#include <core_cm3.h>                           /* Processor and core peripherals */
#include "system_stm32f103c8.h"                 /* System Header */

/* ========================================================================= */
/* ============       Device Specific Peripheral Section        ============ */
/* ========================================================================= */


/* ToDo: add here your device specific peripheral access structure typedefs
         including bit definitions for Pos/Msk macros
         following is an example for a timer */

/* ========================================================================= */
/* ============                       TMR                       ============ */
/* ========================================================================= */

// typedef struct
// {
//   __IOM uint32_t  LOAD;                 /* Offset: 0x000 (R/W) Load Register */
//   __IM  uint32_t  VALUE;                /* Offset: 0x004 (R/ ) Value Register */
//   __IOM uint32_t  CONTROL;              /* Offset: 0x008 (R/W) Control Register */
//   __OM  uint32_t  INTCLR;               /* Offset: 0x00C ( /W) Clear Interrupt Register */
//   __IM  uint32_t  RIS;                  /* Offset: 0x010 (R/ ) Raw Interrupt Status Register */
//   __IM  uint32_t  MIS;                  /* Offset: 0x014 (R/ ) Interrupt Status Register */
//   __IOM uint32_t  BGLOAD;               /* Offset: 0x018 (R/W) Background Load Register */
// } <DeviceAbbreviation>_TMR_TypeDef;

// /* <DeviceAbbreviation>_TMR LOAD Register Definitions */
// #define <DeviceAbbreviation>_TMR_LOAD_Pos              0
// #define <DeviceAbbreviation>_TMR_LOAD_Msk             (0xFFFFFFFFUL /*<< <DeviceAbbreviation>_TMR_LOAD_Pos*/)

// /* <DeviceAbbreviation>_TMR VALUE Register Definitions */
// #define <DeviceAbbreviation>_TMR_VALUE_Pos             0
// #define <DeviceAbbreviation>_TMR_VALUE_Msk            (0xFFFFFFFFUL /*<< <DeviceAbbreviation>_TMR_VALUE_Pos*/)

// /* <DeviceAbbreviation>_TMR CONTROL Register Definitions */
// #define <DeviceAbbreviation>_TMR_CONTROL_SIZE_Pos      1
// #define <DeviceAbbreviation>_TMR_CONTROL_SIZE_Msk     (1UL << <DeviceAbbreviation>_TMR_CONTROL_SIZE_Pos)

// #define <DeviceAbbreviation>_TMR_CONTROL_ONESHOT_Pos   0
// #define <DeviceAbbreviation>_TMR_CONTROL_ONESHOT_Msk  (1UL /*<< <DeviceAbbreviation>_TMR_CONTROL_ONESHOT_Pos*/)



/* --------  End of section using anonymous unions and disabling warnings  -------- */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* ========================================================================= */
/* ============     Device Specific Peripheral Address Map      ============ */
/* ========================================================================= */

#define FLASH_ROM_BASE            (0x08000000UL)
#define SRAM_BASE                 (0x20000000UL)
#define PERIPH_BASE               (0x40000000UL)                              /* (Peripheral) Base Address */

#define AHB_BASE                  (0x40018000UL)
#define APB1_BASE                 (PERIPH_BASE)
#define APB2_BASE                 (PERIPH_BASE + 0x10000)

#define FSMC_BASE                 (0xA0000000UL)
#define USBOTGFS_BASE             (0x50000000UL)

#define SDIO_BASE                 (AHB_BASE)
#define DMA1_BASE                 (AHB_BASE + 0x0800)
#define DMA2_BASE                 (AHB_BASE + 0x0C00)
#define RCC_BASE                  (AHB_BASE + 0x9000)
#define FLASH_BASE                (AHB_BASE + 0xA000)
#define CRC_BASE                  (AHB_BASE + 0xB000)
#define FLASH_BASE                (AHB_BASE + 0xA000)

#define TIM11_BASE                (APB2_BASE + 0x5400)
#define TIM10_BASE                (APB2_BASE + 0x5400)
#define TIM9_BASE                 (APB2_BASE + 0x4C00)
#define ADC3_BASE                 (APB2_BASE + 0x3C00)
#define USART1_BASE               (APB2_BASE + 0x3800)
#define TIM8_BASE                 (APB2_BASE + 0x3400)
#define SPI1_BASE                 (APB2_BASE + 0x3000)
#define TIM1_BASE                 (APB2_BASE + 0x2C00)
#define ADC2_BASE                 (APB2_BASE + 0x2800)
#define ADC1_BASE                 (APB2_BASE + 0x2400)
#define GPIOG_BASE                (APB2_BASE + 0x2000)
#define GPIOF_BASE                (APB2_BASE + 0x1C00)
#define GPIOE_BASE                (APB2_BASE + 0x1800)
#define GPIOD_BASE                (APB2_BASE + 0x1400)
#define GPIOC_BASE                (APB2_BASE + 0x1000)
#define GPIOB_BASE                (APB2_BASE + 0x0c00)
#define GPIOA_BASE                (APB2_BASE + 0x0800)
#define EXTI_BASE                 (APB2_BASE + 0x0400)
#define AFIO_BASE                 (APB2_BASE)

#define DAC_BASE                  (APB1_BASE + 0x7400)
#define PWR_BASE                  (APB1_BASE + 0x7000)
#define BKP_BASE                  (APB1_BASE + 0x6C00)
#define CAN1_BASE                 (APB1_BASE + 0x6400)
#define CAN2_BASE                 (APB1_BASE + 0x6800)
#define USB_CAN_SRAM_BASE         (APB1_BASE + 0x6000)
#define USBFS_BASE                (APB1_BASE + 0x5C00)
#define I2C2_BASE                 (APB1_BASE + 0x5800)
#define I2C1_BASE                 (APB1_BASE + 0x5400)
#define UART5_BASE                (APB1_BASE + 0x4000)
#define UART4_BASE                (APB1_BASE + 0x4C00)
#define USART3_BASE               (APB1_BASE + 0x4800)
#define USART2_BASE               (APB1_BASE + 0x4400)
#define SPI3_BASE                 (APB1_BASE + 0x3C00)
#define SPI2_BASE                 (APB1_BASE + 0x3800)
#define IWDG_BASE                 (APB1_BASE + 0x3000)
#define WWDG_BASE                 (APB1_BASE + 0x2C00)
#define RTC_BASE                  (APB1_BASE + 0x2800)
#define TIM14_BASE                (APB1_BASE + 0x2000)
#define TIM13_BASE                (APB1_BASE + 0x1C00)
#define TIM12_BASE                (APB1_BASE + 0x1800)
#define TIM7_BASE                 (APB1_BASE + 0x1400)
#define TIM6_BASE                 (APB1_BASE + 0x1000)
#define TIM5_BASE                 (APB1_BASE + 0x0C00)
#define TIM4_BASE                 (APB1_BASE + 0x0800)
#define TIM3_BASE                 (APB1_BASE + 0x0400)
#define TIM2_BASE                 (APB1_BASE)

/* ========================================================================= */
/* ============             Peripheral declaration              ============ */
/* ========================================================================= */


/* ToDo: Add here your device peripherals pointer definitions
         following is an example for timer */

// #define <DeviceAbbreviation>_TIM0        ((<DeviceAbbreviation>_TMR_TypeDef *) <DeviceAbbreviation>TIM0_BASE)
// #define <DeviceAbbreviation>_TIM1        ((<DeviceAbbreviation>_TMR_TypeDef *) <DeviceAbbreviation>TIM0_BASE)
// #define <DeviceAbbreviation>_TIM2        ((<DeviceAbbreviation>_TMR_TypeDef *) <DeviceAbbreviation>TIM0_BASE)

#ifdef __cplusplus
}
#endif

#endif  /* STM32F103C8_H */
