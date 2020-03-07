//
// rgb.c
// Created by Andreas Gerono on 07/03/2020.

#include "rgb.h"
#include "tim.h"
#include "math.h"
#define BRIGHTNESS_MAX 99
#define PWM_MAX 10000

static uint16_t colors[][3] = {
		{100, 100, 100},
		{100, 0, 0},
		{0, 100, 0},
		{0, 0, 100}
};




static uint16_t *currentColor;
static uint8_t currentBrightness;




static void set_pwm(){
	double tmp_brightness = (currentBrightness+1);
	TIM2->CCR1 = PWM_MAX - (uint16_t) (tmp_brightness* currentColor[0]);
	TIM2->CCR2 = PWM_MAX - (uint16_t) (tmp_brightness* currentColor[1]);
	TIM2->CCR3 = PWM_MAX - (uint16_t) (tmp_brightness* currentColor[2]);
}

void rgb_setColor(Color color){
	currentColor = colors[color];
	set_pwm();
}


void rgb_setBrightness(uint8_t brightness){
	currentBrightness = brightness;
	set_pwm();
}

void rgb_on(){
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_3);
}

void rgb_off(){
 	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_2);
	HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_3);
}



void rgb_init(){
	currentColor = colors[white];
	currentBrightness = 0;
}
