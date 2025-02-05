// Bibliotecas necessárias para o projeto
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h" 

// Definição dos pinos dos leds e do botão
#define LED_G_PIN 11
#define LED_B_PIN 12
#define LED_R_PIN 13

#define BUTTON_PIN 5

int contador = 0; // Contador

// Função para inicializar os LEDs e botões
void inicializacaocomponentes() {
    gpio_init(LED_G_PIN);
    gpio_set_dir(LED_G_PIN, GPIO_OUT);
    gpio_put(LED_G_PIN, 0);

    gpio_init(LED_B_PIN);
    gpio_set_dir(LED_B_PIN, GPIO_OUT);
    gpio_put(LED_B_PIN, 0);

    gpio_init(LED_R_PIN);
    gpio_set_dir(LED_R_PIN, GPIO_OUT);
    gpio_put(LED_R_PIN, 0);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN); // Habilita o resistor pull-up interno para o pino do botão.
}

// Função de callback com a rotina dos LEDs
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
       if (contador == 0) { 
        gpio_put(LED_G_PIN, 0);
        gpio_put(LED_B_PIN, 1);
        gpio_put(LED_R_PIN, 1);

        contador = 1;
    } else {
        gpio_put(LED_G_PIN, 0);
        gpio_put(LED_B_PIN, 0);
        gpio_put(LED_R_PIN, 1);

        contador = 0;
    }
    return 0;
}

int main() {
    stdio_init_all();
    inicializacaocomponentes(); // Inicializa os LEDs e o botão

    // Rotina principal
    while (true) {

        // Verifica se o botão foi pressionado (nível baixo no pino) e se o LED não está ativo.
        if (gpio_get(BUTTON_PIN) == 0 && contador == 0) {

            sleep_ms(200); // Atraso para debounce, evitando leituras errôneas.

            if (gpio_get(BUTTON_PIN) == 0){
                //Liga os LEDs
                gpio_put(LED_G_PIN, 1);
                gpio_put(LED_B_PIN, 1);
                gpio_put(LED_R_PIN, 1);

                contador = 0;
                
                // A função 'turn_off_callback' será chamada após esse tempo.
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
        }
        // Introduz uma pequena pausa de 10 ms para reduzir o uso da CPU.
        sleep_ms(10);
    }
    return 0;  // Retorna 0, embora o loop seja infinito
}