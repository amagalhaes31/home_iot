/*
 -- TCC - Trabalho de Conclusão de Curso
 -- Pós Graduação em Cloud Coumputing e Desenvolvimento Mobile
 --
 -- Este firmware tem como objetivo de ler/escrever no AWS (Amazon Web Services) informações dos sensores
 -- em uma residência
 --
 -- Autor: Alexandre Magalhães
 -- Data: 11/04/2021
 -- IDE: Eclipse IDF 4.0.2
*/

// Bibliotecas
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "gpio/configGPIO.h"


// Função principal
void app_main(void)
{
    /* Inicialização da memória não volátil para armazenamento de dados (NVS -> Non-Volatile Storage). */
	esp_err_t ret = nvs_flash_init();
	if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);

	inicializaGPIO();
}

