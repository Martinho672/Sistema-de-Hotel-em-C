#define ARQUIVO_BINARIO_CATEGORIA_ACOMODACOES "CategoriaAcomodacoes.bin"

#include "OperacaoCategoriaAcomodacoes.h"



void GravaArquivoBinarioCategoriaAcomodacoes(CategoriaAcomodacoes *categoriaAcomodacoes){
    FILE *arq = fopen(ARQUIVO_BINARIO_CATEGORIA_ACOMODACOES, "ab");
    if(arq != NULL){
        fwrite(categoriaAcomodacoes, sizeof(CategoriaAcomodacoes),1,arq);
        printf("Categoria de acomodacao cadastrada com sucesso!\n");
    }
    else{
        printf("Erro ao abrir o arquivo!1\n");
        exit(1);
    }
    fclose(arq);

}

void LerArquivoBinarioCategoriaAcomodacoes(CategoriaAcomodacoes *categoriaAcomodacoes,int tam){

    FILE *arq = fopen(ARQUIVO_BINARIO_CATEGORIA_ACOMODACOES, "rb");
    if (arq != NULL) {
        while (1) {
            size_t aux = fread(categoriaAcomodacoes, sizeof(CategoriaAcomodacoes), tam, arq);
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

void AlteraArquivoBinarioCategoriaAcomodacoes(CategoriaAcomodacoes *categoriaAcomodacoes,int tam){
    FILE *arq = fopen(ARQUIVO_BINARIO_CATEGORIA_ACOMODACOES, "wb");
    if (arq != NULL) {
        fwrite(categoriaAcomodacoes, sizeof(CategoriaAcomodacoes)*(tam), 1, arq);
        fclose(arq);
    } else {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    printf("Categoria alterada com sucesso!\n");
}

void AlteraCategoriaAcomodacoes(int tam, int op, int cod, char *aux, int Intaux,float Floataux){

    CategoriaAcomodacoes *categoriaAcomodacoes = malloc(sizeof(CategoriaAcomodacoes) * (tam));
    LerArquivoBinarioCategoriaAcomodacoes(categoriaAcomodacoes,tam);

    for (int i = 0; i < tam; i++) {
        if (categoriaAcomodacoes[i].codCategoriaAcomodacoes == cod) {
            switch (op) {
                case 1:
                    strcpy(categoriaAcomodacoes[i].descricaoCategoria, aux);
                    break;
                case 2 :
                    categoriaAcomodacoes[i].qntPessoas = Intaux;
                    break;
                case 3:
                    categoriaAcomodacoes[i].valorDiaria = Floataux;
                    break;
            }
            break;
        }
    }
    AlteraArquivoBinarioCategoriaAcomodacoes(categoriaAcomodacoes,tam);
}
