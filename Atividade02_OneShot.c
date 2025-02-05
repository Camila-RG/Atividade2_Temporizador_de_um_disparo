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

int64_t turn_off_callback(alarm_id_t id, void *user_data) {
         if (contador == 0) {
        gpio_put(LED_G_PIN, 1);
        gpio_put(LED_B_PIN, 1);
        gpio_put(LED_R_PIN, 1);

        contador = 1;
    } else if (contador == 1) { 
        gpio_put(LED_G_PIN, 0);
        gpio_put(LED_B_PIN, 1);
        gpio_put(LED_R_PIN, 1);

        contador = 2;
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
        // Agenda um alarme para desligar o LED após 3 segundos (3000 ms).
        add_alarm_in_ms(3000, turn_off_callback, NULL, false);
        // Introduz uma pequena pausa de 10 ms para reduzir o uso da CPU.
        sleep_ms(10);
    }
    return 0;  // Retorna 0, embora o loop seja infinito
}