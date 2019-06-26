#include "Produto.h"
#include "Helper.h"

void GravaArquivoProduto(Produto *produto);
void LerArquivoProduto(Produto *produtos, int tam);
void AlteraProduto(int tam, int op,int cod,char *aux,int Intaux, float Floataux);
void DesativaProduto(int cod, int tam);
void AlteraProdutoCadastro(Produto *produto,int tam);
