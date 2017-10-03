/*
    TOBIAS FURTADO - 170141X
    03.10.2017

    EXERCICIO 3.
        Criar um registro (alocação dinâmica) que represente uma
    pessoa, contendo nome, data de nascimento e e-mail. Crie
    uma variável que é um ponteiro para este registro (no
    programa principal). Depois crie uma função que receba este
    ponteiro e preencha os dados da estrutura e também uma
    função que receba este ponteiro e imprima os dados da
    estrutura. Finalmente, faça as chamadas as funções criadas no
    programa principal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa pessoa_t;
struct pessoa{
    char nome[40];
    char dtNascimento[15];
    char email[40];
};

void preencherDados(pessoa_t *pessoa);
void imprimirPessoa(pessoa_t *pessoa);


int main(void){
    pessoa_t* pessoa = (pessoa_t *) malloc(sizeof(pessoa_t));

    preencherDados(pessoa);
    imprimirPessoa(pessoa);

    free(pessoa);
    return 1;
}

void preencherDados(pessoa_t *pessoa){
    printf("Digite o nome: ");
    fgets(pessoa->nome, 40, stdin);
    fflush(stdin);
    pessoa->nome[(strlen(pessoa->nome) - 1)] = '\0';
    printf("Digite a data de nascimento: ");
    fgets(pessoa->dtNascimento, 15, stdin);
    fflush(stdin);
    pessoa->dtNascimento[(strlen(pessoa->dtNascimento) - 1)] = '\0';
    printf("Digite o e-mail: ");
    fgets(pessoa->email, 40, stdin);
    fflush(stdin);
    pessoa->email[(strlen(pessoa->email) - 1)] = '\0';
}

void imprimirPessoa(pessoa_t *pessoa){
    printf("\n\nNome: %s\n Data de nascimento: %s\n E-mail: %s", pessoa->nome, pessoa->dtNascimento, pessoa->email);
}
