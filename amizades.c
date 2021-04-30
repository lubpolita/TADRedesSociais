#include <stdio.h>
#include <stdlib.h>
#include "redesocial.h"


int PesquisarAmizade(TRedeSocial rede, TUsuarios user1, TUsuarios user2){
    int indice1, indice2;

    indice1 = Pesquisar(rede,user1);
    indice2 = Pesquisar(rede, user2);

    if(rede.matrix[indice1][indice2] == 1 && rede.matrix[indice2][indice1] == 1){
        return 1;
    }
    return 0;
}


void CadastrarAmizade (TRedeSocial *rede, TUsuarios user1, TUsuarios user2){
    int indice1, indice2, ver;
    indice1 = Pesquisar(*rede, user1);
    indice2 = Pesquisar(*rede, user2);

    ver = PesquisarAmizade(*rede, user1, user2);

    if(ver != 1){
        rede->matrix[indice1][indice2] = 1;
        rede->matrix[indice2][indice1] = 1;
        printf("\n\nAmizade cadastrada com sucesso!");
    }
    else{
        printf("\n\nA amizade ja existe.");
    }

}

void ExcluirAmizade (TRedeSocial *rede, TUsuarios user1, TUsuarios user2){
    int indice1, indice2, ver;

    indice1 = Pesquisar(*rede,user1);
    indice2 = Pesquisar(*rede, user2);

    ver = PesquisarAmizade(*rede, user1, user2);

      if(ver != 0){
        rede->matrix[indice1][indice2] = 0;
        rede->matrix[indice2][indice1] = 0;
        printf("\n\nAmizade excluida com sucesso!");
    }
    else{
        printf("\n\nA amizade nao existente.");
    }
    
}


void ImprimirAmigos (TRedeSocial rede, TUsuarios user){

    int i, j, indice;
    int cont = 0;

    indice = Pesquisar(rede, user);

    for(i = 0; i < rede.indice; i++){
        if(rede.matrix[indice][i] == 1 && rede.matrix [i][indice] == 1){
            cont++;
            printf("\n\n\n>>>>>>>>>>>>>>>>AMIGO %d<<<<<<<<<<<<<<<<<", cont);
            Imprimir(rede.vetor[i]);
        }
    } 


}


void MaisAmigos(TRedeSocial rede){

    int i, j;
    int max = 0;
    int cont = 0;
    int popular;
    for (i = 0; i < rede.indice; i++){
        for(j = 0; j < rede.indice; j++){
            if(rede.matrix[i][j] == 1){
                cont++;
            }
            cont = 0;
        }
        if(cont > max){
            popular = i;
        }
    }

    printf("\n\n%s eh a pessoa com mais amigos na rede social.\n", rede.vetor[popular].nome);
}


int AmigosEmComum(TRedeSocial rede, TUsuarios user1, TUsuarios user2){

    int i, j, amigos1, amigos2;
    int indice1, indice2, amigo;
    int cont = 0;
    //confere se eles sao amigos
    amigo = PesquisarAmizade(rede, user1, user2);

    if(amigo == 0){
        indice1 = Pesquisar(rede, user1);
        indice2 = Pesquisar(rede, user2);

        for(i = 0; i < rede.indice; i++){
            amigos1 = rede.matrix[indice1][i];
            amigos2 = rede.matrix[indice2][i];
            if(amigos1 == 1 && amigos2 == 1){
                cont++;
            }
        }
    }
    return cont;

}