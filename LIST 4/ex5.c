/*
    TOBIAS FURTADO DA SILVA - 22/08/2017 - LP1

    EXERCICIO 5.
        Faça um programa que leia uma tabela com N codigos e profissoes.
        Depois, grave em arquivo binario. No mesmo programa ou em outro,
        leia esse arquivo binario para a tabela e, dado um codigo, escreva a profissao.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 2

typedef struct profissoes profissoes_t;
struct profissoes{
    int cod;
    char profissao[30];
};

void preencheProfissoes(profissoes_t* profissoes);
void gravaProfissoes(profissoes_t* profissoes);
void printProfissao(int cod);

int main(void){
    int auxCod;
    profissoes_t profissoes[N];
    preencheProfissoes(profissoes);
    gravaProfissoes(profissoes);

    printf("Agora, digite o codigo da profissao que voce quer encontrar: ");
    scanf("%d", &auxCod);

    printProfissao(auxCod);

    return 1;
}

void preencheProfissoes(profissoes_t* profissoes){
    int contadorA;

    for (contadorA = 0; contadorA < N; contadorA++){
        printf("Digite o codigo da profissao: ");
        scanf("%d", &profissoes[contadorA].cod);
        fflush(stdin);
        printf("Digite a profissao: ");
        fgets(profissoes[contadorA].profissao, 30, stdin);
        fflush(stdin);
    }
}

void gravaProfissoes(profissoes_t* profissoes){
    FILE *arquivoProfissoes;

    arquivoProfissoes = fopen("profissoes.txt", "wb");
    if (arquivoProfissoes != NULL){
        fwrite(profissoes, sizeof(profissoes_t), N, arquivoProfissoes);
    }

    fclose(arquivoProfissoes);
}

void printProfissao(int auxCod){
    int contadorA;
    FILE *arquivoProfissoes;
    profissoes_t profissoes[N];

    arquivoProfissoes = fopen("profissoes.txt", "rb");
    if (arquivoProfissoes != NULL){
        fread(profissoes, sizeof(profissoes_t), N, arquivoProfissoes);

        for (contadorA = 0; contadorA < N; contadorA++){
            if (profissoes[contadorA].cod == auxCod) break;
        }
    }

    fclose(arquivoProfissoes);

    printf("\n\tA profissao de cod %d e: %s\n\n", auxCod, profissoes[contadorA].profissao);
}


