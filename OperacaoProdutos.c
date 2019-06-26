#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OperacaoProdutos.h"
#include "Helper.h"

#define ARQUIVO_PRODUTO_BINARIO "Produto.bin"

void GravaArquivoProduto(Produto *produto) {

    FILE *arq = fopen(ARQUIVO_PRODUTO_BINARIO, "ab");

    if (arq != NULL) {

        fwrite(produto, sizeof(Produto), 1, arq);
        fclose(arq);

    } else {
        printf("\nErro ao abrir o arquivo para leitura!\n");
        exit(1);
    }

}


void LerArquivoProduto(Produto *produtos, int tam) {


    FILE *arq = fopen(ARQUIVO_PRODUTO_BINARIO, "rb");
    if (arq != NULL) {
        while (1) {
            size_t aux = fread(produtos, sizeof(Produto), tam, arq);
            if (aux < 1) {
                break;
            }

        }

    } else {
        printf("Erro ao Ler arquivo(arquivo nao existe ou danificado !\n");
        exit(1);
    }
    fclose(arq);

}

/*
 * A funcao "AlteraHospedeCadastro" abre o arquivo hospede para alteracao
 */
void AlteraProdutoCadastro(Produto *produto,int tam) {
    FILE *arq = fopen(ARQUIVO_PRODUTO_BINARIO, "wb");
    if (arq != NULL) {
        fwrite(produto, sizeof(Produto)*(tam), 1, arq);
        fclose(arq);
    } else {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    printf("Hospede alterado com sucesso!\n");

}

void AlteraProduto(int tam, int op,int cod,char *aux,int Intaux, float Floataux) {
    Produto *produto = malloc(sizeof(Produto) * (tam));
    LerArquivoProduto(produto, tam);

    for (int i = 0; i < tam; i++) {
        if (produto[i].codProduto == cod) {
            switch (op) {
                case 1:
                    strcpy(produto[i].descricao, aux);
                    break;
                case 2 :
                    produto[i].estoqueMinimo = Intaux;
                    break;
                case 3:
                    produto[i].estoque = Intaux;
                    break;
                case 4:
                    produto[i].precoCusto = Floataux;
                    break;
                case 5:
                    produto[i].precoVenda = Floataux;
                    break;
            }
            break;
        }

    }
    AlteraProdutoCadastro(produto,tam);
}

void DesativaProduto(int cod, int tam) {
    Produto *produto = malloc(sizeof(Produto) * (tam));
    LerArquivoProduto(produto,tam);
    for(int i = 0; i < tam; i++){
        if(cod == produto[i].codProduto){
            produto[i].ativo = 0;
        }
    }
    AlteraProdutoCadastro(produto,tam);
}
