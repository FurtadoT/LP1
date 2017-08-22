/*
    TOBIAS FURTADO DA SILVA - 22/08/2017 - LP1

    EXERCICIO 4.
        Faça uma função que busque no arquivo criado em 3 os alunos que obtiveram
        média final >= 6 e imprima os seus dados.
*/

#include <stdlib.h>
#include <stdio.h>

#define MAX 2

typedef struct alunos alunos_t;
struct alunos{
    char prontuario[8];
    char nome[50];
    double np1;
    double np2;
    double mediaF;
};

int main(void){
    int contadorA;
    alunos_t alunos[MAX];
    FILE *arquivoAlunos;

    arquivoAlunos = fopen("alunos.txt", "rb");
    if (arquivoAlunos != NULL){
        fread(alunos, sizeof(alunos_t), MAX, arquivoAlunos);

        for (contadorA = 0; contadorA < MAX; contadorA++){
            if (alunos[contadorA].mediaF >= 6)
                printf("\tProntuario: %s\n\tNome: %s\n\tNota prova 1: %.2lf\n\tNota prova 2: %.2lf\n\tMedia Final: %.2lf", alunos[contadorA].prontuario, alunos[contadorA].nome, alunos[contadorA].np1, alunos[contadorA].np2, alunos[contadorA].mediaF);
            printf("\n\n");
        }
    }

    fclose(arquivoAlunos);

    return 1;
}
