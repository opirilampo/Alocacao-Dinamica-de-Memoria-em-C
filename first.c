#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

// Função para alocar memória para a matriz
int** alocarMatriz(int lin, int col) {
    int **matriz = malloc(lin * sizeof(int*));
    if (matriz == NULL) return NULL;
    for (int i = 0; i < lin; i++) {
        matriz[i] = malloc(col * sizeof(int));
        if (matriz[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            return NULL;
        }
    }
    return matriz;
}

// Função para realocar memória da matriz
int** realocarMatriz(int nvlin, int nvcol, int** matrizog, int lin_atual) {
    int** matrizreserva = realloc(matrizog, nvlin * sizeof(int*));
    if (matrizreserva == NULL) return NULL;
    for (int i = 0; i < nvlin; i++) {
        if (i < lin_atual) {
            int* nova_linha = realloc(matrizreserva[i], nvcol * sizeof(int));
            if (nova_linha == NULL) {
                for (int j = 0; j < i; j++) {
                    free(matrizreserva[j]);
                }
                free(matrizreserva);
                return NULL;
            }
            matrizreserva[i] = nova_linha;
        } else {
            matrizreserva[i] = malloc(nvcol * sizeof(int));
            if (matrizreserva[i] == NULL) {
                for (int j = 0; j < i; j++) {
                    free(matrizreserva[j]);
                }
                free(matrizreserva);
                return NULL;
            }
        }
    }
    return matrizreserva;
}

// Função para validar a resposta do usuário (s/n)
char mecnProsseguir(char resposta) {
    do {
        scanf(" %c", &resposta);
        resposta = tolower(resposta);
        if (resposta != 's' && resposta != 'n') {
            printf("Resposta inválida, digite s ou n. Deseja continuar? (s/n)?\n");
        }
    } while (resposta != 's' && resposta != 'n');
    return resposta;
}

// Função para liberar memória da matriz
void liberarMatriz(int **matriz, int lin) {
    for (int i = 0; i < lin; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// Função para preencher a matriz com valores fornecidos pelo usuário
void preencherMatriz(int **matriz, int lin, int col) {
    for (int i = 0; i < lin; i++) {
        for (int c = 0; c < col; c++) {
            printf("Matriz[%d][%d] = ", i, c);
            scanf("%d", &matriz[i][c]);
        }
    }
}

// Função para validar a entrada de um número inteiro
int mecnConfInt(int entrada) {
    char ch;
    int saida;
    bool valido = false;
    while(!valido) {
        if (scanf("%d", &entrada) == 1) {
            valido = true;
            return entrada;
        } else {
            printf("Entrada inválida. Por favor, digite um número inteiro.\n");
            while ((ch = getchar()) != '\n' && ch != EOF);
        }
    }
    return -1;
}

// Função para preencher a matriz realocada com novos valores
void repreencherMatriz(int **matriz, int lin, int col, int nvlin, int nvcol) {
    for (int i = 0; i < nvlin; i++) {
        for (int c = 0; c < nvcol; c++) {
            if (i >= lin || c >= col) {
                printf("Matriz[%d][%d] = ", i, c);
                matriz[i][c] = mecnConfInt(matriz[i][c]);
            }
        }
    }
}

// Função para exibir a matriz
void exibirMatriz(int **matriz, int lin, int col) {
    printf("\nSua matriz:\n");
    for (int i = 0; i < lin; i++) {
        for (int c = 0; c < col; c++) {
            printf("%d ", matriz[i][c]);
        }
        printf("\n");
    }
}

// Função para verificar se a realocação negativa irá apagar a matriz
char mecnRealocarNegativo(int numatual, int numrlc) {
    char apagar;
    if(numatual + numrlc <= 0 && numrlc < 0) {
        printf("Ao realocar %d a matriz chegará a zero e será apagada, deseja prosseguir?(s/n)", numrlc);
        apagar = mecnProsseguir(apagar);
        if (apagar == 's') {
            printf("Matriz encerrada.\n");
        }
    }
    return apagar;
}

// Função principal
int main() {
    int lin, col;
    do {
        printf("Quantas linhas terá sua matriz?\n");
        lin = mecnConfInt(lin);
        printf("Quantas colunas terá sua matriz?\n");
        col = mecnConfInt(col);
        if (lin < 1 || col < 1) {
            printf("O número de linhas e/ou colunas deve ser maior ou igual a 1.\n");
        }
    } while (lin < 1 || col < 1);
    
    int **matriz = alocarMatriz(lin, col);
    if (matriz == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    
    preencherMatriz(matriz, lin, col);
    exibirMatriz(matriz, lin, col);
    
    char prosseguir, seguir;
    int rlin, rcol;
    printf("Deseja realocar sua matriz? (s/n)\n");
    prosseguir = mecnProsseguir(prosseguir);
    if (prosseguir == 's') {
        printf("Quantas linhas deseja realocar (seja para aumentar ou diminuir)?\n");
        rlin = mecnConfInt(rlin);
        seguir = mecnRealocarNegativo(lin, rlin);
        if (seguir == 's') {
            liberarMatriz(matriz, lin);
            return 1;
        }
        
        printf("Quantas colunas deseja realocar (seja para aumentar ou diminuir)?\n");
        rcol = mecnConfInt(rcol);
        seguir = mecnRealocarNegativo(col, rcol);
        if (seguir == 's') {
            liberarMatriz(matriz, lin);
            return 1;
        }
        
        int lin_antiga = lin;
        lin += rlin;
        col += rcol;
        matriz = realocarMatriz(lin, col, matriz, lin_antiga);
        if (matriz == NULL) {
            printf("Erro ao alocar memória. \n");
            liberarMatriz(matriz, lin);
            return 1;
        }
        repreencherMatriz(matriz, lin_antiga, col - rcol, lin, col);
        exibirMatriz(matriz, lin, col);
    }
    
    liberarMatriz(matriz, lin);
    return 0;
}
