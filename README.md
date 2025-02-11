# Atividade 02 - Temporizador de um disparo (One Shot)

Este repositório foi desenvolvido para fins educativos na U4 do EmbarcaTech, com base na aula do dia 29/02 com tema clock e temporizadores - apresenta um sistema de controle de LEDs utilizando o microcontrolador Raspberry Pi Pico W e outros componentes do kit de desenvolvimento BitDogLab. O projeto explora a função add_alarm_in_ms() do Pico SDK e com funções de callback do temporizador. O sistema é acionado quando o usuário pressiona o botão e, seguindo o tempo programado, os LEDs seguirão um padrão de desligamento.

# Componentes utilizados 

- Raspberry Pi pico W(ou extensão Wokwi para simular os componentes)
- 3 LEDs RGB
- 3 resistores de 330 Ohms
- Botão (Push Button)
- Kit de Desenvolvimento BitDogLab
- VS Code
- Wokwi

# Linguagem Utilizada

*C*

# Como utilizar?

1) Configuração da Ambiente de Desenvolvimento:

- Instale um compilador para C/C++ (Ex.: GCC)
- Instale as extensões: C/C++, Raspberry Pi Pico e Wokwi na sua IDE(Ex.: VS Code).

2) Utilização deste projeto:

- Com o ambiente configurado, você pode baixar este repositório no GitHub ou clonar o link na sua IDE(VsCode) utilizando o Git/Github Desktop.
**Confira se o git foi instalado antes de prosseguir**
  
Ex.: Você irá abrir sua IDE e inserir no terminal:
 ```sh
   git clone https://github.com/Camila-RG/Atividade2_Temporizador_de_um_disparo.git
```

- Abra a pasta Atividade2_Temporizador_de_um_disparo na sua IDE
- Compile o código pelo aba da Raspberry Pi e envie o código para sua placa
- Se não possuir o Raspberry Pi Pico W ou o kit BitDogLab, você pode utilizar a simulação do Wokwi para testar o funcionamento do programa.


# Funcionamento 

Aqui está a parte principal do projeto, que tem como objetivo a utilização de temporizadores e clock para o funcionamento do sistema: 
- Aguarda o usuário apertar o botão;
- Assim que o botão é pressionado todos os 3 LEDs se acendem;
- A cada 3 segundos (3.000ms), um LED será desligado até que todos estejam apagados.

# Testes

- O funcionamento do programa foi realizado por meio de simulações pelo software Wokwi
- Foi verificado se o temporizador estava funcionando corretamente
- Funções call back e add_alarme_in_ms() implementadas e funcionando

# Autor

Camila Ramos Gomes
