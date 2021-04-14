/*
 * configGPIO.h
 *
 *  Created on: 13 de abr. de 2021
 *      Author: Alexandre Magalhães
 */

#ifndef MAIN_GPIO_CONFIGGPIO_H_
#define MAIN_GPIO_CONFIGGPIO_H_

typedef struct {
	bool ledOn: 1;
	bool dhtStatus: 1;
	bool lamp: 1;
	bool switch_0: 1;
	bool switch_1: 1;
}GPIO_STATUS;

void inicializaGPIO(void);
void leds (void *pvParameter);
bool getLedOn(void);
bool getDhtStatus(void);
bool getLampStatus(void);

#endif /* MAIN_GPIO_CONFIGGPIO_H_ */
