#include "stm32f10x.h"                  // Device header
#include "GPIO.h"
void Try_Gpio_Init(uint32_t rcc,GPIOMode_TypeDef MODE,uint16_t PIN,GPIOSpeed_TypeDef SPEED)
{
	RCC_APB2PeriphClockCmd(rcc,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode= MODE;
	GPIO_InitStruct.GPIO_Pin= PIN;
	GPIO_InitStruct.GPIO_Speed= SPEED;
	
	switch(rcc)
	{
		case RCC_A:GPIO_Init(GPIOA,&GPIO_InitStruct);break;
		case RCC_B:GPIO_Init(GPIOB,&GPIO_InitStruct);break;
		case RCC_C:GPIO_Init(GPIOC,&GPIO_InitStruct);break;
		case RCC_D:GPIO_Init(GPIOD,&GPIO_InitStruct);break;
		default:GPIO_Init(GPIOG,&GPIO_InitStruct);break;
	}
}
