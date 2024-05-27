#ifndef __GPIO_H__
#define __GPIO_H__
#include "stm32f10x.h"                  // Device header
//使能
#define RCC_A                 RCC_APB2Periph_GPIOA            
#define RCC_B             	  RCC_APB2Periph_GPIOB
#define RCC_C                 RCC_APB2Periph_GPIOC
#define RCC_D                 RCC_APB2Periph_GPIOD
//gpio_pin初始化
#define PIN0                 ((uint16_t)0x0001)  /*!< Pin 0 selected */
#define PIN1                 ((uint16_t)0x0002)  /*!< Pin 1 selected */
#define PIN2                 ((uint16_t)0x0004)  /*!< Pin 2 selected */
#define PIN3                 ((uint16_t)0x0008)  /*!< Pin 3 selected */
#define PIN4                 ((uint16_t)0x0010)  /*!< Pin 4 selected */
#define PIN5                 ((uint16_t)0x0020)  /*!< Pin 5 selected */
#define PIN6                 ((uint16_t)0x0040)  /*!< Pin 6 selected */
#define PIN7                 ((uint16_t)0x0080)  /*!< Pin 7 selected */
#define PIN8                 ((uint16_t)0x0100)  /*!< Pin 8 selected */
#define PIN9                 ((uint16_t)0x0200)  /*!< Pin 9 selected */
#define PIN10                ((uint16_t)0x0400)  /*!< Pin 10 selected */
#define PIN11                ((uint16_t)0x0800)  /*!< Pin 11 selected */
#define PIN12                ((uint16_t)0x1000)  /*!< Pin 12 selected */
#define PIN13                ((uint16_t)0x2000)  /*!< Pin 13 selected */
#define PIN14                ((uint16_t)0x4000)  /*!< Pin 14 selected */
#define PIN15                ((uint16_t)0x8000)  /*!< Pin 15 selected */
#define PIN00                ((uint16_t)0xFFFF)  /*!< All pins selected */


void Try_Gpio_Init(uint32_t rcc,GPIOMode_TypeDef MODE,uint16_t PIN,GPIOSpeed_TypeDef SPEED);
#endif

