#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "redesocial.h"

/*

FUNÇÕES AUXILIARES

*/


void Imprimir(TUsuarios user){
    printf("\nNome do Usuario: ");
    printf("\n%s", user.nome);


    printf("\nEmail: ");
    printf("\n%s", user.email);


    printf("\nLogin: ");
    printf("\n%s", user.login);

    printf("\nSenha do Usuario: ");
    printf("\n%s", user.senha);

    printf("Data de Nascimento: ");
    printf("\n%s / %s / %s ", user.data_de_nascimento.dia, user.data_de_nascimento.mes, user.data_de_nascimento.ano);

}


void Ler(TUsuarios *user){
    printf("\nDigite o nome do usuario: ");
    __fpurge(stdin);
    fgets(user->nome, 100, stdin);

    printf("\nDigite o e-mail do usuario: ");
    __fpurge(stdin);
    fgets(user->email, 200, stdin);

    printf("\nDigite o login do usuario: ");
    __fpurge(stdin);
    fgets(user->login, 50, stdin);

    printf("\nDigite a senha do usuario: ");
    __fpurge(stdin);
    fgets(user->senha, 50, stdin);

    printf("\nDigite a data de nascimento: ");
    printf("\nDia: ");
    __fpurge(stdin);
    scanf("%d", &user->data_de_nascimento.dia);

    printf("\nMes: ");
    __fpurge(stdin);
    scanf("%d", &user->data_de_nascimento.mes);


    printf("\nAno: ");
    __fpurge(stdin);
    scanf("%d", &user->data_de_nascimento.ano);
    

}


/*
OPERAÇÕES BÁSICAS

*/

void Iniciar(TRedeSocial *rede){
    
    int i, j;

    //inicia a matriz de relacionamentos
    for(i = 0; i < 100; i++){
        for(j = 0; j < 100; j++){
            rede->matrix[i][j] = 0;
        }
    }

    //inicia indice
    rede->indice = 0;
}

void Cadastrar(TRedeSocial *rede, TUsuarios user){

    if(rede->indice < 100){
    user.ID = rede->indice; // troca o indice antes de inserir
    rede->vetor[rede->indice] = user;  //adiciona usuario no vetor indice
    rede->indice++; //incrementa indice
    }
}


//imprime todas as informações de um elemento TUsuario
void Imprimir2 (TRedeSocial rede){

    int i;
    printf("\n\n\n\n\n------------USUARIOS----------\n");
    
    for (i = 0; i < rede.indice; i++){
        printf("\n----------Usuario %d: -----------------\n", i+1);
        //caso o usuario nao tenha sido excluido
        if(rede.vetor[i].ID != -1){
            Imprimir(rede.vetor[i]);
        }
    }

}


//pesquisa pelo nome
int Pesquisar (TRedeSocial rede, TUsuarios user){

    //retorna -1 se nao encontrar e indice se encontrar
    int i; 
    for(i = 0; i < rede.indice; i++){
        if(strcmp(rede.vetor[i].nome, user.nome) == 0){
            return i;   //indice encontrado
        }
        else{
            return -1; // nao encontrado
        }
    }


}

//qual o nome que voce deseja alterar? 
//antes i = pesquisar(rede, usuario);
// agora leia o usuario Ler(&usuario);
//passe os args
void Alterar (TRedeSocial *rede, TUsuarios user, int indice){
    user.ID = indice;
    rede->vetor[indice] = user;
}


//pesquisa antes o indice com a função pesquisar
void Excluir (TRedeSocial *rede, int indice){
    int i, j;

    rede->vetor[indice].ID = -1;  //-1 significa usuario inativo
//zerar coluna do usuario 
    for (i = 0; i < rede->indice; i++){
        for(j = 0; j < rede->indice; j++){
            rede->matrix[indice][j] = 0; //excluindo amizades de colunas
        }
        rede->matrix[i][indice] = 0; //excluindo amizades de linhas
    }
}


