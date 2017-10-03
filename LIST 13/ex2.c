/*
    TOBIAS FURTADO - 170141X
    03.10.2017

    EXERCICIO 2.
        Construa uma função que receba dois parâmetros m e n,
    aloque uma matriz de ordem m x n e retorne um ponteiro para
    a matriz alocada em tempo de execução. Crie ainda outra
    função que receba por parâmetro um ponteiro para matriz e
    libere a área de memória alocada. Finalmente, crie um
    programa (main) que teste/use as duas funções criadas.
*/

#include <stdio.h>
#include <stdlib.h>

int **criarMatriz(int m, int n);
void imprimirMatriz(int **matriz, int m, int n);
void liberarMemoria(int **matriz, int m);

int main(void){
    int contadorA, contadorB, m, n;
    int **matriz;

    printf("Digite a quantidade de linhas da matriz: ");
    scanf("%d", &m);
    printf("Digite a quantidade de colunas da matriz: ");
    scanf("%d", &n);

    matriz = criarMatriz(m, n);

    for (contadorA = 0; contadorA < m; contadorA++){
        for (contadorB = 0; contadorB < n; contadorB++){
            printf("M[%d][%d]: ", contadorA, contadorB);
            scanf("%d", &matriz[contadorA][contadorB]);
        }
    }

    imprimirMatriz(matriz, m, n);

    liberarMemoria(matriz, m);


    return 1;
}

int **criarMatriz(int m, int n){
    int contadorA;
    int **matriz;

    matriz = (int **) malloc(m * sizeof(int*));
    for (contadorA = 0; contadorA < m; contadorA++)
        *(matriz + contadorA) = (int *) malloc(n * sizeof(int));

    return matriz;
}

void imprimirMatriz(int **matriz, int m, int n){
    int contadorA, contadorB;

    printf("\nValores da matriz:\n");
    for (contadorA = 0; contadorA < m; contadorA++){
        for (contadorB = 0; contadorB < n; contadorB++){
            printf("%d\t", matriz[contadorA][contadorB]);
        }
        printf("\n");
    }
}

void liberarMemoria(int** matriz, int m){
    int contadorA;

    for (contadorA = 0; contadorA < m; contadorA++)
        free(*(matriz + contadorA));

    free(matriz);
}

