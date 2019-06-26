#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "OperacaoHotel.h"
#define ARQUIVO_HOTEL_BINARIO "Hotel.bin"
void CadastraHotel(Hotel *hotel)
{
    FILE *arq = fopen(ARQUIVO_HOTEL_BINARIO, "wb");

    if (arq != NULL)
    {
        fwrite(hotel, sizeof(Hotel), 1, arq);

        fclose(arq);

    }
    else
    {
        printf("\nErro ao abrir o arquivo para leitura!\n");
        exit(1);
    }
}

void LerArquivohotel(Hotel *hotel)
{

    FILE *arq = fopen(ARQUIVO_HOTEL_BINARIO, "rb");


    if (arq != NULL)
    {
        while (1)
        {
            size_t tam = fread(hotel, sizeof(Hotel), 1, arq);
            if (tam < 1 )
                break;
        }
        fclose(arq);
    }
    else
    {
        hotel->numeroHotel = 0;
    }
}

void AlteraHotelGrava(Hotel *hotel){
    FILE *arq = fopen(ARQUIVO_HOTEL_BINARIO, "wb");
    if (arq != NULL) {
        fwrite(hotel, sizeof(Hotel), 1, arq);
        fclose(arq);
    } else {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    printf("Hotel alterado com sucesso!\n");

}


void AlteraHotel(int op,char aux[200],int Intaux) {
    Hotel *hotel = malloc(sizeof(Hotel));
    LerArquivohotel(hotel);

    switch (op) {
        case 1:
            strcpy(hotel->nome, aux);
            break;
        case 2:
            strcpy(hotel->razaoSocial, aux);
            break;
        case 3:
            strcpy(hotel->inscricaoEstadual, aux);
            break;
        case 4:
            strcpy(hotel->CNPJ, aux);
            break;
        case 5:
            strcpy(hotel->estado, aux);
            break;
        case 6:
            strcpy(hotel->cidade, aux);
            break;
        case 7:
            strcpy(hotel->bairro, aux);
            break;
        case 8:
            strcpy(hotel->rua, aux);
            break;
        case 9:
            strcpy(hotel->numero, aux);
            break;
        case 10:
            strcpy(hotel->email, aux);
            break;
        case 11:
            strcpy(hotel->nomeGerente, aux);
            break;
        case 12:
            hotel->telefone = Intaux;
            break;
        case 13:
            hotel->telefoneGerente = Intaux;
            break;
        case 14:
            hotel->lucro = Intaux;
            break;
        case 15:
            strcpy(hotel->checkin, aux);
            break;
        case 16:
            strcpy(hotel->checkout, aux);
            break;
    }
    AlteraHotelGrava(hotel);
    free(hotel);
}


