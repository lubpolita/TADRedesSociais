#include <stdio.h>
#include <stdlib.h>
#include "redesocial.h"
#include "amizades.h"
#include <stdio_ext.h>


void MSG_MENU(){
    printf("\n\n\t>>>>>>>>> MENU <<<<<<<<<");
    printf("\n\n\t 1. GERENCIAMENTO DE USUARIOS");
    printf("\n\n\t 2. GERENCIAMENTO DE AMIZADES");
    printf("\n\n\t 3. SAIR");

}

void MSG_SUBMENU (int n){
    system("clear");

    if(n == 1){
        printf("\n\n\t>>>>>>>>>>>>>> MODULO %d <<<<<<<<<<<<<<<", n);
        printf("\n\n\t1. CADASTRAR");
        printf("\n\n\t2. PESQUISAR");
        printf("\n\n\t3. ALTERAR");
        printf("\n\n\t4. EXCLUIR");
        printf("\n\n\t5. IMPRIMIR");
        printf("\n\n\t6. SAIR");
    }

    else if(n == 2){
         printf("\n\n\t>>>>>>>>>>>>>> MODULO %d <<<<<<<<<<<<<<<", n);
        printf("\n\n\t1. CADASTRAR AMIZADE");
        printf("\n\n\t2. PESQUISAR AMIZADE");
        printf("\n\n\t3. EXCLUIR AMIZADE");
        printf("\n\n\t4. IMPRIMIR AMIZADES");
        printf("\n\n\t5.IMPRIMIR QUEM TEM MAIS AMIGOS.");
        printf("\n\n\t6.IMPRIMIR AMIZADES EM COMUM");
        printf("\n\n\t7. SAIR");
    }

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
            system("clear");
            printf("\n\nCADASTRE UM USER\n\n");
            Ler(&user);
            Cadastrar(rede, user); //como rede ja é ponteiro nao prec de &
            printf("\n\n Pressione qlqr tecla para continuar...");
            __fpurge(stdin);
            getchar();
    
            break;

        case 2: 
            //menu pesquisar
            printf("\n\nDigite o nome do usuario que deseja pesquisar: ");
            __fpurge(stdin);
            fgets(user.nome, 100,stdin);
            indice = Pesquisar(*rede, user);
            //if(indice>=0)
            if(indice != -1){
                printf("\n\n O indice do usuario encontrado eh: %d\n", indice);
                Imprimir(rede->vetor[indice]);
            }
            else{
                printf("\n\n Usuario nao encontrado.");
            }

            printf("\n\n Pressione qlqr tecla para continuar...");
            __fpurge(stdin);
            getchar();
    
            break;
        
        case 3: 
            //alterar
            printf("\n\nQual o nome da pessoa que deseja alterar?");
            __fpurge(stdin);
            fgets(user.nome, 100, stdin);
            indice = Pesquisar(*rede, user);
            if(indice != -1){
                Ler(&user);
                Alterar(rede, user, indice);
            }
            else {
                printf("\n\n Usuario nao encontrado.");
            }

            printf("\n\n Pressione qlqr tecla para continuar...");
            __fpurge(stdin);
            getchar();
            break;
        
        case 4:
            //excluir
            printf("\n\nQual o nome da pessoa que deseja excluir?\n");
            __fpurge(stdin);
            fgets(user.nome, 100, stdin);
            indice = Pesquisar(*rede, user);
            if (indice != -1){
                Excluir(rede, indice);
            }
            else{
                printf("\n\n Usuario nao encontrado.");
            }

            printf("\n\n Pressione qlqr tecla para continuar...");
            __fpurge(stdin);
            getchar();

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

            printf("\n\n Pressione qlqr tecla para continuar...");
            __fpurge(stdin);
            getchar();
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


void SubMenuMod2(TRedeSocial *rede, TUsuarios user1, TUsuarios user2){

    int opcao = 0;
    int indice = -1;
    int amigos;

    do {
        MSG_SUBMENU(2);
        printf("\n\nDigite uma opcao: ");
        __fpurge(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: 
            //menu cadastrar
            system("clear");
            printf("\n\nCADASTRE UMA AMIZADE\n\n");
            printf("\n\nDigite o nome do primeiro usuario: ");
            __fpurge(stdin);
            fgets(user1.nome, 100,stdin);

             printf("\n\nDigite o nome do segundo usuario: ");
            __fpurge(stdin);
            fgets(user2.nome, 100,stdin);

            CadastrarAmizade(rede, user1, user2);

            printf("\n\n Pressione qlqr tecla para continuar...");
            __fpurge(stdin);
            getchar();
    
            break;

        case 2: 
            //menu pesquisar
           printf("\n\nDigite o nome do primeiro usuario: ");
            __fpurge(stdin);
            fgets(user1.nome, 100,stdin);

             printf("\n\nDigite o nome do segundo usuario: ");
            __fpurge(stdin);
            fgets(user2.nome, 100,stdin);

            indice = PesquisarAmizade(*rede, user1, user2);
            //if(indice>=0)
            if(indice == 1){
                printf("%s e %s sao amigos!", user1.nome, user2.nome);
                }
            else{
                printf("%s e %s nao sao amigos!", user1.nome, user2.nome);

            }

            printf("\n\n Pressione qlqr tecla para continuar...");
            __fpurge(stdin);
            getchar();
    
            break;
        
        case 3: 
            //excluir
             printf("\n\nDigite o nome do primeiro usuario: ");
            __fpurge(stdin);
            fgets(user1.nome, 100,stdin);

             printf("\n\nDigite o nome do segundo usuario: ");
            __fpurge(stdin);
            fgets(user2.nome, 100,stdin);

            ExcluirAmizade(rede, user1, user2);
            
            printf("\n\n Pressione qlqr tecla para continuar...");
            __fpurge(stdin);
            getchar();
            break;
        
        case 4:
            //imprimir amizades
            printf("\n\nDigite o nome do usuario: ");
            __fpurge(stdin);
            fgets(user1.nome, 100,stdin);
            ImprimirAmigos(*rede, user1); 

            printf("\n\n Pressione qlqr tecla para continuar...");
            __fpurge(stdin);
            getchar();

            break;
        
        case 5:

        //mais amigos
            system("clear");
            MaisAmigos(*rede);

            printf("\n\n Pressione qlqr tecla para continuar...");
            __fpurge(stdin);
            getchar();

            break;
        
        case 6:
        //amigos em comum
            printf("\n\nDigite o nome do primeiro usuario: ");
            __fpurge(stdin);
            fgets(user1.nome, 100,stdin);

             printf("\n\nDigite o nome do segundo usuario: ");
            __fpurge(stdin);
            fgets(user2.nome, 100,stdin);


            amigos = AmigosEmComum(*rede, user1, user2);
            printf("\n\nA quantidade de amigos em comum eh: %d", amigos);

            printf("\n\n Pressione qlqr tecla para continuar...");
            __fpurge(stdin);
            getchar();
            break;

        case 7:
          
            system("clear");
            printf("\n\n\n\t>>>>>> saindo do modulo <<<<<");
            system("PAUSE");
            break;

         
        default:
            system("clear");
            printf("\n\n\n\t>>>>>> Digite uma opcao valida <<<<<");
            system("PAUSE");
            __fpurge(stdin);
            getchar();
            break;
        }

    }while(opcao != 7);

}