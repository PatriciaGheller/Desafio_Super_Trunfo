#include <stdio.h>
#include <ctype.h> // Inclua esta biblioteca para usar toupper()

// Definição da estrutura Cidade
typedef struct {
    char estado;
    char cidade[30];
    int numero_da_cidade;
    int pop;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_demografica; // Adicionando a densidade demográfica
} Cidade;

// Função para entrada de dados
void entrada_dados(Cidade *c) {
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &c->estado);
    c->estado = toupper(c->estado); // Converte o estado para maiúscula
    printf("Digite o nome da Cidade: ");
    scanf(" %[^\n]", c->cidade); // Lê até a nova linha
    printf("Digite o código da carta: (1-4): ");
    scanf("%d", &c->numero_da_cidade);
    printf("Digite a População: ");
    scanf("%d", &c->pop); 
    printf("Digite a Área: km²: ");
    scanf("%f", &c->area);
    printf("Digite o PIB: ");
    scanf("%f", &c->pib);
    printf("Digite o Número de pontos turísticos: ");
    scanf("%d", &c->pontos_turisticos);
    
    // Calculando a densidade demográfica
    if (c->area > 0) {
        c->densidade_demografica = (float)c->pop / c->area; // Densidade demográfica
    } else {
        c->densidade_demografica = 0; // Evitar divisão por zero
    }
}

// Função para saída de dados
void saida_dados(Cidade c) {
    char codigo_carta[4];
    snprintf(codigo_carta, sizeof(codigo_carta), "%c%02d", c.estado, c.numero_da_cidade);
    printf("\nEstado: %c\n", c.estado); 
    printf("Código da carta: %s\n", codigo_carta); 
    printf("Nome da Cidade: %s\n", c.cidade);
    printf("População: %d mil habitantes\n", c.pop);
    printf("Área: %.2f km²\n", c.area); 
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Número de pontos turísticos: %d\n", c.pontos_turisticos); 
    printf("Densidade Demográfica: %.2f habitantes/km²\n", c.densidade_demografica);
    printf("CARTA CADASTRADA COM SUCESSO!\n");
}

// Função para comparar duas cartas
void comparar_cartas(Cidade c1, Cidade c2, int atributo) {
    printf("\nComparando cartas:\n");
    printf("País 1: %s\n", c1.cidade);
    printf("País 2: %s\n", c2.cidade);
    
    switch (atributo) {
        case 1: // População
            printf("Atributo: População\n");
            if (c1.pop > c2.pop) {
                printf("A carta 1 (Cidade: %s) vence com maior população: %d mil habitantes\n", c1.cidade, c1.pop);
            } else if (c1.pop < c2.pop) {
                printf("A carta 2 (Cidade: %s) vence com maior população: %d mil habitantes\n", c2.cidade, c2.pop);
            } else {
                printf("Empate na população!\n");
            }
            break;
        case 2: // Área
            printf("Atributo: Área\n");
            if (c1.area > c2.area) {
                printf("A carta 1 (Cidade: %s) vence com maior área: %.2f km²\n", c1.cidade, c1.area);
            } else if (c1.area < c2.area) {
                printf("A carta 2 (Cidade: %s) vence com maior área: %.2f km²\n", c2.cidade, c2.area);
            } else {
                printf("Empate na área!\n");
            }
            break;
        case 3: // PIB
            printf("Atributo: PIB\n");
            if (c1.pib > c2.pib) {
                printf("A carta 1 (Cidade: %s) vence com maior PIB: %.2f bilhões de reais\n", c1.cidade, c1.pib);
            } else if (c1.pib < c2.pib) {
                printf("A carta 2 (Cidade: %s) vence com maior PIB: %.2f bilhões de reais\n", c2.cidade, c2.pib);
            } else {
                printf("Empate no PIB!\n");
            }
            break;
        case 4: // Número de pontos turísticos
            printf("Atributo: Número de Pontos Turísticos\n");
            if (c1.pontos_turisticos > c2.pontos_turisticos) {
                printf("A carta 1 (Cidade: %s) vence com mais pontos turísticos: %d\n", c1.cidade, c1.pontos_turisticos);
            } else if (c1.pontos_turisticos < c2.pontos_turisticos) {
                printf("A carta 2 (Cidade: %s) vence com mais pontos turísticos: %d\n", c2.cidade, c2.pontos_turisticos);
            } else {
                printf("Empate no número de pontos turísticos!\n");
            }
            break;
        case 5: // Densidade demográfica
            printf("Atributo: Densidade Demográfica\n");
            if (c1.densidade_demografica < c2.densidade_demografica) {
                printf("A carta 1 (Cidade: %s) vence com menor densidade demográfica: %.2f habitantes/km²\n", c1.cidade, c1.densidade_demografica);
            } else if (c1.densidade_demografica > c2.densidade_demografica) {
                printf("A carta 2 (Cidade: %s) vence com menor densidade demográfica: %.2f habitantes/km²\n", c2.cidade, c2.densidade_demografica);
            } else {
                printf("Empate na densidade demográfica!\n");
            }
            break;
        default:
            printf("Opção inválida!\n");
            break;
    }
}

// Função para exibir o menu e obter a escolha do usuário
int exibir_menu() {
    int escolha;
    printf("\nEscolha o atributo para comparar as cartas:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Número de Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("Digite sua escolha (1-5): ");
    scanf("%d", &escolha);
    return escolha;
}

int main() {
    // Declaração de variáveis do tipo Cidade
    Cidade c1, c2;

    // Entrada nos dados da primeira carta
    printf("Cadastro da primeira carta:\n");
    entrada_dados(&c1);
    saida_dados(c1);

    // Entrada nos dados da segunda carta
    printf("\nCadastro da segunda carta:\n");
    entrada_dados(&c2);
    saida_dados(c2);

    // Exibir menu e obter a escolha do usuário
    int atributo = exibir_menu();

    // Comparar as duas cartas com base na escolha do usuário
    comparar_cartas(c1, c2, atributo);

    return 0; 
}