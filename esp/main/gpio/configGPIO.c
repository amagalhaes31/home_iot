/*
 * configGPIO.c
 *
 *  Created on: 13 de abr. de 2021
 *      Author: Alexandre Magalhães
 */

#include "configGPIO.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_ON 		GPIO_NUM_2
#define DHT_STATUS 	GPIO_NUM_15
#define LAMP 		GPIO_NUM_18
#define SWITCH_0	GPIO_NUM_32
#define SWITCH_1	GPIO_NUM_33

#define GPIO_OUTPUT_PIN_SEL ((1ULL<<LED_ON)|(1ULL<<DHT_STATUS)|(1ULL<<LAMP))
#define GPIO_INPUT_PIN_SEL  ((1ULL<<SWITCH_0) | (1ULL<<SWITCH_1))


void inicializaGPIO(void) {

	// Configura o pinos de saída
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    gpio_config(&io_conf);

    // Configura os pinos de entrada
    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_config(&io_conf);

    xTaskCreate(leds, "leds", (1024 * 5), NULL, 1, NULL);

}

void leds (void *pvParameter) {

}
