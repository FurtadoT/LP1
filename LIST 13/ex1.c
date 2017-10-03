/*
    TOBIAS FURTADO - 170141X
    03.10.2017

    EXERCICIO 1.
        Faça uma função que receba um valor n e crie
    dinamicamente um vetor de n elementos e retorne
    um ponteiro. Crie uma função que receba um ponteiro
    para um vetor e um valor n e imprima os n
    elementos desse vetor. Construa também uma
    função que receba um ponteiro para um vetor e libere
    esta área de memória. Por fim, crie uma função principal
    que leia um valor n e chame a função de alocação de
    memória. Depois, a função principal deve ler os n
    elementos desse vetor. Então, a função principal deve
    chamar a função de impressão dos n elementos do vetor
    criado e, finalmente, liberar a memória alocada através
    da função criada para liberação.
*/

#include <stdio.h>
#include <stdlib.h>

int* criarPonteiro(int n);
void imprimirVetor(int *p, int n);
void liberarMemoria(int *p);

int main(void){
    int contadorA, n, *p;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    p = criarPonteiro(n);

    for (contadorA = 0; contadorA < n; contadorA++){
        printf("Digite o %d valor: ", (contadorA + 1));
        scanf("%d", (p + contadorA));
    }

    imprimirVetor(p, n);
    liberarMemoria;

    return 1;
}

int* criarPonteiro(int n){
    int *p;
    return (p = (int *) malloc(n * sizeof(int)));
}

void imprimirVetor(int *p, int n){
    int contadorA;

    printf("\nValores do vetor:\n");
    for (contadorA = 0; contadorA < n; contadorA++)
        printf("%d ", *(p + contadorA));

    printf("\n");
}

void liberarMemoria(int *p){
    free(p);
}
