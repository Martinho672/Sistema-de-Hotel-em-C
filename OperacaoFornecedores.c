#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "OperacaoFornecedores.h"
#define ARQUIVO_FORNECEDORES_BINARIO "Fornecedores.bin"
#define TEMP_FORNECEDORES_BINARIO "TempFornecedores.bin"


void CadastraFornecedores(Fornecedores *fornecedores){
    FILE *arq = fopen(ARQUIVO_FORNECEDORES_BINARIO, "ab");
    if(arq != NULL){
        fwrite(fornecedores, sizeof(Fornecedores),1,arq);
        fclose(arq);
    }
    else
    {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

}

void LerArquivoFornecedores(Fornecedores *fornecedores,int tam){
    FILE *arq = fopen(ARQUIVO_FORNECEDORES_BINARIO, "rb");

    if(arq != NULL)
    {
        while(1)
        {

            size_t aux = fread(fornecedores, sizeof(Fornecedores),tam,arq);
            if (aux < 1)
            {
                break;
            }
        }

    }
    else{
        printf("Erro ao abrir arquivo para leitura!\n");
        exit(1);
    }
}

void AlteraFornecedorCadastro(Fornecedores *fornecedores,int tam) {
    FILE *arq = fopen(ARQUIVO_FORNECEDORES_BINARIO, "wb");
    if (arq != NULL) {
        fwrite(fornecedores, sizeof(Fornecedores)*(tam), 1, arq);
        fclose(arq);
    } else {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    printf("Fornecedor alterado com sucesso!\n");

}

void AlteraFornecedoresBinario(int cod, int opc, char *campo, int tam){
    Fornecedores *fornecedores = malloc(sizeof(Fornecedores) * (tam));
    LerArquivoFornecedores(fornecedores,tam);

    for (int i = 0; i < tam; ++i) {
        if(fornecedores[i].codFornecedor == cod){
            switch (opc){
                case 1:
                    strcpy(fornecedores[i].nomeFantasiaFornecedor, campo);
                    break;
                case 2:
                    strcpy(fornecedores[i].razaoSocialFornecedor, campo);
                    break;
                case 3:
                    strcpy(fornecedores[i].inscricaoEstadualFornecedor, campo);
                    break;
                case 4:
                    strcpy(fornecedores[i].cnpjFornecedor, campo);
                    break;
                case 5:
                    strcpy(fornecedores[i].estadoFornecedor, campo);
                    break;
                case 6:
                    strcpy(fornecedores[i].cidadeFornecedor, campo);
                    break;
                case 7:
                    strcpy(fornecedores[i].bairroFornecedor,campo);
                    break;
                case 8:
                    strcpy(fornecedores[i].ruaFornecedor,campo);
                    break;
                case 9:
                    strcpy(fornecedores[i].telefoneFornecedor,campo);
                    break;
                case 10:
                    strcpy(fornecedores[i].emailFornecedor,campo);
                    break;
            }
            break;
        }
    }
    AlteraFornecedorCadastro(fornecedores,tam);
}

void DesativaFornecedor(int cod,int tam){
    Fornecedores *fornecedores = malloc(sizeof(Fornecedores) * (tam));
    LerArquivoFornecedores(fornecedores,tam);
    for(int i = 0; i < tam; i++){
        if(cod == fornecedores[i].codFornecedor){
            fornecedores[i].ativo = 0;
        }
    }
    AlteraFornecedorCadastro(fornecedores,tam);

}

