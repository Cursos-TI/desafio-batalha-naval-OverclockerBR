#include <stdio.h>

// Definindo o novo tamanho do tabuleiro para o Nível Aventureiro
#define LINHAS 10
#define COLUNAS 10

int main() {
    // Declara a matriz bidimensional para representar o tabuleiro
    // 0 = água (posição sem navio)
    // 3 = parte de um navio (posição ocupada)
    int tabuleiro[LINHAS][COLUNAS];

    // Inicializa o tabuleiro com água (0)
    printf("--- NÍVEL AVENTUREIRO: Batalha Naval ---\n");
    printf("Inicializando o tabuleiro 10x10 com água (0)...\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    printf("Tabuleiro inicializado com sucesso!\n\n");

    // --- Posicionamento dos Quatro Navios ---

    // Navio 1: Vertical (tamanho 4)
    // Posição inicial: Linha 1, Coluna 0 (display: 2,A)
    // Ocupará (1,0), (2,0), (3,0), (4,0)
    int navio1_linha_inicial = 1;
    int navio1_coluna_inicial = 0;
    int navio1_tamanho = 4; // Aumentado para 4

    printf("Posicionando Navio 1 (Vertical - Tamanho %d):\n", navio1_tamanho);
    for (int i = 0; i < navio1_tamanho; i++) {
        int linha_matriz = navio1_linha_inicial + i;
        int coluna_matriz = navio1_coluna_inicial;
        
        // Converte coordenadas da matriz para display
        int linha_display = linha_matriz + 1;
        char coluna_display = 'A' + coluna_matriz;

        if (linha_matriz < LINHAS && coluna_matriz < COLUNAS) {
            tabuleiro[linha_matriz][coluna_matriz] = 3; // Marca como parte do navio (valor 3)
            printf("  Parte do Navio 1 em: (%d, %c) - (Interno: %d,%d)\n", linha_display, coluna_display, linha_matriz, coluna_matriz);
        } else {
            printf("  Erro: Tentativa de posicionar Navio 1 fora do tabuleiro em: (%d, %c)\n", linha_display, coluna_display);
        }
    }
    printf("\n");

    // Navio 2: Horizontal (tamanho 5)
    // Posição inicial: Linha 0, Coluna 3 (display: 1,D)
    // Ocupará (0,3), (0,4), (0,5), (0,6), (0,7)
    int navio2_linha_inicial = 0;
    int navio2_coluna_inicial = 3;
    int navio2_tamanho = 5; // Aumentado para 5

    printf("Posicionando Navio 2 (Horizontal - Tamanho %d):\n", navio2_tamanho);
    for (int j = 0; j < navio2_tamanho; j++) {
        int linha_matriz = navio2_linha_inicial;
        int coluna_matriz = navio2_coluna_inicial + j;

        // Converte coordenadas da matriz para display
        int linha_display = linha_matriz + 1;
        char coluna_display = 'A' + coluna_matriz;

        if (linha_matriz < LINHAS && coluna_matriz < COLUNAS) {
            tabuleiro[linha_matriz][coluna_matriz] = 3; // Marca como parte do navio (valor 3)
            printf("  Parte do Navio 2 em: (%d, %c) - (Interno: %d,%d)\n", linha_display, coluna_display, linha_matriz, coluna_matriz);
        } else {
            printf("  Erro: Tentativa de posicionar Navio 2 fora do tabuleiro em: (%d, %c)\n", linha_display, coluna_display);
        }
    }
    printf("\n");

    // Navio 3: Diagonal (Canto Superior Esquerdo para Baixo e Direita - tamanho 3)
    // Posição inicial: Linha 2, Coluna 2 (display: 3,C)
    // Ocupará (2,2), (3,3), (4,4)
    int navio3_linha_inicial = 2;
    int navio3_coluna_inicial = 2;
    int navio3_tamanho = 3;

    printf("Posicionando Navio 3 (Diagonal Baixo-Direita - Tamanho %d):\n", navio3_tamanho);
    for (int k = 0; k < navio3_tamanho; k++) {
        int linha_matriz = navio3_linha_inicial + k;
        int coluna_matriz = navio3_coluna_inicial + k; // Tanto linha quanto coluna incrementam

        // Converte coordenadas da matriz para display
        int linha_display = linha_matriz + 1;
        char coluna_display = 'A' + coluna_matriz;

        if (linha_matriz < LINHAS && coluna_matriz < COLUNAS) {
            tabuleiro[linha_matriz][coluna_matriz] = 3; // Marca como parte do navio (valor 3)
            printf("  Parte do Navio 3 em: (%d, %c) - (Interno: %d,%d)\n", linha_display, coluna_display, linha_matriz, coluna_matriz);
        } else {
            printf("  Erro: Tentativa de posicionar Navio 3 fora do tabuleiro em: (%d, %c)\n", linha_display, coluna_display);
        }
    }
    printf("\n");

    // Navio 4: Diagonal (Canto Superior Direito para Baixo e Esquerda - tamanho 4)
    // Posição inicial: Linha 0, Coluna 9 (display: 1,J)
    // Ocupará (0,9), (1,8), (2,7), (3,6)
    int navio4_linha_inicial = 0;
    int navio4_coluna_inicial = 9;
    int navio4_tamanho = 4;

    printf("Posicionando Navio 4 (Diagonal Baixo-Esquerda - Tamanho %d):\n", navio4_tamanho);
    for (int l = 0; l < navio4_tamanho; l++) {
        int linha_matriz = navio4_linha_inicial + l;  // Linha incrementa
        int coluna_matriz = navio4_coluna_inicial - l; // Coluna decrementa

        // Converte coordenadas da matriz para display
        int linha_display = linha_matriz + 1;
        char coluna_display = 'A' + coluna_matriz;

        if (linha_matriz < LINHAS && coluna_matriz >= 0 && linha_matriz < LINHAS && coluna_matriz < COLUNAS) { // Validação de limite inferior da coluna
            tabuleiro[linha_matriz][coluna_matriz] = 3; // Marca como parte do navio (valor 3)
            printf("  Parte do Navio 4 em: (%d, %c) - (Interno: %d,%d)\n", linha_display, coluna_display, linha_matriz, coluna_matriz);
        } else {
            printf("  Erro: Tentativa de posicionar Navio 4 fora do tabuleiro em: (%d, %c)\n", linha_display, coluna_display);
        }
    }
    printf("\n");


    // --- Exibindo o Tabuleiro Completo com Letras e Números ---
    printf("Visualização final do Tabuleiro (Nível Aventureiro):\n");

    // Imprime o cabeçalho das colunas (letras)
    printf("     "); // Espaço para alinhar com os números das linhas (agora 2 dígitos)
    for (int j = 0; j < COLUNAS; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    // Imprime uma linha divisória
    printf("   +-");
    for (int j = 0; j < COLUNAS; j++) {
        printf("--");
    }
    printf("+\n");

    // Imprime as linhas com os números e o conteúdo do tabuleiro
    for (int i = 0; i < LINHAS; i++) {
        printf("%2d | ", i + 1); // Números das linhas (1-baseado) e borda esquerda, com 2 espaços
        for (int j = 0; j < COLUNAS; j++) {
            // Se for água, mostra '~'
            // Se for navio, mostra 'S'
            if (tabuleiro[i][j] == 0) {
                printf("0 ");
            } else { // tabuleiro[i][j] == 3
                printf("3 ");
            }
        }
        printf("|\n"); // Borda direita
    }
    printf("   +-"); // Borda inferior
    for (int j = 0; j < COLUNAS; j++) {
        printf("--");
    }
    printf("+\n");

    return 0;
}