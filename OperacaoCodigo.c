#include <stdio.h>
#include <stdlib.h>
#include "OperacaoCodigo.h"
#define ARQUIVO_CODIGOS_BINARIO "Codigos.bin"

void CadastraCodigo(Codigo *codigo){

    FILE *arq = fopen(ARQUIVO_CODIGOS_BINARIO, "ab");

    if(arq != NULL){

        fwrite(codigo, sizeof(Codigo),1,arq);
        fclose(arq);
    }
    else
    {
        printf("\nErro ao abrir o arquivo para leitura!\n");
        exit(1);
    }

}


void LerArquivoCodigo(Codigo *codigo)
{
    Codigo *codigo = malloc(sizeof(Codigo));
    FILE *arq = fopen(ARQUIVO_CODIGOS_BINARIO, "rb");
    int i = 0;
    if(arq != NULL)
    {

        while(1)
        {
            size_t tam = fread(codigo, sizeof(Codigo),1,arq);
            if (tam<1)
            {
                break;
            }
            codigo[i] = codigo[0];
            i++;
        }

        fclose(arq);
    }
    else
    {

    }

}

