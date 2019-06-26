#include "Helper.h"

#define NOME_ARQUIVO_BINARIO_ULTIMO_CODIGO "DadosCodigo.bin"

int LerUltimosCodigos(int opc){
    Codigo *codigo;
    FILE *arq;
    codigo = malloc(sizeof(Codigo));
    arq = fopen(NOME_ARQUIVO_BINARIO_ULTIMO_CODIGO, "rb");
    if(arq != NULL){
        fread(codigo, sizeof(Codigo),1,arq);
    }
    else
    {
        printf("Erro ao ler arquivo!\n");
        exit(1);
    }
    fclose(arq);
    switch (opc){
        case 1:
            return codigo->codigoHospede;
        case 2:
            return codigo->codigoFornecedor;
        case 3:
            return codigo->codigoOperador;
        case 4:
            return codigo->codigoAcomodacoes;
        case 5:
            return codigo->codigoCategoriaAcomodacoes;
        case 6:
            return codigo->codigoProduto;

    }

}

void CarregarCodigoBinario(Codigo *codigo){

    FILE *arq;
    arq = fopen(NOME_ARQUIVO_BINARIO_ULTIMO_CODIGO,"rb");
    if(arq != NULL){
        fread(codigo, sizeof(Codigo*),1,arq);

    }
    else{
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }
    fclose(arq);
}


void GravaUltimoCodigoBinario(int opc, Codigo *codigo){
    switch (opc){
        case 1:
            codigo->codigoHospede++;
            break;
        case 2:
            codigo->codigoFornecedor++;
            break;
        case 3:
            codigo->codigoOperador++;
            break;
        case 4:
            codigo->codigoAcomodacoes++;
            break;
        case 5:
            codigo->codigoCategoriaAcomodacoes++;
            break;
        case 6:
            codigo->codigoProduto++;
            break;
        case 0:
            codigo->codigoFornecedor = 0;
            codigo->codigoHospede = 0;
            codigo->codigoOperador = 0;
            codigo->codigoAcomodacoes = 0;
            codigo->codigoCategoriaAcomodacoes = 0;
            codigo->codigoProduto = 0;
            break;
    }
    FILE *arq = fopen(NOME_ARQUIVO_BINARIO_ULTIMO_CODIGO,"wb");
    if(arq != NULL){
        fwrite(codigo, sizeof(Codigo),1,arq);
        fclose(arq);
    }
    else
        {
        printf("\nErro ao abrir arquivo!\n");
        fclose(arq);
        exit(1);

    }

}