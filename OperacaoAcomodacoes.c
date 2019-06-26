#define ARQUIVO_BINARIO_ACOMODACOES "Acomodacoes.bin"

#include "OperacaoAcomodacoes.h"
#include "Operacaohospede.h"



void GravaArquivoBinarioAcomodacoes(Acomodacoes *acomodacoes){
    FILE *arq = fopen(ARQUIVO_BINARIO_ACOMODACOES, "ab");
    if(arq != NULL){
        fwrite(acomodacoes, sizeof(Acomodacoes),1,arq);
        printf("Acomodacao cadastrada com sucesso!\n");
    }
    else{
        printf("Erro ao abrir o arquivo!1\n");
        exit(1);
    }
    fclose(arq);

}

void LerArquivoBinarioAcomodacoes(Acomodacoes *acomodacoes,int tam){

    FILE *arq = fopen(ARQUIVO_BINARIO_ACOMODACOES, "rb");
    if (arq != NULL) {
        while (1) {
            size_t aux = fread(acomodacoes, sizeof(Acomodacoes), tam, arq);
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

void AlteraArquivoBinarioAcomodacoes(Acomodacoes *acomodacoes,int tam){
    FILE *arq = fopen(ARQUIVO_BINARIO_ACOMODACOES, "wb");
    if (arq != NULL) {
        fwrite(acomodacoes, sizeof(Acomodacoes)*(tam), 1, arq);
        fclose(arq);
    } else {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    printf("Acomodacao alterada com sucesso!\n");
}

void AlteraAcomodacoes(int tam, int op, int cod, char *aux, int Intaux){

    Acomodacoes *acomodacoes = malloc(sizeof(Acomodacoes) * (tam));
    LerArquivoBinarioAcomodacoes(acomodacoes, tam);

    for (int i = 0; i < tam; i++) {
        if (acomodacoes[i].codAcomodacao == cod) {
            switch (op) {
                case 1:
                    strcpy(acomodacoes[i].descricao, aux);
                    break;
                case 2 :
                    strcpy(acomodacoes[i].facilidades, aux);
                    break;
                case 3:
                    strcpy(acomodacoes[i].categoria, aux);
                    break;
            }
            break;
        }
    }
    AlteraArquivoBinarioAcomodacoes(acomodacoes,tam);
}

void fazReserva(int cod,int tam,int hospedeCod){
    Acomodacoes *acomodacoes = malloc(sizeof(Acomodacoes)*(tam));
    Hospede *hospede = malloc(sizeof(Hospede));

    for (int (i) = 0; (i) <=tam; ++(i)) {
        if(cod == acomodacoes[i].codAcomodacao && acomodacoes[i].disponivel == 1 && acomodacoes[i].ativo == 1){
            acomodacoes[i].disponivel = 0;
            acomodacoes[i].codHospede = hospede[i].codHospede;
        }
    }
    AlteraArquivoBinarioAcomodacoes(acomodacoes,tam);
    printf("Reserva feita com sucesso!\n");
}

void DesativaAcomodacoes(int cod,int tam){
    Acomodacoes *acomodacoes = malloc(sizeof(Acomodacoes) * (tam));
    LerArquivoBinarioAcomodacoes(acomodacoes,tam);
    for(int i = 0; i < tam; i++){
        if(cod == acomodacoes[i].codAcomodacao){
            acomodacoes[i].ativo = 0;
        }
    }
    AlteraArquivoBinarioAcomodacoes(acomodacoes,tam);

}