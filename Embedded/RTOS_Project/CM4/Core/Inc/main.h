/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "keypad.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ULPI_D7_Pin GPIO_PIN_5
#define ULPI_D7_GPIO_Port GPIOB
#define SDIO1_D2_Pin GPIO_PIN_10
#define SDIO1_D2_GPIO_Port GPIOC
#define HDMI_CEC_Pin GPIO_PIN_6
#define HDMI_CEC_GPIO_Port GPIOB
#define ETH_TX_EN_Pin GPIO_PIN_11
#define ETH_TX_EN_GPIO_Port GPIOG
#define SDIO1_D3_Pin GPIO_PIN_11
#define SDIO1_D3_GPIO_Port GPIOC
#define OSC32_OUT_Pin GPIO_PIN_15
#define OSC32_OUT_GPIO_Port GPIOC
#define OSC32_IN_Pin GPIO_PIN_14
#define OSC32_IN_GPIO_Port GPIOC
#define ETH_TXD1_Pin GPIO_PIN_12
#define ETH_TXD1_GPIO_Port GPIOG
#define SPDIF_RX0_Pin GPIO_PIN_7
#define SPDIF_RX0_GPIO_Port GPIOD
#define SDIO1_CK_Pin GPIO_PIN_12
#define SDIO1_CK_GPIO_Port GPIOC
#define SAI1_SCK_A_Pin GPIO_PIN_5
#define SAI1_SCK_A_GPIO_Port GPIOE
#define SAI1_FS_A_Pin GPIO_PIN_4
#define SAI1_FS_A_GPIO_Port GPIOE
#define SAI1_SD_B_Pin GPIO_PIN_3
#define SAI1_SD_B_GPIO_Port GPIOE
#define ETH_TXD0_Pin GPIO_PIN_13
#define ETH_TXD0_GPIO_Port GPIOG
#define SDIO1_CMD_Pin GPIO_PIN_2
#define SDIO1_CMD_GPIO_Port GPIOD
#define B2_Pin GPIO_PIN_13
#define B2_GPIO_Port GPIOC
#define SAI1_SD_A_Pin GPIO_PIN_6
#define SAI1_SD_A_GPIO_Port GPIOE
#define SDIO1_D0_Pin GPIO_PIN_8
#define SDIO1_D0_GPIO_Port GPIOC
#define SDIO1_D1_Pin GPIO_PIN_9
#define SDIO1_D1_GPIO_Port GPIOC
#define CEC_CK_MCO1_Pin GPIO_PIN_8
#define CEC_CK_MCO1_GPIO_Port GPIOA
#define SPI2_SCK_Pin GPIO_PIN_12
#define SPI2_SCK_GPIO_Port GPIOA
#define PMOD_1_Pin GPIO_PIN_11
#define PMOD_1_GPIO_Port GPIOA
#define ULPI_DIR_Pin GPIO_PIN_11
#define ULPI_DIR_GPIO_Port GPIOI
#define SAI1_MCLK_A_Pin GPIO_PIN_7
#define SAI1_MCLK_A_GPIO_Port GPIOG
#define OSC_OUT_Pin GPIO_PIN_1
#define OSC_OUT_GPIO_Port GPIOH
#define OSC_IN_Pin GPIO_PIN_0
#define OSC_IN_GPIO_Port GPIOH
#define ARD_D13_Pin GPIO_PIN_0
#define ARD_D13_GPIO_Port GPIOK
#define ARD_D10_Pin GPIO_PIN_1
#define ARD_D10_GPIO_Port GPIOK
#define PMOD_14_ARD_D3_Pin GPIO_PIN_8
#define PMOD_14_ARD_D3_GPIO_Port GPIOF
#define ARD_D12_Pin GPIO_PIN_11
#define ARD_D12_GPIO_Port GPIOJ
#define ULPI_STP_Pin GPIO_PIN_0
#define ULPI_STP_GPIO_Port GPIOC
#define ARD_D11_Pin GPIO_PIN_10
#define ARD_D11_GPIO_Port GPIOJ
#define ETH_MDC_SAI4_D1_Pin GPIO_PIN_1
#define ETH_MDC_SAI4_D1_GPIO_Port GPIOC
#define PMOD_3_Pin GPIO_PIN_2
#define PMOD_3_GPIO_Port GPIOC
#define PMOD_2_Pin GPIO_PIN_3
#define PMOD_2_GPIO_Port GPIOC
#define ARD_D0_Pin GPIO_PIN_9
#define ARD_D0_GPIO_Port GPIOJ
#define ETH_MDIO_Pin GPIO_PIN_2
#define ETH_MDIO_GPIO_Port GPIOA
#define ETH_REF_CLK_Pin GPIO_PIN_1
#define ETH_REF_CLK_GPIO_Port GPIOA
#define KEYPAD_COLUMN1_D7_Pin GPIO_PIN_0
#define KEYPAD_COLUMN1_D7_GPIO_Port GPIOJ
#define ARD_D1_Pin GPIO_PIN_8
#define ARD_D1_GPIO_Port GPIOJ
#define KEYPAD_ROW4_D6_Pin GPIO_PIN_7
#define KEYPAD_ROW4_D6_GPIO_Port GPIOJ
#define KEYPAD_COLUMN3_D9_Pin GPIO_PIN_6
#define KEYPAD_COLUMN3_D9_GPIO_Port GPIOJ
#define ULPI_NXT_Pin GPIO_PIN_4
#define ULPI_NXT_GPIO_Port GPIOH
#define ULPI_D3_Pin GPIO_PIN_10
#define ULPI_D3_GPIO_Port GPIOB
#define ULPI_D4_Pin GPIO_PIN_11
#define ULPI_D4_GPIO_Port GPIOB
#define KEYPAD_ROW3_D5_Pin GPIO_PIN_6
#define KEYPAD_ROW3_D5_GPIO_Port GPIOA
#define ETH_CRS_DV_Pin GPIO_PIN_7
#define ETH_CRS_DV_GPIO_Port GPIOA
#define KEYPAD_COLUMN2_D8_Pin GPIO_PIN_5
#define KEYPAD_COLUMN2_D8_GPIO_Port GPIOJ
#define ARD_A2_Pin GPIO_PIN_0
#define ARD_A2_GPIO_Port GPIOA
#define ARD_A3_Pin GPIO_PIN_1
#define ARD_A3_GPIO_Port GPIOA
#define ULPI_CK_Pin GPIO_PIN_5
#define ULPI_CK_GPIO_Port GPIOA
#define ETH_RXD0_Pin GPIO_PIN_4
#define ETH_RXD0_GPIO_Port GPIOC
#define ULPI_D2_Pin GPIO_PIN_1
#define ULPI_D2_GPIO_Port GPIOB
#define ULPI_D5_Pin GPIO_PIN_12
#define ULPI_D5_GPIO_Port GPIOB
#define ULPI_D0_Pin GPIO_PIN_3
#define ULPI_D0_GPIO_Port GPIOA
#define ETH_RXD1_Pin GPIO_PIN_5
#define ETH_RXD1_GPIO_Port GPIOC
#define ULPI_D1_Pin GPIO_PIN_0
#define ULPI_D1_GPIO_Port GPIOB
#define KEYPAD_ROW1_D2_Pin GPIO_PIN_3
#define KEYPAD_ROW1_D2_GPIO_Port GPIOJ
#define KEYPAD_ROW2_D4_Pin GPIO_PIN_4
#define KEYPAD_ROW2_D4_GPIO_Port GPIOJ
#define ULPI_D6_Pin GPIO_PIN_13
#define ULPI_D6_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
