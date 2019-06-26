#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Operacaohospede.h"
#include "Helper.h"

#define ARQUIVO_HOSPEDE_BINARIO "Hospede.bin"

void CadastraHospede(Hospede *hospede) {

    FILE *arq = fopen(ARQUIVO_HOSPEDE_BINARIO, "ab");

    if (arq != NULL) {

        fwrite(hospede, sizeof(Hospede), 1, arq);
        fclose(arq);

    } else {
        printf("\nErro ao abrir o arquivo para leitura!\n");
        exit(1);
    }

}


void LerArquivoHospede(Hospede *hospede, int tam) {


    FILE *arq = fopen(ARQUIVO_HOSPEDE_BINARIO, "rb");
    if (arq != NULL) {
        while (1) {
            size_t aux = fread(hospede, sizeof(Hospede), tam, arq);
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
void AlteraHospedeCadastro(Hospede *hospede,int tam) {
    FILE *arq = fopen(ARQUIVO_HOSPEDE_BINARIO, "wb");
    if (arq != NULL) {
        fwrite(hospede, sizeof(Hospede)*(tam), 1, arq);
        fclose(arq);
    } else {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    printf("Hospede alterado com sucesso!\n");

}

void AlteraHospede(int tam, int op, int cod, char *aux) {
    Hospede *hospede = malloc(sizeof(Hospede) * (tam));
    LerArquivoHospede(hospede, tam);

    for (int i = 0; i < tam; i++) {
        if (hospede[i].codHospede == cod) {
            switch (op) {
                case 1:
                    strcpy(hospede[i].nome, aux);
                    break;
                case 2 :
                    strcpy(hospede[i].CPF, aux);
                    break;
                case 3:
                    strcpy(hospede[i].email, aux);
                    break;
                case 4:
                    strcpy(hospede[i].dataNascimento, aux);
                    break;
                case 5:
                    strcpy(hospede[i].estadoCivil, aux);
                    break;
                case 6:
                    strcpy(hospede[i].sexo, aux);
                    break;
                case 7:
                    strcpy(hospede[i].estado, aux);
                    break;
                case 8:
                    strcpy(hospede[i].cidade, aux);
                    break;
                case 9:
                    strcpy(hospede[i].bairro, aux);
                    break;
                case 10:
                    strcpy(hospede[i].rua, aux);
                    break;
                case 11:
                    strcpy(hospede[i].numero, aux);
                    break;
                case 12:
                    strcpy(hospede[i].telefone, aux);
                    break;
            }
            break;
        }

    }
    AlteraHospedeCadastro(hospede,tam);
}

void DesativaHospede(int cod, int tam) {
    Hospede *hospede = malloc(sizeof(Hospede) * (tam));
    LerArquivoHospede(hospede,tam);
    for(int i = 0; i < tam; i++){
        if(cod == hospede[i].codHospede){
            hospede[i].ativo = 0;
        }
    }
    AlteraHospedeCadastro(hospede,tam);
}
