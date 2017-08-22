/*
    TOBIAS FURTADO DA SILVA - 22/08/2017 - LP1

    EXERCICIO 2.
    Faça um programa que leia um arquivo contendo as notas da primeira prova de 40
    alunos de LPI, calcule e mostre a media da turma.
        Dica: use a funcao atof(), para converter a nota (string) lida do arquivo em número real (float).
        Ex. de uso: char str [ ] = “8.5”;
        float nota;
        nota = atof(str);
*/

#include <stdlib.h>
#include <stdio.h>

#define MAX 3

int main(void){
    int contadorA;
    double notaAlunos = 0;
    char auxConverter[6];
    FILE *arquivoAlunos;

    arquivoAlunos = fopen("notasAlunos.txt", "r");
    if (arquivoAlunos != NULL){
        while(!feof(arquivoAlunos)){
            fgets(auxConverter, 5, arquivoAlunos);
            notaAlunos += atof(auxConverter);
        }
    }

    fclose(arquivoAlunos);

    printf("\n\nMedia da turma: %.2lf\n\n", notaAlunos/MAX);

    return 1;
}
