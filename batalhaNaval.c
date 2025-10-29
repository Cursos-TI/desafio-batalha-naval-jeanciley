#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    int tabuleiro[10][10] = {0};

    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    printf("Navio 1 (Horizontal) posicionado em:\n");
    for (int i = 0; i < 3; i++) {
        tabuleiro[2][2 + i] = 3; // Parte do navio 1
        printf("(%d, %d)\n", 2, 2 + i);
    }

    printf("Navio 2 (Vertical) posicionado em:\n");
    for (int i = 0; i < 3; i++) {
        tabuleiro[4 + i][5] = 3; // Parte do navio 2
        printf("(%d, %d)\n", 4 + i, 5);
    }

    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios. 
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal

    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    printf("Navio 3 (Diagonal) posicionado em:\n");
    for (int i = 0; i < 3; i++) {
        tabuleiro[7 + i][7 + i] = 3; // Navio diagonal 1
        printf("(%d, %d)\n", 7 + i, 7 + i);
    }

    printf("Navio 4 (Diagonal) posicionado em:\n");
    for (int i = 0; i < 3; i++) {
        tabuleiro[6 + i][2 + i] = 3; // Navio diagonal 2
        printf("(%d, %d)\n", 6 + i, 2 + i);
    }
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    int cone[3][5] = {0};
    // Preenchendo a habilidade em cone
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            if(j == 2 || (i == 1 && (j == 1 || j == 2 || j == 3)) || (i == 2 && (j >= 0 && j <= 4))) {
                cone[i][j] = 1;
            }
        }
    }
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    int octaedro[3][5] = {0};
    // Preenchendo a habilidade em octaedro
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            if((i == 0 && j == 2) || (i == 2 && j == 2)) {
                octaedro[i][j] = 1;
            } else if (i == 1 && (j == 1 || j == 2 || j == 3)) {
                octaedro[i][j] = 1;
            }
        }
    }
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    int cruz[3][5] = {0};
    // Preenchendo a habilidade em cruz
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            if((i == 0 && j == 2) || (i == 2 && j == 2)) {
                cruz[i][j] = 1;
            } else if ((i == 1 &&(j == 0 || j == 1 || j == 2 || j == 3 || j == 4))) {
                cruz[i][j] = 1;
            }           
        }
    }
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    //Posição das habilidades no tabuleiro
    // Posicionando habilidade em cone no tabuleiro com posição de inicio (0, 0)
    printf("A habilidade de Cone afeta as seguintes posicoes:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            if (cone[i][j] != 0) {
                if (tabuleiro[0 + i][ 0 + j] == 3) {
                    printf("(%d, %d) Navio atingido!\n", 0 + i, 0 + j);
                } else {
                    printf("(%d, %d)\n", 0 + i, 0 + j);
                }
                tabuleiro[i][j] = 5; // Area afetada pela habilidade em cone
            }
        }
    }

    // Posicionando habilidade em cruz no tabuleiro com posição de inicio (4, 5)
    printf("A habilidade de Cruz afeta as seguintes posicoes:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            if (cruz[i][j] != 0) {
                if (tabuleiro[4 + i][ 5 + j] == 3) {
                    printf("(%d, %d) Navio atingido!\n", 4 + i, 5 + j);
                } else {
                    printf("(%d, %d)\n", 4 + i, 5 + j);
                }
                tabuleiro[4 + i][ 5 + j] = 5; // Area afetada pela habilidade em cruz             
            }
        }
    }

    // Posicionando habilidade em octaedro no tabuleiro com posição de inicio (7, 0)
    printf("A habilidade de Octaedro afeta as seguintes posicoes:\n");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            if (octaedro[i][j] != 0) {
                if (tabuleiro[7 + i][ 0 + j] == 3) {
                    printf("(%d, %d) Navio atingido!\n", 7 + i, 0 + j);
                } else {
                    printf("(%d, %d)\n", 7 + i, 0 + j);
                }
                tabuleiro[7 + i][0 + j] = 5; // Area afetada pela habilidade em octaedro
            }
        }
    }

    //Imprimindo o tabuleiro final
    for(int i = 0; i < 10; i++) {          // percorre as linhas
        for(int j = 0; j < 10; j++) {      // percorre as colunas
            printf("%d\t", tabuleiro[i][j]); // imprime o elemento e um tab
        }
        printf("\n"); // pula para a próxima linha
    }


    return 0;
}
