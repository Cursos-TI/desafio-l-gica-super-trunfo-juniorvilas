#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de país
typedef struct {
    char nome[50];
    int populacao;
    int area;
    int pib;
    int densidade_demografica;
} Carta;

// Função para exibir o menu de atributos e obter a escolha do usuário
int escolherAtributo(int excluido) {
    int escolha;
    printf("\nEscolha um atributo para comparar:\n");
    if (excluido != 1) printf("1 - População\n");
    if (excluido != 2) printf("2 - Área\n");
    if (excluido != 3) printf("3 - PIB\n");
    if (excluido != 4) printf("4 - Densidade Demográfica\n");
    printf("Escolha: ");
    scanf("%d", &escolha);
    
    // Valida se a escolha é válida
    if (escolha < 1 || escolha > 4 || escolha == excluido) {
        printf("Opção inválida. Tente novamente.\n");
        return escolherAtributo(excluido);
    }
    return escolha;
}

// Função para obter o valor do atributo
int obterValorAtributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.densidade_demografica;
        default: return 0;
    }
}

// Função para comparar dois atributos
int compararAtributo(int valor1, int valor2, int atributo) {
    return (atributo == 4) ? (valor1 < valor2) : (valor1 > valor2);
}

// Função principal
int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 211000000, 8515767, 2200000, 25};
    Carta carta2 = {"Argentina", 45000000, 2780000, 500000, 16};

    printf("Comparando %s vs %s\n", carta1.nome, carta2.nome);
    
    // Escolha dos dois atributos
    int atributo1 = escolherAtributo(0);
    int atributo2 = escolherAtributo(atributo1);
    
    // Obter valores
    int valor1A = obterValorAtributo(carta1, atributo1);
    int valor2A = obterValorAtributo(carta2, atributo1);
    int valor1B = obterValorAtributo(carta1, atributo2);
    int valor2B = obterValorAtributo(carta2, atributo2);
    
    // Soma total
    int soma1 = valor1A + valor1B;
    int soma2 = valor2A + valor2B;
    
    // Exibir resultados
    printf("\nResultados:\n");
    printf("%s - %d (%d) e %d (%d) - Total: %d\n", carta1.nome, valor1A, atributo1, valor1B, atributo2, soma1);
    printf("%s - %d (%d) e %d (%d) - Total: %d\n", carta2.nome, valor2A, atributo1, valor2B, atributo2, soma2);
    
    // Determinar vencedor
    if (soma1 > soma2) printf("%s venceu!\n", carta1.nome);
    else if (soma2 > soma1) printf("%s venceu!\n", carta2.nome);
    else printf("Empate!\n");
    
    return 0;
}
