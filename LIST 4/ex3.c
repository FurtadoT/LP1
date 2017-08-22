/*
    TOBIAS FURTADO DA SILVA - 22/08/2017 - LP1

    EXERCICIO 3.
        Modifique o programa desenvolvido no exercicio 1 de modo que
        os registros de alunos que cursam LPI sejam gravados em arquivo binario.
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

void preencheVetor(alunos_t* alunos);

int main(void){
    alunos_t alunos[MAX];
    FILE *arquivoAlunos;
    preencheVetor(alunos);

    arquivoAlunos = fopen("alunos.txt", "wb");
    if (arquivoAlunos != NULL){
        fwrite(alunos, sizeof(alunos_t), MAX, arquivoAlunos);
    }

    fclose(arquivoAlunos);

    return 1;
}

void preencheVetor(alunos_t* alunos){
    int contadorA;

    for (contadorA = 0; contadorA < MAX; contadorA++){
        printf("Digite o prontuario de aluno: ");
        gets(alunos[contadorA].prontuario);
        fflush(stdin);
        printf("Digite o nome de aluno: ");
        gets(alunos[contadorA].nome);
        fflush(stdin);
        printf("Digite a nota da primeira prova: ");
        scanf("%lf", &alunos[contadorA].np1);
        fflush(stdin);
        printf("Digite a nota da segunda prova: ");
        scanf("%lf", &alunos[contadorA].np2);
        fflush(stdin);

        alunos[contadorA].mediaF = (alunos[contadorA].np1 + alunos[contadorA].np2) / 2.0;
    }
}

