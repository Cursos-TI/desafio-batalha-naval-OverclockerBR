#include <stdio.h>

// Definindo o tamanho do tabuleiro principal (mantendo 10x10 do Aventureiro)
#define TAB_LINHAS 10
#define TAB_COLUNAS 10

// Definindo o tamanho das matrizes de habilidade (para demonstração dos padrões)
#define HABILIDADE_TAMANHO 5 // As habilidades serão demonstradas em uma matriz 5x5

// Função para exibir uma matriz genérica
void exibirMatriz(int linhas, int colunas, int matriz[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n"); // Linha em branco para separação
}

int main() {
    // --- Parte do Nível Aventureiro (Mantida) ---

    int tabuleiro[TAB_LINHAS][TAB_COLUNAS];

    printf("--- NÍVEL MESTRE: Batalha Naval com Habilidades ---\n");
    printf("Inicializando o tabuleiro principal 10x10 com água (0)...\n");
    for (int i = 0; i < TAB_LINHAS; i++) {
        for (int j = 0; j < TAB_COLUNAS; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    printf("Tabuleiro principal inicializado com sucesso!\n\n");

    // Posicionamento dos Quatro Navios (do Nível Aventureiro)
    // Os navios serão marcados com '3' no tabuleiro principal
    // (Não vou repetir as mensagens detalhadas de posicionamento aqui para focar nas habilidades)

    // Navio 1: Vertical (tamanho 4)
    int navio1_linha_inicial = 1; int navio1_coluna_inicial = 0; int navio1_tamanho = 4;
    for (int i = 0; i < navio1_tamanho; i++) {
        if (navio1_linha_inicial + i < TAB_LINHAS && navio1_coluna_inicial < TAB_COLUNAS)
            tabuleiro[navio1_linha_inicial + i][navio1_coluna_inicial] = 3;
    }

    // Navio 2: Horizontal (tamanho 5)
    int navio2_linha_inicial = 0; int navio2_coluna_inicial = 3; int navio2_tamanho = 5;
    for (int j = 0; j < navio2_tamanho; j++) {
        if (navio2_linha_inicial < TAB_LINHAS && navio2_coluna_inicial + j < TAB_COLUNAS)
            tabuleiro[navio2_linha_inicial][navio2_coluna_inicial + j] = 3;
    }

    // Navio 3: Diagonal (Baixo-Direita - tamanho 3)
    int navio3_linha_inicial = 2; int navio3_coluna_inicial = 2; int navio3_tamanho = 3;
    for (int k = 0; k < navio3_tamanho; k++) {
        if (navio3_linha_inicial + k < TAB_LINHAS && navio3_coluna_inicial + k < TAB_COLUNAS)
            tabuleiro[navio3_linha_inicial + k][navio3_coluna_inicial + k] = 3;
    }

    // Navio 4: Diagonal (Baixo-Esquerda - tamanho 4)
    int navio4_linha_inicial = 0; int navio4_coluna_inicial = 9; int navio4_tamanho = 4;
    for (int l = 0; l < navio4_tamanho; l++) {
        if (navio4_linha_inicial + l < TAB_LINHAS && navio4_coluna_inicial - l >= 0 && navio4_coluna_inicial - l < TAB_COLUNAS)
            tabuleiro[navio4_linha_inicial + l][navio4_coluna_inicial - l] = 3;
    }

    // --- Novas Funcionalidades para Nível Mestre: Habilidades Especiais ---

    // 1. Habilidade em Cone (exemplo 5x5)
    // Padrão:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    int habilidade_cone[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO];

    // Inicializa a matriz da habilidade com 0s
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            habilidade_cone[i][j] = 0;
        }
    }

    // Preenche o padrão de Cone
    // Centro do cone está em (0, HABILIDADE_TAMANHO / 2)
    int centro_coluna = HABILIDADE_TAMANHO / 2;
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) { // Percorre as linhas
        // A largura da base do cone aumenta a cada linha
        // Calculamos o deslocamento a partir do centro para cada lado
        int deslocamento = i; 
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) { // Percorre as colunas
            if (j >= centro_coluna - deslocamento && j <= centro_coluna + deslocamento) {
                habilidade_cone[i][j] = 1;
            }
        }
    }
    printf("--- Padrão de Habilidade: CONE ---\n");
    exibirMatriz(HABILIDADE_TAMANHO, HABILIDADE_TAMANHO, habilidade_cone);

    // 2. Habilidade em Octaedro (ou Diamante/Losango) (exemplo 5x5)
    // Padrão:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0
    int habilidade_octaedro[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO];

    // Inicializa a matriz da habilidade com 0s
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            habilidade_octaedro[i][j] = 0;
        }
    }

    // Preenche o padrão de Octaedro
    // Centro está em (HABILIDADE_TAMANHO / 2, HABILIDADE_TAMANHO / 2)
    int centro_oct_linha = HABILIDADE_TAMANHO / 2;
    int centro_oct_coluna = HABILIDADE_TAMANHO / 2;

    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            // Distância de Manhattan ao centro: |i - centro_oct_linha| + |j - centro_oct_coluna|
            // Para um octaedro 5x5 centrado em (2,2), os pontos afetados têm distância <= 2
            int distancia_manhattan = (i > centro_oct_linha ? i - centro_oct_linha : centro_oct_linha - i) +
                                      (j > centro_oct_coluna ? j - centro_oct_coluna : centro_oct_coluna - j);
            
            if (distancia_manhattan <= centro_oct_linha) { // Para um octaedro 5x5, o raio é 2
                habilidade_octaedro[i][j] = 1;
            }
        }
    }
    printf("--- Padrão de Habilidade: OCTAEDRO ---\n");
    exibirMatriz(HABILIDADE_TAMANHO, HABILIDADE_TAMANHO, habilidade_octaedro);

    // 3. Habilidade em Cruz (exemplo 5x5)
    // Padrão:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    int habilidade_cruz[HABILIDADE_TAMANHO][HABILIDADE_TAMANHO];

    // Inicializa a matriz da habilidade com 0s
    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            habilidade_cruz[i][j] = 0;
        }
    }

    // Preenche o padrão de Cruz
    // Linha do meio e coluna do meio
    int linha_do_meio = HABILIDADE_TAMANHO / 2;
    int coluna_do_meio = HABILIDADE_TAMANHO / 2;

    for (int i = 0; i < HABILIDADE_TAMANHO; i++) {
        for (int j = 0; j < HABILIDADE_TAMANHO; j++) {
            if (i == linha_do_meio || j == coluna_do_meio) { // Se estiver na linha do meio OU na coluna do meio
                habilidade_cruz[i][j] = 1;
            }
        }
    }
    printf("--- Padrão de Habilidade: CRUZ ---\n");
    exibirMatriz(HABILIDADE_TAMANHO, HABILIDADE_TAMANHO, habilidade_cruz);

    // --- Exibição do Tabuleiro Principal (do Nível Aventureiro) ---
    // (Ainda mostrando 0 para água e 3 para navios)
    printf("Visualização final do Tabuleiro Principal (com Navios):\n");

    printf("     "); 
    for (int j = 0; j < TAB_COLUNAS; j++) {
        printf("%c ", 'A' + j);
    }
    printf("\n");

    printf("   +-");
    for (int j = 0; j < TAB_COLUNAS; j++) {
        printf("--");
    }
    printf("+\n");

    for (int i = 0; i < TAB_LINHAS; i++) {
        printf("%2d | ", i + 1); 
        for (int j = 0; j < TAB_COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]); 
        }
        printf("|\n"); 
    }
    printf("   +-"); 
    for (int j = 0; j < TAB_COLUNAS; j++) {
        printf("--");
    }
    printf("+\n");

    return 0;
}