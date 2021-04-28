#include <stdio.h>
#include <stdlib.h>
#include "redesocial.h"
#include "interface.h"


void MSG_MENU(){
    printf("\n\n\t>>>>>>>>> MENU <<<<<<<<<");
    printf("\n\n\t MODULO 1 - GERENCIAMENTO DE USUARIOS");
    printf("\n\n\t MODULO 2 - GERENCIAMENTO DE AMIZADES");
    printf("\n\n\t SAIR");

}

void MSG_SUBMENU (int n){
    system("clear");
    printf("\n\n\t>>>>>>>>>>>>>> MODULO %d <<<<<<<<<<<<<<<", n);
    printf("\n\n\t1. CADASTRAR");
    printf("\n\n\t2. PESQUISAR");
    printf("\n\n\t3. ALTERAR");
    printf("\n\n\t4. EXCLUIR");
    printf("\n\n\t5. IMPRIMIR");
    printf("\n\n\t6. SAIR");

}

void SubMenuMod1(TRedeSocial *rede, TUsuarios user){

    int opcao = 0;
    int indice = -1;

    do {
        MSG_SUBMENU(1);
        printf("\n\nDigite uma opcao: ");
        __fpurge(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: 
            //menu cadastrar
            Ler(&user);
            Cadastrar(rede, user); //como rede ja é ponteiro nao prec de &
            break;

        case 2: 
            //menu pesquisar
            printf("\n\nDigite o nome do usuario que deseja pesquisar: ");
            __fpurge(stdin);
            fgets(&user.nome, 100,stdin);
            indice = Pesquisar(*rede, user);
            if(indice != -1){
                printf("\n\n O indice do usuario encontrado eh: %d", indice);
            }
            else{
                printf("\n\n Usuario nao encontrado.");
            }
            break;
        
        case 3: 
            //alterar
            printf("\n\nQual o nome da pessoa que deseja alterar?");
            __fpurge(stdin);
            fgets(&user.nome, 100, stdin);
            indice = Pesquisar(*rede, user);
            if(indice != -1){
                Ler(&user);
                Alterar(rede, user, indice);
            }
            else {
                printf("\n\n Usuario nao encontrado.");
            }
            break;
        
        case 4:
            //excluir
            printf("\n\nQual o nome da pessoa que deseja excluir? ");
            __fpurge(stdin);
            fgets(&user.nome, 100, stdin);
            indice = Pesquisar(*rede, user);
            if (indice != -1){
                Excluir(rede, indice);
            }
            else{
                printf("\n\n Usuario nao encontrado.");
            }

            break;
        
        case 5:
            //imprimir 
            /*printf("\n\nQual o nome do usuario que deseja imprimir? ");
            __fpurge(stdin);
            fgets(&user.nome, 100, stdin);
            indice = Pesquisar(*rede, user);
            if(indice != -1){
                Imprimir(rede->vetor[indice]);
            }
            else{
                printf("\n\n Usuario nao encontrado.");
            }*/
            Imprimir2(*rede);
            break;
        
        case 6: 
            system("clear");
            printf("\n\n\n\t>>>>>> saindo do modulo <<<<<");
            system("PAUSE");
            break;

        default:
            system("clear");
            printf("\n\n\n\t>>>>>> saindo do modulo <<<<<");
            system("PAUSE");
            __fpurge(stdin);
            getchar();
            break;
        }

    }while(opcao !=6);

}