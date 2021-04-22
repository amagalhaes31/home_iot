/*
 -- TCC - Trabalho de Conclus�o de Curso
 -- P�s Gradua��o em Cloud Coumputing e Desenvolvimento Mobile
 --
 -- Este firmware tem como objetivo de ler/escrever no AWS (Amazon Web Services) informa��es dos sensores
 -- em uma resid�ncia
 --
 -- Autor: Alexandre Magalh�es
 -- Data: 11/04/2021
 -- IDE: Eclipse IDF 4.0.2
*/

// Bibliotecas
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "gpio/configGPIO.h"


// Fun��o principal
void app_main(void)
{
    /* Inicializa��o da mem�ria n�o vol�til para armazenamento de dados (NVS -> Non-Volatile Storage). */
	esp_err_t ret = nvs_flash_init();
	if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
		ESP_ERROR_CHECK(nvs_flash_erase());
		ret = nvs_flash_init();
	}
	ESP_ERROR_CHECK(ret);

	// Inicializa os pinos de entradas e sa�das do m�dulo
	inicializaGPIO();
}

