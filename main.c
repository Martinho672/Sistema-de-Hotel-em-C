#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Helper.h"
#include "Operacaohospede.h"


#define ARQUIVO_HOSPEDES_BINARIO "hospedes.bin"

int cod = 0;

int menuHospedes();

void listarHospede();

//void buscarHospedes();

//void alterarHospedes();

//void excluirHospedes();


int main() {
    Hospede *hospede = malloc(sizeof(Hospede));
    Codigo *codigo = malloc(sizeof(Codigo));

    int op;
    do {
        op = menuHospedes();
        switch (op) {

            case 1:
                printf("Cadastrar Hospede\n");
                printf("Digite os dados a seguir:\n");
                printf("Nome:");
                scanf(" %[^\n]s", hospede->nome);
                printf("\nCPF:\t");
                scanf(" %[^\n]s", hospede->CPF);
                printf("\nEmail:\t");
                scanf(" %[^\n]s", hospede->email);
                printf("\nData de Nascimento(01/01/1901): \t");
                scanf(" %[^\n]s", hospede->dataNascimento);
                printf("\nEstado Civil: \t");
                scanf(" %s", hospede->estadoCivil);
                printf("\nSexo (m / f):\t");
                scanf(" %s", hospede->sexo);
                printf("Digite o Endereco a seguir:\n");
                printf("Estado:\t");
                scanf(" %[^\n]s", hospede->estado);
                printf("\nCidade:\t");
                scanf(" %[^\n]s", hospede->cidade);
                printf("\nBairro:\t");
                scanf(" %[^\n]s", hospede->bairro);
                printf("\nRua:\t");
                scanf(" %[^\n]s", hospede->rua);
                printf("\nNumero:\t");
                scanf(" %[^\n]s", hospede->numero);
                hospede->codHospede = codigo->codigoHospede;
                CadastraHospede(hospede);

                break;
            case 2:
                printf("Listar Hospede\n");
                listarHospede();
                break;
            case 3:
                printf("Alterar Hospede\n");
                //alterarHospedes();
                break;
            case 4:
                printf("Buscar Hospede\n");
                //buscarHospedes();
                break;
            case 5:
                printf("Excluir Hospede\n");
                //excluirHospedes();
                break;
        }
    } while (op != 0);
    return 0;
}


int menuHospedes(void) {

    int opcao;

    do {
        printf("MENU - HOSPEDES\n");
        printf("1 - Cadastrar\n2 - Listar\n3 - Alterar Cadastro\n4 - Excluir\n5 - Buscar\n0 - Sair\n");
        printf("Digite sua opcao:\n");
        scanf("%d", &opcao);
        if ((opcao < 0) || (opcao > 5)) {
            printf("Opcao invalida!!!!!\n");
        }
    } while ((opcao < 0 || opcao > 5));
    return opcao;
}

void listarHospede() {
    Hospede *hospede = malloc(sizeof(Hospede) * 4);
    LerArquivoHospede(hospede);
    int cont = 0;
    int qtdHospede = 3;

    printf("\nQuantidade de Hospedes cadastrados: %d\n", qtdHospede);

    for (cont; cont < qtdHospede; cont++){
        printf("Nome: %s\n", hospede[cont].nome);
        printf("CPF: %s\n", hospede[cont].CPF);
        printf("Email: %s\n", hospede[cont].email);
        printf("Data Nascimento: %s\n", hospede[cont].dataNascimento);
        printf("Estado civil: %s\n", hospede[cont].estadoCivil);
        printf("Endereco:\n");
        printf("Estado: %s\n", hospede[cont].estado);
        printf("Cidade:%s\n", hospede[cont].cidade);
        printf("Bairro: %s\n", hospede[cont].bairro);
        printf("Rua: %s\n", hospede[cont].rua);
        printf("Numero: %s\n", hospede[cont].numero);
    }

}

void buscarHospede(){
    Hospede *hospede = malloc(sizeof(Hospede));


}