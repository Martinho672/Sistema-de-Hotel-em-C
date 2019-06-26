#define ARQUIVO_BINARIO_OPERADOR "DadosOperador.bin"
#define ARQUIVO_TEXTO_OPERADOR "DadosOperador.txt"

#include "OperacaoOperadores.h"

/*
 * A funcao "GravaFuncionarioBinario", abre o arquivo para salvar em binario,
 * e grava os dados da struct Funcionarios em binario.
 */

void GravaOperadorBinario(Operadores *operador) {
    FILE *arq = fopen(ARQUIVO_BINARIO_OPERADOR, "ab");
    if (arq != NULL) {
        fwrite(operador, sizeof(Operadores), 1, arq);
        printf("Operador Cadastrado com sucesso!\n");
    } else {
        printf("Erro ao abrir arquivo Binario!\n");
        exit(1);
    }
    fclose(arq);
}

/*
 * A funcao "VerificaOperadorBinario", abre o arquivo binario para leitura, carregando os dados na memoria,
 * e fazendo a verificacao se o Operador existe
 */
int VerificaOperadorBinario(Operadores *operador, int tam, char *nomeOperador, char *senhaOperador) {
    FILE *arq = fopen(ARQUIVO_BINARIO_OPERADOR, "rb");
    if (arq != NULL) {
        while (1) {
            size_t aux = fread(operador, sizeof(Operadores), tam, arq);
            if ((strcmp(operador->usuarioOperador, nomeOperador)) == 0 &&
                (strcmp(operador->senhaOperador, senhaOperador) == 0)) {
                printf("Login Realizado %s\n", nomeOperador);
                fclose(arq);
                return 1;
            }
            if (aux < 1) {
                printf("Operador incorreto ou inexistente!\n");
                break;
            }
            operador++;
        }
    } else {
        printf("Erro ao ler Operador!\n");
        exit(1);
    }
    return 0;
}

/*
 * A funcao "LerOperadorBinario", abre o arquivo binario para leitura, carregando os dados na memoria.
 */

void LerOperadorBinario(Operadores *operador, int tam) {
    FILE *arq = fopen(ARQUIVO_BINARIO_OPERADOR, "rb");
    if (arq != NULL) {
        while (1) {
            size_t aux = fread(operador, sizeof(Operadores), tam, arq);
            if (aux < 1) {
                break;
            }
        }
        operador++;
    } else {
        printf("Erro ao abrir arquivo Operador!\n");
        exit(1);
    }
    fclose(arq);
}

/*
 * A funcao "AlteraOperadorBinario" carrega os dados do operador com a funcao "LerOperadorBinario", e logo apos altera
 * seus dados de acordo com a opcao escolhida pelo usuario.
 */

void AlteraOperadorBinario(int cod, int opc, char *campo, int campoAux, int tam) {
    Operadores *operador = malloc(sizeof(Operadores) * (tam));
    LerOperadorBinario(operador, tam);

    for (int i = 0; i < tam; i++) {
        if (cod == operador[i].codOperador) {
            switch (opc) {
                case 1:
                    strcpy(operador[i].nomeOperador, campo);
                    break;
                case 2:
                    strcpy(operador[i].usuarioOperador, campo);
                    break;
                case 3:
                    strcpy(operador[i].senhaOperador, campo);
                    break;
                case 4:
                    operador[i].permissaoAcesso = campoAux;
                    break;
            }
        }
    }
    GravaOperadorBinario(operador);
}

void AlteraOperadorCadastro(Operadores *operador,int tam) {
    FILE *arq = fopen(ARQUIVO_BINARIO_OPERADOR, "wb");
    if (arq != NULL) {
        fwrite(operador, sizeof(Operadores)*(tam), 1, arq);
        fclose(arq);
    } else {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    printf("Operador alterado com sucesso!\n");

}

void DesativaOperador(int cod,int tam){
    Operadores *operador = malloc(sizeof(Operadores) * (tam));
    LerOperadorBinario(operador,tam);
    for(int i = 0; i < tam; i++){
        if(cod == operador[i].codOperador){
            operador[i].ativo = 0;
        }
    }
    AlteraOperadorCadastro(operador,tam);
}

