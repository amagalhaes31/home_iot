/*
 * configGPIO.c
 *
 *  Created on: 13 de abr. de 2021
 *      Author: Alexandre Magalhães
 */

// Bibliotecas
#include <stdbool.h>
#include "configGPIO.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

// Definições do hardware
#define LED_ETH 	GPIO_NUM_2
#define LED_DHT 	GPIO_NUM_15
#define LED_SENSOR	GPIO_NUM_16
#define LAMP_0 		GPIO_NUM_17
#define LAMP_1 		GPIO_NUM_18
#define LAMP_2 		GPIO_NUM_19

#define SWITCH_0	GPIO_NUM_34
#define SWITCH_1	GPIO_NUM_36
#define SWITCH_2	GPIO_NUM_39
#define SENSOR_DHT	GPIO_NUM_32
#define SENSOR_0	GPIO_NUM_26
#define SENSOR_1	GPIO_NUM_27

#define GPIO_OUTPUT_PIN_SEL ((1ULL<<LED_ETH)|(1ULL<<LED_DHT)|(1ULL<<LAMP_0)|(1ULL<<LAMP_1)|(1ULL<<LAMP_2))
#define GPIO_INPUT_PIN_SEL  ((1ULL<<SWITCH_0)|(1ULL<<SWITCH_1)|(1ULL<<SWITCH_2)|(1ULL<<SENSOR_0)|(1ULL<<SENSOR_1))

// Variáveis Globais
GPIO_STATUS gpioStatus;


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

    // Cria a task para leitura dos leds
    xTaskCreate(leds, "leds", (1024 * 5), NULL, 1, NULL);

}

void leds (void *pvParameter) {

	while(true) {

		/**** Seta os pinos de saídas ****/
		//
		gpio_set_level(LED_ETH, getLedEthernet());
		gpio_set_level(LED_DHT, getDhtStatus());

		// Seta as lampadas
		int8_t statusLamp = getLampStatus();
		gpio_set_level(LAMP_0, (statusLamp&0x01)>>0);
		gpio_set_level(LAMP_1, (statusLamp&0x02)>>1);
		gpio_set_level(LAMP_2, (statusLamp&0x04)>>2);

		// Atraso da task
		vTaskDelay(500 / portTICK_PERIOD_MS);
	}
}

bool getLedEthernet(void) {

	return gpioStatus.ledOn;
}

bool getDhtStatus(void) {

	return gpioStatus.dhtStatus;
}

uint8_t getLampStatus(void) {

	return gpioStatus.lamp;
}
