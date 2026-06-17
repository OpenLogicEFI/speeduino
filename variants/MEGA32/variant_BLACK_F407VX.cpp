/*
 *******************************************************************************
 * Copyright (c) 2017-2021, STMicroelectronics
 * All rights reserved.
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 *******************************************************************************
 */
#if defined(ARDUINO_BLACK_F407VE) || defined(ARDUINO_BLACK_F407VG)

//#include "Arduino.h"
#include "pins_arduino.h"
#include "variant_BLACK_F407VX.h"

// Prevent PA15 from glitching during startup
extern "C" void initVariant(void)
{
  // Enable GPIOA clock
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
  __DSB(); // make sure the clock write lands before we touch GPIO

  // Force PA15 output data LOW *before* switching to output mode
  GPIOA->BSRR = (1U << (15U + 16U));   // BR15 = reset bit -> drives low once in output mode

  // Configure PA15 as a normal GPIO output, push-pull, low speed
  GPIOA->MODER   = (GPIOA->MODER   & ~(3U << (15U * 2U))) | (1U << (15U * 2U)); // 01 = output
  GPIOA->OTYPER &= ~(1U << 15U);                                               // 0 = push-pull
  GPIOA->OSPEEDR = (GPIOA->OSPEEDR & ~(3U << (15U * 2U)));                      // 00 = low speed
  GPIOA->PUPDR   = (GPIOA->PUPDR   & ~(3U << (15U * 2U)));                      // no pull (optional)
}

// Digital PinName array
// This array allows to wrap Arduino pin number(Dx or x)
// to STM32 PinName (PX_n)
const PinName digitalPin[] = {
  // D0..D13
  PA_10,  // D0  RX1
  PA_9,   // D1  TX1
  PD_4,   // D2
  PD_3,   // D3
  PC_9,   // D4
  PC_8,   // D5
  PC_7,   // D6
  PC_6,   // D7
  PD_15,  // D8
  PD_14,  // D9
  PD_13,  // D10
  PD_12,  // D11
  PA_8,   // D12
  PA_13,  // D13

  // D14..D21
  PD_5,   // D14 TX3
  PD_6,   // D15 RX3
  PB_10,  // D16 TX2
  PB_11,  // D17 RX2
  PD_11,  // D18 TX1
  PD_10,  // D19 RX1
  PD_9,   // D20 SDA
  PD_8,   // D21 SCL

  // D22..D53
  PB_15,  // D22
  PB_14,  // D23
  PB_13,  // D24
  PB_10,  // D25 (parallel)
  PB_12,  // D26
  PE_15,  // D27 (parallel)
  PB_7,   // D28
  PE_14,  // D29
  PE_13,  // D30
  PB_11,  // D31 (parallel)
  PB_8,   // D32
  PB_9,   // D33
  PE_0,   // D34
  PE_2,   // D35
  PE_3,   // D36
  PE_4,   // D37
  PE_12,  // D38
  PE_4,   // D39 (parallel)
  PA_15,  // D40
  PE_5,   // D41
  PE_4,   // D42 (parallel)
  PE_5,   // D43 (parallel)
  PE_6,   // D44
  PD_7,   // D45
  PE_6,   // D46 (parallel)
  PB_6,   // D47
  PE_10,  // D48
  PE_11,  // D49
  PE_9,   // D50
  PC_13,  // D51
  PE_7,   // D52
  PE_8,   // D53

  // A0..A15 as digital 54..69
  PA_0,   // D54 A0
  PA_1,   // D55 A1
  PA_2,   // D56 A2
  PA_3,   // D57 A3
  PA_4,   // D58 A4
  PA_5,   // D59 A5
  PA_6,   // D60 A6
  PA_7,   // D61 A7
  PB_0,   // D62 A8
  PB_1,   // D63 A9
  PC_0,   // D64 A10
  PC_1,   // D65 A11
  PC_2,   // D66 A12
  PC_3,   // D67 A13
  PC_4,   // D68 A14
  PC_5,   // D69 A15

  // Extras
  PA_11,  // D70 USB_DP
  PA_12,  // D71 USB_DM
  PE_1,   // D72 SPI-Flash CS
  PB_4,   // D73 SPI1 MOSI
  PB_5,   // D74 SPI1 MISO
  PB_3,   // D75 SPI1 CLK
  PD_0,   // D76 CAN RX
  PD_1,   // D77 CAN TX
  PD_2,   // D78 SD CS
  PC_10,  // D79 SPI3 SCK
  PC_11,  // D80 SPI3 MISO
  PC_12,  // D81 SPI3 MOSI
  PA_14,  // D82
  PB_2,   // D83
  PC_14,  // D84
  PC_15,  // D85
};

// Analog (Ax) pin number array
const uint32_t analogInputPin[] = {
  54, // A0
  55, // A1
  56, // A2
  57, // A3
  58, // A4
  59, // A5
  60, // A6
  61, // A7
  62, // A8
  63, // A9
  64, // A10
  65, // A11
  66, // A12
  67, // A13
  68, // A14
  69  // A15

};

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief  System Clock Configuration
  * @param  None
  * @retval None
  */
WEAK void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct = {};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {};

  /**Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /**Initializes the CPU, AHB and APB busses clocks
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }

  /**Initializes the CPU, AHB and APB busses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
                                | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK) {
    Error_Handler();
  }

  /* Ensure CCM RAM clock is enabled */
  __HAL_RCC_CCMDATARAMEN_CLK_ENABLE();

}

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_BLACK_F407VE || ARDUINO_BLACK_F407VG */
