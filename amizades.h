
#ifndef AMIZADES_H
#define AMIZADES_H
#include <stdio.h>
#include <stdlib.h>
#include "redesocial.h"


int PesquisarAmizade(TRedeSocial rede, TUsuarios user1, TUsuarios user2);
void CadastrarAmizade (TRedeSocial *rede, TUsuarios user1, TUsuarios user2);
void ExcluirAmizade (TRedeSocial *rede, TUsuarios user1, TUsuarios user2);
void ImprimirAmigos (TRedeSocial rede, TUsuarios user);
void MaisAmigos(TRedeSocial rede);
int AmigosEmComum(TRedeSocial rede, TUsuarios user1, TUsuarios user2);
#endif