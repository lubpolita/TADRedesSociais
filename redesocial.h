#define REDESOCIAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


//inicio TAD

typedef struct tdata
{
int dia;
int mes;
int ano;
}TData;


typedef struct usuarios{
char nome[100];
char email[200];
char login[50];
char senha[50];
TData data_de_nascimento;
int ID; // deverá ser gerado pelo programa e
// igual ao índice do elemento cadastrado no vetor (lista)
}TUsuarios;


typedef struct redeSocial{
TUsuarios vetor[100];// lista de usuários
int matrix[100][100]; // matriz de relacionamentos de amizade
int indice; // indica a posição em que o próximo elemento vai ser inserido na lista e
// também informa a quantidade de usuários cadastrados na lista
}TRedeSocial;


//funções
void Ler(TUsuarios *user);
void Imprimir(TUsuarios user);
void Iniciar(TRedeSocial *rede);
void Cadastrar(TRedeSocial *rede, TUsuarios user);
void Imprimir2(TRedeSocial rede);
int Pesquisar(TRedeSocial rede, TUsuarios user);
void Alterar(TRedeSocial *rede, TUsuarios user, int indice);
void Excluir(TRedeSocial *rede, int indice);

