# Desafio Super Trunfo - Países

## Descrição

Bem-vindo ao desafio "Super Trunfo - Países"! Este jogo permite que os jogadores comparem propriedades de cartas representando cidades de diferentes estados. Cada carta contém informações sobre a população, área, PIB, número de pontos turísticos e densidade demográfica das cidades.

## Estrutura do Código

O código é estruturado em funções que permitem a entrada e saída de dados, comparação de cartas e exibição de um menu para o usuário escolher o atributo a ser comparado.

### Estrutura da Cidade

A estrutura `Cidade` contém as seguintes propriedades:

- `estado`: Letra que representa o estado (A-H).
- `cidade`: Nome da cidade.
- `numero_da_cidade`: Número da cidade (1-4).
- `pop`: População em milhares de habitantes.
- `area`: Área em km².
- `pib`: PIB em bilhões de reais.
- `pontos_turisticos`: Número de pontos turísticos.
- `densidade_demografica`: Densidade demográfica calculada.

## Funcionalidades

1. **Cadastro de Cartas**: O usuário pode cadastrar duas cartas, inserindo os dados interativamente.
2. **Cálculo de Densidade Demográfica**: A densidade demográfica é calculada automaticamente com base na população e área.
3. **Comparação de Cartas**: O usuário pode comparar as cartas com base em diferentes atributos:
   - População
   - Área
   - PIB
   - Número de Pontos Turísticos
   - Densidade Demográfica

## Instruções de Compilação e Execução

Para compilar e executar o programa, siga os passos abaixo:

1. **Compilação**: Utilize um compilador C, como `gcc`. Execute o seguinte comando no terminal:
   ```bash
   gcc -o super_trunfo super_trunfo.c