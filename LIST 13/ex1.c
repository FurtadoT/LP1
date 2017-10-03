/*
    TOBIAS FURTADO - 170141X
    03.10.2017

    EXERCICIO 1.
        Fa�a uma fun��o que receba um valor n e crie
    dinamicamente um vetor de n elementos e retorne
    um ponteiro. Crie uma fun��o que receba um ponteiro
    para um vetor e um valor n e imprima os n
    elementos desse vetor. Construa tamb�m uma
    fun��o que receba um ponteiro para um vetor e libere
    esta �rea de mem�ria. Por fim, crie uma fun��o principal
    que leia um valor n e chame a fun��o de aloca��o de
    mem�ria. Depois, a fun��o principal deve ler os n
    elementos desse vetor. Ent�o, a fun��o principal deve
    chamar a fun��o de impress�o dos n elementos do vetor
    criado e, finalmente, liberar a mem�ria alocada atrav�s
    da fun��o criada para libera��o.
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
