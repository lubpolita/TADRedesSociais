#include <stdio.h>
#include <stdlib.h>
#include "redesocial.h"
#include "interface.h"
#include <stdio_ext.h>
#include "amizades.h"

int main (){

    TRedeSocial rede;
    TUsuarios usuario;
    Iniciar(&rede);
 
    int opcao = 0;

    do{
        system("clear");
        MSG_MENU();

        printf("\n\nDigite uma opcao: ");
        __fpurge(stdin);
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        // mod 1
            SubMenuMod1(&rede, usuario);
            break;
        case 2:
            SubMenuMod2(&rede, usuario);
            break;
        case 3: 
            system("clear");
            printf("\n\n\n>>>>saindo do programa..... <<<<<");
        default:
            system("clear");
            printf("\n\n\n>>>>Digite uma opcao valida <<<<<");
            __fpurge(stdin);
            getchar();
        }


    }while(opcao !=3);

    return 0;

}