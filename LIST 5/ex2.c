/*
    TOBIAS FURTADO - 29/08/2017 - LP1

    EXERCICIO 2.
        Escreva um programa que imprima um vetor
        de inteiros na ordem inversa, acessando os
        elementos por meio de um ponteiro.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main(void){
    int numeros[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, contadorA;
    int *pInteiro = &numeros[MAX-1];

    printf("\n\n\tOrdem inversa: {");
    for (contadorA = 0; contadorA < MAX; contadorA++){
        printf("%d", *(pInteiro - contadorA));

        if (contadorA != (MAX - 1)) printf(", "); else printf("}");
    }

    printf("\n\n");

    return 0;
}
