#include <stdio.h>
#include <stdlib.h>
#include "Operacaohospede.h"
#define ARQUIVO_HOSPEDE_BINARIO "Hospede.bin"

void CadastraHospede(Hospede *hospede){

    FILE *arq = fopen(ARQUIVO_HOSPEDE_BINARIO, "ab");

    if(arq != NULL){

        fwrite(hospede, sizeof(Hospede),1,arq);
        fclose(arq);
    }
    else
    {
        printf("\nErro ao abrir o arquivo para leitura!\n");
        exit(1);
    }

}


void LerArquivoHospede(Hospede *hospedes)
{
    Hospede *hospede = malloc(sizeof(Hospede));
    FILE *arq = fopen(ARQUIVO_HOSPEDE_BINARIO, "rb");
    int i = 0;
    if(arq != NULL)
    {

        while(1)
        {
            size_t tam = fread(hospede, sizeof(Hospede),1,arq);
            if (tam<1)
            {
                break;
            }
            hospedes[i] = hospede[0];
            i++;
        }

        fclose(arq);
    }
    else
    {
        hospede->codHospede = 0;
    }

}
