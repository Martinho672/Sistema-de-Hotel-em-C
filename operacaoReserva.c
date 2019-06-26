#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "operacaoReserva.h"

#define ARQUIVO_RESERVA_BINARIO "Reserva.bin"

void ReservaAcomodacaoBinario(Reserva *reserva){
    FILE *arq;
    arq = fopen(ARQUIVO_RESERVA_BINARIO,"ab");
    if (arq != NULL){
        fwrite(reserva, sizeof(Reserva),1,arq);
        fclose(arq);
    }else{
        printf("Erro ao abrir arquivo de reserva!\n");
        exit(1);
    }
    printf("Reserva concluida com Sucesso!\n");

}

void LerReservaBinario(Reserva *reserva){
    FILE *arq = fopen(ARQUIVO_RESERVA_BINARIO,"rb");
    if(arq != NULL){
        while (1)
        {
            size_t tam = fread(reserva, sizeof(Reserva), 1, arq);
            if (tam < 1 )
                break;
        }
        fclose(arq);
    }
    else
    {
      printf("Erro ao ler arquivo!\n");
      exit(1);
    }

}