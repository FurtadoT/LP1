/*
    TOBIAS FURTADO DA SILVA - 22/08/2017 - LP1

    EXERCICIO 1.
    Faça um programa que preencha um vetor com 10 registros de alunos que cursam LPI.
    Cada registro sera composto pelos seguintes campos:
    prontuario, nome, nota_p1, nota_p2 e media final.
    Em seguida, percorra o vetor armazenando cada registro de aluno em um arquivo chamado alunos.txt.
        Obs: cada linha do arquivo deve conter 1 registro apenas,
        sendo que o valor de cada campo deve estar separado por um hifen (-).
*/

#include <stdlib.h>
#include <stdio.h>

#define MAX 10

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
    int contadorA;
    alunos_t alunos[MAX];
    FILE *arquivoAlunos;
    preencheVetor(alunos);

    arquivoAlunos = fopen("alunos.txt", "w");
    if (arquivoAlunos != NULL){
        for (contadorA = 0; contadorA < MAX; contadorA++){
            fprintf(arquivoAlunos, "%s-%s-%.2lf-%.2lf-%.2lf\n", alunos[contadorA].prontuario, alunos[contadorA].nome, alunos[contadorA].np1, alunos[contadorA].np2, alunos[contadorA].mediaF);
        }
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
