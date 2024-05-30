#include "stm32f10x.h"                  // Device header
#include "GPIO.h"
void Sg90_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
//	GPIO_InitTypeDef GPIO_INITSTRUCT;
//	GPIO_INITSTRUCT.GPIO_Mode=GPIO_Mode_AF_PP;
//	GPIO_INITSTRUCT.GPIO_Pin=GPIO_Pin_0;
//	GPIO_INITSTRUCT.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_Init(GPIOA,&GPIO_INITSTRUCT);
	Try_Gpio_Init(RCC_A,GPIO_Mode_AF_PP,PIN0,GPIO_Speed_50MHz);
	
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_TIMERINITSTRUCT;
	TIM_TIMERINITSTRUCT.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TIMERINITSTRUCT.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TIMERINITSTRUCT.TIM_Period=200-1;//ARR自动重装
	TIM_TIMERINITSTRUCT.TIM_Prescaler=7200-1;//PSC预分频器
	TIM_TIMERINITSTRUCT.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2,&TIM_TIMERINITSTRUCT);
	
	TIM_OCInitTypeDef TIM2_INITSTRUCT;
	TIM_OCStructInit(&TIM2_INITSTRUCT);
	TIM2_INITSTRUCT.TIM_OCMode=TIM_OCMode_PWM1;
	TIM2_INITSTRUCT.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM2_INITSTRUCT.TIM_OutputState=ENABLE;
	TIM2_INITSTRUCT.TIM_Pulse=0;
	TIM_OC1Init(TIM2,&TIM2_INITSTRUCT);
	
	TIM_Cmd(TIM2,ENABLE);
}
void angle_set(uint16_t x)
{
	TIM_SetCompare1(TIM2,x);
}
//#include "stm32f10x.h"
//#include "Delay.h"
//#include "Sg90.h"
//int main(void)
//{
//	Sg90_init();
//	while(1)
//	{
//		TIM_SetCompare1(TIM2,195);
//		Delay_ms(500);
//		TIM_SetCompare1(TIM2,190);
//		Delay_ms(500);
//		TIM_SetCompare1(TIM2,185);
//		Delay_ms(500);
//		TIM_SetCompare1(TIM2,180);
//		Delay_ms(500);
//		TIM_SetCompare1(TIM2,175);
//		Delay_ms(500);
//	}
//}

