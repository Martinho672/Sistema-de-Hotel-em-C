#ifndef DEFINITIVO_OPERACAOFORNECEDORES_H
#define DEFINITIVO_OPERACAOFORNECEDORES_H

#endif //DEFINITIVO_OPERACAOFORNECEDORES_H

#include "Fornecedores.h"

void CadastraFornecedores(Fornecedores *fornecedores);
void LerArquivoFornecedores(Fornecedores *fornecedores,int tam);
void AlteraFornecedoresBinario(int cod, int opc, char *campo, int tam);
void DesativaFornecedor(int cod,int tam);