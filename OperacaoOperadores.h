#ifndef DEFINITIVO_OPERACAOOPERADORES_H
#define DEFINITIVO_OPERACAOOPERADORES_H

#include "Operador.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif /*OPERACAOOPERADORES_H */

void GravaOperadorBinario(Operadores *operador);
int VerificaOperadorBinario(Operadores *operador, int tam, char nomeOperador[50],char senhaOperador[6]);
void LerOperadorBinario(Operadores *operador,int tam);
void AlteraOperadorBinario(int cod, int opc, char *campo, int campoAux, int tam);