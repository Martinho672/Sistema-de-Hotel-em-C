#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Acomodacoes.h"
#include "Helper.h"

void GravaArquivoBinarioAcomodacoes(Acomodacoes *acomodacoes);
void LerArquivoBinarioAcomodacoes(Acomodacoes *acomodacoes,int tam);
void AlteraArquivoBinarioAcomodacoes(Acomodacoes *acomodacoes,int tam);
void AlteraAcomodacoes(int tam, int op, int cod, char *aux, int Intaux);
void DesativaAcomodacoes(int cod,int tam);
void fazReserva(int cod,int tam,int hospedeCod);
