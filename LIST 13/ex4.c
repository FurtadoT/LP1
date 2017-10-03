/*
    TOBIAS FURTADO - 170141X
    03.10.2017

    EXERCICIO 4.
        Escreva um programa que solicita ao usu�rio o
    prontu�rio (inteiro) e a m�dia final (real) de todos os
    seus alunos e imprime todos os alunos que est�o de
    exame. Utilize um vetor de registros (estruturas) para
    armazenar os dados dos alunos (fa�a aloca��o
    din�mica com os N alunos que ser�o lidos). O
    programa deve ter as fun��es de aloca��o, libera��o
    de mem�ria, leitura e impress�o dos alunos de exame.
    Est�o de exame os alunos com 4<=m�dia<6.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno aluno_t;
struct aluno{
    char nome[40];
    double media;
};

aluno_t *criarAlunos(int totalAlunos);
void preencherAlunos(aluno_t *alunos, int totalAlunos);
void imprimirAlunosDeExame(aluno_t *alunos, int totalAlunos);
void liberarMemoria(aluno_t *alunos);

int main(void){
    int totalAlunos;
    aluno_t *alunos;

    printf("Digite o total de alunos: ");
    scanf("%d", &totalAlunos);
    fflush(stdin);

    alunos = criarAlunos(totalAlunos);
    preencherAlunos(alunos, totalAlunos);
    imprimirAlunosDeExame(alunos, totalAlunos);
    liberarMemoria(alunos);

    return 1;
}

aluno_t *criarAlunos(int totalAlunos){
    aluno_t *alunos = (aluno_t *) malloc(totalAlunos * sizeof(aluno_t));

    return alunos;
}

void preencherAlunos(aluno_t *alunos, int totalAlunos){
    int contadorA;

    for(contadorA = 0; contadorA < totalAlunos; contadorA++){
        printf("Digite o nome do %d aluno: ", (contadorA + 1));
        fgets(alunos[contadorA].nome, 40, stdin);
        fflush(stdin);
        alunos[contadorA].nome[(strlen(alunos[contadorA].nome) - 1)] = '\0';
        printf("Digite a media: ");
        scanf("%lf", &alunos[contadorA].media);
        fflush(stdin);
    }
}

void imprimirAlunosDeExame(aluno_t *alunos, int totalAlunos){
    int contadorA;

    printf("\nAlunos de exame:\n\n");
    for (contadorA = 0; contadorA < totalAlunos; contadorA++)
        if ((alunos[contadorA].media >= 4) && (alunos[contadorA].media < 6))
            printf("Nome: %s\nMedia: %.2lf\n", alunos[contadorA].nome, alunos[contadorA].media);
}

void liberarMemoria(aluno_t *alunos){
    free(alunos);
}

