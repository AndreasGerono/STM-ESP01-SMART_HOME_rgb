//
// rgb.h
// Created by Andreas Gerono on 07/03/2020.

#ifndef _rgb_h_
#define _rgb_h_

#include "stm32f1xx.h"


typedef enum Color{
	white,
	red,
	green,
	blue
} Color;


void rgb_setColor(Color);
void rgb_setBrightness(uint8_t brightness);
void rgb_init();
void rgb_on();
void rgb_off();


#endif
