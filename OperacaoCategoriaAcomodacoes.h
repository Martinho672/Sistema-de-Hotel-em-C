#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "CategoriaAcomodacoes.h"
#include "Helper.h"

void GravaArquivoBinarioCategoriaAcomodacoes(CategoriaAcomodacoes *categoriaAcomodacoes);
void LerArquivoBinarioCategoriaAcomodacoes(CategoriaAcomodacoes *categoriaAcomodacoes,int tam);
void AlteraArquivoBinarioCategoriaAcomodacoes(CategoriaAcomodacoes *categoriaAcomodacoes,int tam);
void AlteraCategoriaAcomodacoes(int tam, int op, int cod, char *aux, int Intaux, float Floataux);