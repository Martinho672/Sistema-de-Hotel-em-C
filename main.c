#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


#include "Operacaohospede.h"
#include "OperacaoFornecedores.h"
#include "OperacaoOperadores.h"
#include "OperacaoHotel.h"
#include "OperacaoAcomodacoes.h"
#include "OperacaoCategoriaAcomodacoes.h"
#include "OperacaoProdutos.h"
#include "operacaoReserva.h"

//Variavel responsavel pelo controle do modo de operacao do sistema
int modo;

char *aux;

Codigo *codigo;

Hotel *hotel;

Reserva *reserva;

Hospede *hospede;

Operadores *operador;

Operadores *operadorLogado;

Fornecedores *fornecedores;

Acomodacoes *acomodacoes;

CategoriaAcomodacoes *categoriaAcomodacoes;

Produto *produto;

void verificarAcomodacao();

int menuGerenciamentoDados();

int menuReservas();

int menuHotel();

int menuHospedes();

int menuFornecedores();

int menuOperadores();

int menuAcomodacoes();

int menuPrincipal();

int menuCategoriaAcomodacoes();

int menuProdutos();

void fazerReserva();

void cadastrarFornecedor();

void cadastrarHospede();

void cadastrarOperador();

void cadastrarAcomodacao();

void cadastrarCategoriaAcomodacoes();

void cadastrarProduto();

void listarHospede();

void listarFornecedores();

void listarOperadores();

void listarAcomodacoes();

void listarCategoriaAcomodacoes();

void listarProdutos();

void buscarHospede();

void buscarFornecedor();

void buscarOperador();

void buscarAcomodacao();

void buscarCategoriaAcomodacoes();

void buscarProduto();

void alterarHotel();

void alterarHospede();

void alterarFornecedor();

void alterarOperador();

void alterarAcomodacao();

void alterarCategoriaAcomodacoes();

void alterarProduto();

void DesativarHospede();

void DesativarFornecedor();

void DesativarOperador();

void DesativarAcomodacao();

void DesativarCategoriaAcomodacao();

void DesativarProduto();

void listarReserva();

void TelaLimpa() {
#ifdef _WIN32
# define CLEAR_SCREEN system ("cls")
#else
# define CLEAR_SCREEN puts("\x1b[H\x1b[2J")
#endif
}

int main(void) {

    printf("Digite o modo que deseja acessar o sistema\n1- Memoria\t2- Texto\t3- Binário\n");
    scanf("%d", &modo);

    hotel = malloc(sizeof(Hotel));
    codigo = malloc(sizeof(Codigo));
    operadorLogado = malloc(sizeof(Operadores));


    switch (modo) {
        case 1:
            hospede = malloc(sizeof(Hospede));
            fornecedores = malloc(sizeof(Fornecedores));
            acomodacoes = malloc(sizeof(Acomodacoes));
            categoriaAcomodacoes = malloc(sizeof(CategoriaAcomodacoes));
            produto = malloc(sizeof(Produto));
            hotel->numeroHotel = 0;
            break;
        case 2:
            break;
        case 3:
            LerArquivohotel(hotel);
            break;
    }


    if (hotel->numeroHotel == 0) {

        printf("Primeiro Acesso!\n");
        printf("Cadastre o Hotel\n");
        printf("Digite o nome do hotel:\n");
        scanf(" %[^\n]s", hotel->nome);
        printf("Digite a Razao social:\n");
        scanf(" %[^\n]s", hotel->razaoSocial);
        printf("Inscricao estadual:\n");
        scanf(" %[^\n]s", hotel->inscricaoEstadual);
        printf("CNPJ:\n");
        scanf(" %[^\n]s", hotel->CNPJ);
        printf("Digite o endereco separadamente a seguir!\n");
        printf("Estado:\n");
        scanf(" %[^\n]s", hotel->estado);
        printf("Cidade:\n");
        scanf(" %[^\n]s", hotel->cidade);
        printf("Bairro:\n");
        scanf(" %[^\n]s", hotel->bairro);
        printf("Rua:\n");
        scanf(" %[^\n]s", hotel->rua);
        printf("Numero:\n");
        scanf(" %[^\n]s", hotel->numero);
        printf("Digite a margem de lucro desejada para os produtos\n");
        scanf("%d", &hotel->lucro);
        printf("Digite o Horario para Checkin:\n");
        scanf(" %[^\n]s", hotel->checkin);
        printf("Digite o Horario para Checkout:\n");
        scanf(" %[^\n]s", hotel->checkout);

        switch (modo) {
            case 2:
                break;
            case 3:
                hotel->numeroHotel = 1;
                CadastraHotel(hotel);
                GravaUltimoCodigoBinario(0, codigo);
                break;
        }
        TelaLimpa();

        printf("Cadastre o Primeior Operador do sistema:\n");
        printf("Informe o nome: \n");
        scanf(" %[^\n]s", operadorLogado->nomeOperador);
        printf("Informe o nome de usuario: \n");
        scanf(" %[^\n]s", operadorLogado->usuarioOperador);
        printf("Informe a senha:\n");
        scanf(" %[^\n]s", operadorLogado->senhaOperador);
        printf("Informe o nivel de permissao do operador:\n");
        scanf(" %d", &operadorLogado->permissaoAcesso);

        switch (modo) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                GravaUltimoCodigoBinario(3, codigo);
                GravaOperadorBinario(operadorLogado);
                break;
        }
        operadorLogado->codOperador = LerUltimosCodigos(3);


    } else {
        char *usuario, *senha;
        int check;
        usuario = malloc(sizeof(char) * 10);
        senha = malloc(sizeof(char) * 10);
        switch (modo) {
            case 2:
                break;
            case 3:
                CarregarCodigoBinario(codigo);
                break;
        }


        do {
            printf("Digite seu Login:\n");
            scanf(" %[^\n]s", usuario);
            printf("Digite sua senha:\n");
            scanf(" %[^\n]s", senha);
            check = VerificaOperadorBinario(operadorLogado, codigo->codigoOperador + 1, usuario, senha);

        } while (check == 0);
    }
    TelaLimpa();
    menuPrincipal();

    return 0;
}

int menuGerenciamentoDados() {
    int op;

    printf("Menu - Gerenciamento de Dados\n");
    printf("1 - Hospedes\n2 - Acomodações\n3 - Categoria de Acomodações\n4 - Produtos \n5 - Fornecedores\n6 - Operadores do Sistema\n7 - Transacoes\n8 - Hotel\n0 - Voltar\n");
    scanf("%d", &op);
    switch (op) {
        case 1:
            menuHospedes();
            break;
        case 2:
            menuAcomodacoes();
            break;
        case 3:
            menuCategoriaAcomodacoes();
            break;
        case 4:
            menuProdutos();
            break;
        case 5:
            menuFornecedores();
            break;
        case 6:
            menuOperadores();
            break;
        case 7:
            break;
        case 8:
            menuHotel();
            break;
        case 0:
            menuPrincipal();
    }
}

int menuReservas(){

    int op;
    printf("1 - Verificar/Fazer Reserva\n2 - Cancelar Reserva\n3 - Listar Reserva\n0 - Voltar\n");
    scanf("%d",&op);
    switch (op){
        case 1:
            verificarAcomodacao();
            break;
        case 2:
            //cancelarReserva();
            break;
        case 3:
            listarReserva();
            break;
        case 0:
            menuPrincipal();
            break;
    }
}

int menuPrincipal() {
    int op;
    printf("Menu - Principal\n");
    printf("1 - Gerenciamento de Dados\n2 - Reservas\n3 - Transacoes\n4 - FeedBack\n5 - Importacao/Exportacao de dados\n0 - Fechar programa\n");
    scanf("%d", &op);

    switch (op) {
        case 1:
            menuGerenciamentoDados();
            break;
        case 2:
            menuReservas();
            break;
        case 0:
            exit(1);
    }
}

int menuHotel() {
    int op;
    printf("MENU - HOTEL\n");
    printf("1 - Mostrar cadastro Hotel\n2 - Alterar Hotel\n0 - Voltar\n");
    scanf("%d", &op);

    switch (op) {
        case 1:
            printf("Nome do hotel: %s\n", hotel->nome);
            printf("Razao social: %s\n", hotel->razaoSocial);
            printf("Inscricao estadual: %s\n", hotel->inscricaoEstadual);
            printf("CNPJ: %s\n", hotel->CNPJ);
            printf("Estado: %s\n", hotel->estado);
            printf("Cidade: %s\n", hotel->cidade);
            printf("Bairro: %s\n", hotel->bairro);
            printf("Rua: %s\n", hotel->rua);
            printf("Numero: %s\n", hotel->numero);
            printf("Lucro produtos: %d\n", hotel->lucro);
            printf("Horario para Checkin: %s\n", hotel->checkin);
            printf("Horario para Checkout: %s\n", hotel->checkout);
            do {
                printf("Voltar para o menu anterior(1) / Menu Principal(2)\n");
                scanf("%d", &op);
                if (op == 1) {
                    menuHotel();
                }
                if (op == 2) {
                    menuPrincipal();
                }
                if (op != 1 && op != 2) {
                    printf("Opcao invalida!\n");
                }

            } while (op != 1 && op != 2);
        case 2:
            alterarHotel();
            break;
        case 0:
            menuGerenciamentoDados();
            break;
    }
}

int menuHospedes(void) {

    int opcao;
    do {
        TelaLimpa();
        printf("MENU - HOSPEDES\n");
        printf("1 - Cadastrar\n2 - Listar\n3 - Alterar Cadastro\n4 - Buscar\n5 - Excluir\n0 - Voltar\n");
        printf("Digite sua opcao:\n");
        scanf("%d", &opcao);
        if ((opcao < 0) || (opcao > 5)) {
            printf("Opcao invalida!!!!!\n");
        }
        do {
            switch (opcao) {

                case 1:
                    printf("Cadastrar Hospede\n");
                    cadastrarHospede();
                    break;
                case 2:
                    printf("Listar Hospede\n");
                    listarHospede();
                    break;
                case 3:
                    printf("Alterar Hospede\n");
                    alterarHospede();
                    break;
                case 4:
                    printf("Buscar Hospede\n");
                    buscarHospede();
                    break;
                case 5:
                    printf("Excluir Hospede\n");
                    DesativarHospede();
                    break;
            };
        } while ((opcao < 0 || opcao > 5));
        menuGerenciamentoDados();
    } while ((opcao < 0 || opcao > 5));

}

int menuFornecedores(void) {
    int opcao;
    do {
        TelaLimpa();
        printf("MENU - FORNECEDORES\n");
        printf("1 - Cadastrar Fornecedor\n2 - Listar Fornecedores\n3 - Alterar Cadastro Fornecedor\n4 - Buscar Fornecedor\n5 - Excluir Fornecedor\n0 - Voltar\n");
        printf("Digite sua opcao:\n");
        scanf("%d", &opcao);
        if ((opcao < 0) || (opcao > 5)) {
            printf("Opcao invalida!!!!!\n");
        }
        do {
            switch (opcao) {
                case 1:
                    printf("1 - Cadastrar Fornecedor!\n");
                    cadastrarFornecedor();
                    break;
                case 2:
                    printf("2 - Listar Fornecedores!\n");
                    listarFornecedores();
                    break;
                case 3:
                    printf("3 - Alterar Dados Fornecedor!\n");
                    alterarFornecedor();
                    break;
                case 4:
                    printf("4 - Buscar Fornecedor!\n");
                    buscarFornecedor();
                    break;
                case 5:
                    printf("5 - Excluir Fornecedor!\n");
                    DesativarFornecedor();
                    break;
            }

        } while ((opcao < 0) || (opcao > 5));
        menuGerenciamentoDados();
    } while ((opcao < 0) || (opcao > 5));

}

int menuOperadores() {
    int opcao;

    do {
        TelaLimpa();
        printf("MENU - OPERADORES SISTEMA\n");
        printf("1 - Cadastrar Operador\n2 - Listar Operadores\n3 - Alterar Cadastro Operador\n4 - Buscar Operador\n0 - Voltar\n");
        printf("Digite sua opcao:\n");
        scanf("%d", &opcao);
        if (opcao < 0 || opcao > 4) {
            printf("Opcao Invalida!\n");
        }
        do {
            switch (opcao) {
                case 1:
                    printf("Cadastrar Operador\n");
                    cadastrarOperador();
                    break;
                case 2:
                    printf("Listar Operadores\n");
                    listarOperadores();
                    break;
                case 3:
                    printf("Alterar Cadastro Operador\n");
                    alterarOperador();
                    break;
                case 4:
                    printf("Buscar Operador\n");
                    buscarOperador();
                    break;
            }

        } while (opcao < 0 || opcao > 5);
        menuGerenciamentoDados();
    } while (opcao < 0 || opcao > 5);

}

int menuAcomodacoes() {

    int opcao;

    do {
        TelaLimpa();
        printf("MENU - ACOMODACOES\n");
        printf("1 - Cadastrar Acomodacao\n2 - Listar Acomodacoes\n3 - Alterar Acomodacao\n4 - Buscar Acomodacao\n5 - Desativar Acomodacao\n0 - Voltar\n");
        printf("Digite sua opcao:\n");
        scanf("%d", &opcao);

        if (opcao < 0 || opcao > 5) {
            printf("Opcao invalida\n");
        }

        do {
            switch (opcao) {
                case 1:
                    cadastrarAcomodacao();
                    break;
                case 2:
                    listarAcomodacoes();
                    break;
                case 3:
                    alterarAcomodacao();
                    break;
                case 4:
                    buscarAcomodacao();
                    break;
                case 5:
                    DesativarAcomodacao();
                    break;
            }
        } while (opcao < 0 || opcao > 5);
        menuGerenciamentoDados();
    } while (opcao < 0 || opcao > 5);

}

int menuCategoriaAcomodacoes() {
    int opcao;

    do {
        TelaLimpa();
        printf("MENU - CATEGORIA ACOMODACOES\n");
        printf("1 - Cadastrar Categoria Acomodacao\n2 - Listar Categorias\n3 - Alterar Categorias\n4 - Buscar Categorias\n5 - Desativar Categorias\n0 - Voltar\n");
        printf("Digite sua opcao:\n");
        scanf("%d", &opcao);

        if (opcao < 0 || opcao > 5) {
            printf("Opcao invalida\n");
        }
        do {
            switch (opcao) {
                case 1:
                    cadastrarCategoriaAcomodacoes();
                    break;
                case 2:
                    listarCategoriaAcomodacoes();
                    break;
                case 3:
                    alterarCategoriaAcomodacoes();
                    break;
                case 4:
                    buscarCategoriaAcomodacoes();
                    break;
                case 5:
                    DesativarCategoriaAcomodacao();
                    break;
            }
        } while (opcao < 0 || opcao > 5);
        menuGerenciamentoDados();
    } while (opcao < 0 || opcao > 5);

}

int menuProdutos() {
    int opcao;

    do {
        TelaLimpa();
        printf("MENU - PRODUTOS\n");
        printf("1 - Cadastrar Novo Produto\n2 - Listar Produtos\n3 - Alterar Produto\n4 - Buscar Produto\n5 - Desativar Produto\n0 - Voltar\n");
        printf("Digite sua opcao:\n");
        scanf("%d", &opcao);

        if (opcao < 0 || opcao > 5) {
            printf("Opcao invalida\n");
        }
        do {
            switch (opcao) {
                case 1:
                    cadastrarProduto();
                    break;
                case 2:
                    listarProdutos();
                    break;
                case 3:
                    alterarProduto();
                    break;
                case 4:
                    buscarProduto();
                    break;
                case 5:
                    DesativarProduto();
                    break;
            }
        } while (opcao < 0 || opcao > 5);
        menuGerenciamentoDados();
    } while (opcao < 0 || opcao > 5);


}

void verificarAcomodacao(){
    reserva = malloc(sizeof(Reserva));
    char mais;
    int op, filtro, opFiltro, tam;
    acomodacoes = malloc(sizeof(Acomodacoes) * (codigo->codigoAcomodacoes + 1));

    switch (modo) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            LerArquivoBinarioAcomodacoes(acomodacoes, codigo->codigoAcomodacoes);
            break;
    }

    printf("Deseja adicionar algum filtro a listagem (1 - SIM - 0 - NAO) ?\n");
    scanf("%d", &filtro);

    if (filtro == 1) {//SIM
        printf("1 - Faixa de codigo\t2 - Categoria\t3 - Data disponivel\n");
        scanf("%d", &opFiltro);
        if (opFiltro == 1) {
            int a = 0, b = 0;

            for (int i = a; i <= b; i++) {//Faixa de codigo
                if (acomodacoes[i].ativo == 1) {
                    printf("Acomodacao: %d\n", acomodacoes[i].codAcomodacao);
                    printf("Descricao: %s\n", acomodacoes[i].descricao);
                    printf("Facilidades: %s\n", acomodacoes[i].facilidades);
                    printf("Categoria: %s\n", acomodacoes[i].categoria);
                    printf("Disponivel: ");
                    if(acomodacoes[i].disponivel == 1){
                        printf("Sim\n");
                    }
                    else{
                        printf("Nao\n");
                    }
                    printf("\n\n");
                }
            }
            printf("Deseja fazer uma reserva ?(1 - SIM / 0 - NAO)\n");
            scanf("%d",&op);

            switch (op){
                case 1:
                    fazerReserva();
                    break;
                case 0:
                    menuReservas();
                    break;
            }
        }
        if (opFiltro == 2) {//Categoria
            char auxCategoria[15];
            printf("Digite o nome da categoria:\n");
            scanf(" %[^\n]s", auxCategoria);

            for (int i = 0; i <= codigo->codigoAcomodacoes; ++i) {
                if ((strcmp(acomodacoes[i].categoria, auxCategoria)) == 0) {
                    printf("Acomodacao: %d\n", acomodacoes[i].codAcomodacao);
                    printf("Descricao: %s\n", acomodacoes[i].descricao);
                    printf("Facilidades: %s\n", acomodacoes[i].facilidades);
                    printf("Categoria: %s\n", acomodacoes[i].categoria);
                    printf("Disponivel: ");
                    if(acomodacoes[i].disponivel == 1){
                        printf("Sim\n");
                    }
                    else{
                        printf("Nao\n");
                    }
                    printf("\n\n");
                }
            }
        } else {//Data

        }
    } else {//Sem Filtro
        for (int i = 0; i <= codigo->codigoAcomodacoes; i++) {
            if (acomodacoes[i].ativo == 1) {
                printf("Acomodacao: %d\n", acomodacoes[i].codAcomodacao);
                printf("Descricao: %s\n", acomodacoes[i].descricao);
                printf("Facilidades: %s\n", acomodacoes[i].facilidades);
                printf("Categoria: %s\n", acomodacoes[i].categoria);
                printf("Disponivel: ");
                if(acomodacoes[i].disponivel == 1){
                    printf("Sim\n");
                }
                else{
                    printf("Nao\n");
                }
                printf("\n\n");
            }
        }
    }


}

void fazerReserva(){
    int op,cod,hospedeCod;

    acomodacoes = malloc(sizeof(Acomodacoes) * (codigo->codigoAcomodacoes + 1));

    printf("Digite o codigo da acomodacao que deseja reservar:\n");
    scanf("%d",&cod);

    printf("Digite o codigo do Hospede para reserva:\n");
    scanf("%d",&hospedeCod);

    fazReserva(cod,codigo->codigoAcomodacoes + 1,hospedeCod);

    menuReservas();

}

void listarReserva(){


}

void cadastrarFornecedor() {
    fornecedores = malloc(sizeof(Fornecedores));
    int CadastrarMais = 0;
    do {
        printf("Digite os dados do Fornecedor a seguir:\n");
        printf("Nome Fantasia:\n");
        scanf(" %[^\n]s", fornecedores->nomeFantasiaFornecedor);
        printf("Razao Social:\n");
        scanf(" %[^\n]s", fornecedores->razaoSocialFornecedor);
        printf("Inscricao Estadual:\n");
        scanf(" %[^\n]s", fornecedores->inscricaoEstadualFornecedor);
        printf("CNPJ:\n");
        scanf(" %[^\n]s", fornecedores->cnpjFornecedor);
        printf("Telefone:\n");
        scanf(" %[^\n]s", fornecedores->telefoneFornecedor);
        printf("Email:\n");
        scanf(" %[^\n]s", fornecedores->emailFornecedor);
        printf("A seguir digite o endereco\n");
        printf("\nEstado:\n");
        scanf(" %[^\n]s", fornecedores->estadoFornecedor);
        printf("Cidade:\n");
        scanf(" %[^\n]s", fornecedores->cidadeFornecedor);
        printf("Bairro:\n");
        scanf(" %[^\n]s", fornecedores->bairroFornecedor);
        printf("Rua:\n");
        scanf(" %[^\n]s", fornecedores->ruaFornecedor);
        printf("Numero:\n");
        scanf(" %[^\n]s", fornecedores->numeroFornecedor);
        fornecedores->ativo = 1;
        printf("Fornecedor cadastrado com sucesso!\n");
        printf("Deseja cadastrar mais ? (sim - 1 / nao - 0)\n");
        scanf(" %d", &CadastrarMais);

        switch (modo) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                GravaUltimoCodigoBinario(2, codigo);
                fornecedores->codFornecedor = LerUltimosCodigos(2);
                CadastraFornecedores(fornecedores);
                break;
        }


    } while (CadastrarMais == 1);
    menuFornecedores();
}

void cadastrarHospede() {
    hospede = malloc(sizeof(Hospede));
    int CadastrarMais = 0;
    do {
        printf("Cadastrar Hospede\n");
        printf("Digite os dados a seguir:\n");
        printf("Nome:");
        scanf(" %[^\n]s", hospede->nome);
        printf("\nCPF: ");
        scanf(" %[^\n]s", hospede->CPF);
        printf("\nEmail: ");
        scanf(" %[^\n]s", hospede->email);
        printf("\nTelefone: ");
        scanf(" %[^\n]s", hospede->telefone);
        printf("\nData de Nascimento(01/01/1901): ");
        scanf(" %[^\n]s", hospede->dataNascimento);
        printf("\nEstado Civil: ");
        scanf(" %[^\n]s", hospede->estadoCivil);
        printf("\nSexo (1 - Masculino/0 - Feminino):\t");
        scanf(" %d", &hospede->sexo);
        printf("Digite o Endereco a seguir:\n");
        printf("Estado: ");
        scanf(" %[^\n]s", hospede->estado);
        printf("\nCidade: ");
        scanf(" %[^\n]s", hospede->cidade);
        printf("\nBairro: ");
        scanf(" %[^\n]s", hospede->bairro);
        printf("\nRua: ");
        scanf(" %[^\n]s", hospede->rua);
        printf("\nNumero: ");
        scanf(" %[^\n]s", hospede->numero);
        hospede->ativo = 1;
        printf("Hospede Cadastrado com Sucesso!\n");
        printf("Deseja cadastrar mais ? Sim(1) Nao(0)");
        scanf("%d", &CadastrarMais);

        switch (modo) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                GravaUltimoCodigoBinario(1, codigo);
                hospede->codHospede = codigo->codigoHospede;
                CadastraHospede(hospede);
                break;
        }

    } while (CadastrarMais == 1);
    menuHospedes();
}

void cadastrarOperador() {
    operador = malloc(sizeof(Operadores));
    int CadastrarMais = 0;
    do {
        printf("Nome:\n");
        scanf(" %[^\n]s", operador->nomeOperador);
        printf("Nome de Usuario:\n");
        scanf(" %[^\n]s", operador->usuarioOperador);
        printf("Senha:");
        scanf(" %[^\n]s", operador->senhaOperador);
        printf("Permissao de acesso:\n");// A definir modelos de permissao de acesso/*
        scanf("%d", &operador->permissaoAcesso);
        operador->ativo = 1;
        printf("Operador Cadastrado com Sucesso!!\n");
        printf("Deseja cadastrar mais ? SIM(1) NAO(0)\n");
        scanf("%d", &CadastrarMais);

        switch (modo) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                GravaUltimoCodigoBinario(3, codigo);
                operador->codOperador = codigo->codigoOperador;
                GravaOperadorBinario(operador);
                break;
        }

    } while (CadastrarMais == 1);
    menuOperadores();
}

void cadastrarAcomodacao() {
    acomodacoes = malloc(sizeof(Acomodacoes));
    char mais;
    do {
        printf("Cadastrar Acomodacao\n");
        printf("Digite os dados a seguir!\n");
        printf("Descricao:\n");
        scanf(" %[^\n]s", acomodacoes->descricao);
        printf("Facilidades:\n");
        scanf(" %[^\n]s", acomodacoes->facilidades);
        printf("Categoria:\n");
        scanf(" %s", acomodacoes->categoria);
        acomodacoes->ativo = 1;
        printf("Acomodacao Cadastrada com sucesso!\n");
        printf("Deseja Cadastrar mais [s/n] ?\n");
        scanf("%s", &mais);

        switch (modo) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                GravaUltimoCodigoBinario(4, codigo);
                acomodacoes->codAcomodacao = codigo->codigoAcomodacoes;
                GravaArquivoBinarioAcomodacoes(acomodacoes);
                break;
        }

    } while (mais == 's' || mais == 'S');
    menuAcomodacoes();
}

void cadastrarCategoriaAcomodacoes() {
    categoriaAcomodacoes = malloc(sizeof(CategoriaAcomodacoes));
    char mais;
    do {
        printf("Cadastrar Categoria de Acomodacao\n");
        printf("Digite os dados a seguir\n");
        printf("Descricao da categoria:\n");
        scanf(" %[^\n]s", categoriaAcomodacoes->descricaoCategoria);
        printf("Quantidade de pessoas suportadas:\n");
        scanf("%d", &categoriaAcomodacoes->qntPessoas);
        printf("Valor diaria:\n");
        scanf(" %f", &categoriaAcomodacoes->valorDiaria);
        printf("Categoria de acomodacao cadastrada com sucesso!\n");
        printf("Deseja cadastrar mais [s/n]?\n");
        scanf("%s", &mais);

        switch (modo) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                GravaUltimoCodigoBinario(5, codigo);
                categoriaAcomodacoes->codCategoriaAcomodacoes = codigo->codigoCategoriaAcomodacoes;
                GravaArquivoBinarioCategoriaAcomodacoes(categoriaAcomodacoes);
                break;
        }

    } while (mais == 's' || mais == 'S');
    menuCategoriaAcomodacoes();
}

void cadastrarProduto() {
    produto = malloc(sizeof(Produto));
    char mais;

    do {
        printf("Cadastrar Produto\n");
        printf("Digite os dados a seguir:\n");
        printf("Descricao produto:\n");
        scanf(" %[^\n]s", produto->descricao);
        printf("Estoque:\n");
        scanf("%d", &produto->estoque);
        printf("Estoque Minimo:\n");
        scanf("%d", &produto->estoqueMinimo);
        printf("Preco de Custo:\n");
        scanf("%f", &produto->precoCusto);
        printf("Preco de Venda:\n");
        scanf("%f", &produto->precoVenda);
        produto->ativo = 1;
        printf("Produto cadastrado com sucesso!\n");
        printf("Deseja cadastrar mais [s/n] ?\n");
        scanf("%s", &mais);

        switch (modo) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                GravaUltimoCodigoBinario(6, codigo);
                produto->codProduto = codigo->codigoProduto;
                GravaArquivoProduto(produto);
                break;
        }


    } while (mais == 's' || mais == 'S');
    menuProdutos();
}

void listarFornecedores() {
    CarregarCodigoBinario(codigo);
    fornecedores = malloc(sizeof(Fornecedores) * (codigo->codigoFornecedor + 1));
    LerUltimosCodigos(2);
    LerArquivoFornecedores(fornecedores, codigo->codigoFornecedor + 1);
    int op;

    for (int i = 0; i <= codigo->codigoFornecedor; i++) {
        if (fornecedores[i].codFornecedor > 0 && fornecedores[i].ativo == 1) {
            printf("Codigo Fornecedor: %d\n", fornecedores[i].codFornecedor);
            printf("Nome Fantasia: %s\n", fornecedores[i].nomeFantasiaFornecedor);
            printf("Razao Social: %s\n", fornecedores[i].razaoSocialFornecedor);
            printf("Inscricao estadual: %s\n", fornecedores[i].inscricaoEstadualFornecedor);
            printf("CNPJ: %s\n", fornecedores[i].cnpjFornecedor);
            printf("Telefone: %s\n", fornecedores[i].telefoneFornecedor);
            printf("Email: %s\n", fornecedores[i].emailFornecedor);
            printf("Endereco %s, %s, Bairro %s, Rua %s, numero %s\n", fornecedores[i].estadoFornecedor,
                   fornecedores[i].cidadeFornecedor, fornecedores[i].bairroFornecedor,
                   fornecedores[i].ruaFornecedor,
                   fornecedores[i].numeroFornecedor);
            printf("\n\n");
        }
    }
    do {
        printf("Voltar para o menu anterior(1) / Menu Principal(2)\n");
        scanf("%d", &op);
        if (op == 1) {
            menuFornecedores();
        }
        if (op == 2) {
            menuPrincipal();
        }
        if (op != 1 && op != 2) {
            printf("Opcao invalida!\n");
        }

    } while (op != 1 && op != 2);


}

void listarHospede() {
    hospede = malloc(sizeof(Hospede) * (codigo->codigoHospede + 1));

    switch (modo) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            LerArquivoHospede(hospede, codigo->codigoHospede);
            break;
    }

    int op, filtroSexo, filtro, opFiltro, tam;

    printf("Deseja adicionar algum filtro a listagem (1 - SIM - 0 - NAO) ?\n");
    scanf("%d", &filtro);

    if (filtro == 1) {
        printf("Escolha o tipo de Filtro:\n");
        printf("1 - Faixa de codigo\t2 - Sexo\n");
        scanf("%d", &opFiltro);
        if (opFiltro == 1) {
            int a = 0, b = 0;

            printf("Digite o numero correspondente ao codigo inicial:\n");
            scanf("%d", &a);
            printf("Digite o numero correspondente ao codigo final:\n");
            scanf("%d", &b);

            for (int i = a; i <= b; i++) {
                if (hospede[i].ativo == 1) {
                    printf("Codigo Hospede:%d\n", hospede[i].codHospede);
                    printf("Nome: %s\n", hospede[i].nome);
                    printf("CPF: %s\n", hospede[i].CPF);
                    printf("Email: %s\n", hospede[i].email);
                    printf("Data Nascimento: %s\n", hospede[i].dataNascimento);
                    printf("Sexo : ");
                    if (hospede[i].sexo == 1) {
                        printf("Masculino\n");
                    }
                    if (hospede[i].sexo == 0) {
                        printf("Feminino\n");
                    }
                    printf("Estado civil: %s\n", hospede[i].estadoCivil);
                    printf("Endereco:\n");
                    printf("Estado: %s\n", hospede[i].estado);
                    printf("Cidade:%s\n", hospede[i].cidade);
                    printf("Bairro: %s\n", hospede[i].bairro);
                    printf("Rua: %s\n", hospede[i].rua);
                    printf("Numero: %s\n", hospede[i].numero);
                }
            }
        } else { //Filtro Sexo
            printf("1 - Listar sexo Masculino\t2 - Listar sexo Feminino\n");
            scanf("%d", &filtroSexo);

            if (filtroSexo == 1) {// Masculino
                for (int i = 0; i <= codigo->codigoHospede; i++) {
                    if (hospede[i].sexo == 1 && hospede[i].ativo == 1) {
                        printf("Codigo Hospede:%d\n", hospede[i].codHospede);
                        printf("Nome: %s\n", hospede[i].nome);
                        printf("CPF: %s\n", hospede[i].CPF);
                        printf("Email: %s\n", hospede[i].email);
                        printf("Data Nascimento: %s\n", hospede[i].dataNascimento);
                        printf("Sexo : ");
                        if (hospede[i].sexo == 1) {
                            printf("Masculino\n");
                        }
                        if (hospede[i].sexo == 0) {
                            printf("Feminino\n");
                        }
                        printf("Estado civil: %s\n", hospede[i].estadoCivil);
                        printf("Endereco:\n");
                        printf("Estado: %s\n", hospede[i].estado);
                        printf("Cidade:%s\n", hospede[i].cidade);
                        printf("Bairro: %s\n", hospede[i].bairro);
                        printf("Rua: %s\n", hospede[i].rua);
                        printf("Numero: %s\n", hospede[i].numero);
                        printf("\n\n");
                        break;
                    }
                }
            }
            if (filtroSexo == 2) {// Feminino
                for (int (i) = 0; (i) <= codigo->codigoHospede; ++(i)) {
                    if (hospede[i].ativo == 1 && hospede[i].sexo == 0) {
                        printf("Codigo Hospede:%d\n", hospede[i].codHospede);
                        printf("Nome: %s\n", hospede[i].nome);
                        printf("CPF: %s\n", hospede[i].CPF);
                        printf("Email: %s\n", hospede[i].email);
                        printf("Data Nascimento: %s\n", hospede[i].dataNascimento);
                        printf("Sexo : ");
                        if (hospede[i].sexo == 1) {
                            printf("Masculino\n");
                        }
                        if (hospede[i].sexo == 0) {
                            printf("Feminino\n");
                        }
                        printf("Estado civil: %s\n", hospede[i].estadoCivil);
                        printf("Endereco:\n");
                        printf("Estado: %s\n", hospede[i].estado);
                        printf("Cidade:%s\n", hospede[i].cidade);
                        printf("Bairro: %s\n", hospede[i].bairro);
                        printf("Rua: %s\n", hospede[i].rua);
                        printf("Numero: %s\n", hospede[i].numero);
                        printf("\n\n");
                    }

                }
            }
        }
    } else {//Listagem sem Filtro
        for (int i = 0; i <= codigo->codigoHospede; i++) {
            if (hospede[i].ativo == 1) {
                if (hospede[i].ativo == 1) {
                    printf("Codigo Hospede:%d\n", hospede[i].codHospede);
                    printf("Nome: %s\n", hospede[i].nome);
                    printf("CPF: %s\n", hospede[i].CPF);
                    printf("Email: %s\n", hospede[i].email);
                    printf("Data Nascimento: %s\n", hospede[i].dataNascimento);
                    printf("Sexo : ");
                    if (hospede[i].sexo == 1) {
                        printf("Masculino\n");
                    }
                    if (hospede[i].sexo == 0) {
                        printf("Feminino\n");
                    }
                    printf("Estado civil: %s\n", hospede[i].estadoCivil);
                    printf("Endereco:\n");
                    printf("Estado: %s\n", hospede[i].estado);
                    printf("Cidade:%s\n", hospede[i].cidade);
                    printf("Bairro: %s\n", hospede[i].bairro);
                    printf("Rua: %s\n", hospede[i].rua);
                    printf("Numero: %s\n", hospede[i].numero);
                    printf("\n\n");

                }
            }
        }

        do {
            printf("Voltar para o menu anterior(1) / Menu Principal(2)\n");
            scanf("%d", &op);
            if (op == 1) {
                menuHospedes();
            }
            if (op == 2) {
                menuPrincipal();
            }
            if (op != 1 && op != 2) {
                printf("Opcao invalida!\n");
            }

        } while (op != 1 && op != 2);

    }
}

void listarOperadores() {
    CarregarCodigoBinario(codigo);
    operador = malloc(sizeof(Operadores) * (codigo->codigoOperador + 1));
    LerUltimosCodigos(3);
    LerOperadorBinario(operador, codigo->codigoOperador + 1);

    int op;
    printf("Quantidade de Operadores do Sistema: %d\n", codigo->codigoOperador + 1);

    for (int i = 0; i <= codigo->codigoOperador; i++) {
        if (operadorLogado[i].codOperador > 0) {
            printf("Operador: %d\n", operador[i].codOperador);
            printf("Nome: %s\n", operador[i].nomeOperador);
            printf("Nome Usuario: %s\n", operador[i].usuarioOperador);
            printf("Nivel de Permissao: %d\n", operador[i].permissaoAcesso);
            printf("\n\n");
        }
    }
    printf("Voltar para o menu anterior(1) / Menu Principal(2)\n");
    scanf("%d", &op);
    if (op == 1) {
        menuOperadores();
    } else if (op == 0) {
        menuPrincipal();
    }
    if (op < 1 || op > 2) {
        printf("Opcao invalida retorna para o menu principal!\n");
        menuPrincipal();
    }

}

void listarAcomodacoes() {

    int op, filtro, opFiltro, tam;
    acomodacoes = malloc(sizeof(Acomodacoes) * (codigo->codigoAcomodacoes + 1));

    switch (modo) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            LerArquivoBinarioAcomodacoes(acomodacoes, codigo->codigoAcomodacoes);
            break;
    }

    printf("Deseja adicionar algum filtro a listagem (1 - SIM - 0 - NAO) ?\n");
    scanf("%d", &filtro);

    if (filtro == 1) {//SIM
        printf("1 - Faixa de codigo\t2 - Categoria\t3 - Data disponivel\n");
        scanf("%d", &opFiltro);
        if (opFiltro == 1) {
            int a = 0, b = 0;

            for (int i = a; i <= b; i++) {//Faixa de codigo
                if (acomodacoes[i].ativo == 1) {
                    printf("Acomodacao: %d\n", acomodacoes[i].codAcomodacao);
                    printf("Descricao: %s\n", acomodacoes[i].descricao);
                    printf("Facilidades: %s\n", acomodacoes[i].facilidades);
                    printf("Categoria: %s\n", acomodacoes[i].categoria);
                    printf("\n\n");
                }
            }
        }
        if (opFiltro == 2) {//Categoria
            char auxCategoria[15];
            printf("Digite o nome da categoria:\n");
            scanf(" %[^\n]s", auxCategoria);

            for (int i = 0; i <= codigo->codigoAcomodacoes; ++i) {
                if ((strcmp(acomodacoes[i].categoria, auxCategoria)) == 0) {
                    printf("Acomodacao: %d\n", acomodacoes[i].codAcomodacao);
                    printf("Descricao: %s\n", acomodacoes[i].descricao);
                    printf("Facilidades: %s\n", acomodacoes[i].facilidades);
                    printf("Categoria: %s\n", acomodacoes[i].categoria);
                    printf("\n\n");
                }
            }
        } else {//Data

        }
    } else {//Sem Filtro
        for (int i = 0; i <= codigo->codigoAcomodacoes; i++) {
            if (acomodacoes[i].ativo == 1) {
                printf("Acomodacao: %d\n", acomodacoes[i].codAcomodacao);
                printf("Descricao: %s\n", acomodacoes[i].descricao);
                printf("Facilidades: %s\n", acomodacoes[i].facilidades);
                printf("Categoria: %s\n", acomodacoes[i].categoria);
                printf("\n\n");
            }
        }
    }

    printf("Voltar para o menu anterior(1) / Menu Principal(2)\n");
    scanf("%d", &op);
    if (op != 1 && op != 2) {
        printf("Opcao invalida!\n");
        printf("Voltar para o menu anterior(1) / Menu Principal(2)\n");
        scanf("%d", &op);
    }
    if (op == 1) {
        menuAcomodacoes();
    }
    if (op == 2) {
        menuPrincipal();
    }

}

void listarCategoriaAcomodacoes() {
    CarregarCodigoBinario(codigo);
    categoriaAcomodacoes = malloc(sizeof(CategoriaAcomodacoes) * (codigo->codigoCategoriaAcomodacoes + 1));
    LerUltimosCodigos(5);
    LerArquivoBinarioCategoriaAcomodacoes(categoriaAcomodacoes, codigo->codigoCategoriaAcomodacoes + 1);

    int op;
    printf("Quantidade de categorias de Acomodacao: %d\n", codigo->codigoCategoriaAcomodacoes + 1);

    for (int i = 0; i <= codigo->codigoCategoriaAcomodacoes; i++) {
        printf("Codigo da Categoria: %d\n", categoriaAcomodacoes[i].codCategoriaAcomodacoes);
        printf("Descricao: %s\n", categoriaAcomodacoes[i].descricaoCategoria);
        printf("Quantidade de Hospedes suportada: %d\n", categoriaAcomodacoes[i].qntPessoas);
        printf("Valor da diaria: %.2f\n", categoriaAcomodacoes[i].valorDiaria);
        printf("\n\n");
    }

    printf("Voltar para o menu anterior(1) / Menu Principal(2)\n");
    scanf("%d", &op);
    if (op == 1) {
        menuCategoriaAcomodacoes();
    } else if (op == 0) {
        menuPrincipal();
    }
    if (op < 1 || op > 2) {
        printf("Opcao invalida retorna para o menu principal!\n");
        menuPrincipal();
    }
}

void listarProdutos() {

    produto = malloc(sizeof(Produto) * (codigo->codigoProduto + 1));
    switch (modo) {
        case 1:
            //memoria
            break;
        case 2:
            //arquivotexto
            break;
        case 3:
            LerArquivoProduto(produto, codigo->codigoProduto + 1);
            break;

    }

    int op, filtro, opFiltro;

    printf("Deseja utilizar algum filtro ? (1 - SIM/ 0 - NAO\n");
    scanf("%d", &filtro);

    if (filtro == 1) {
        int a = 0, b = 0;
        printf("Digite o numero correspondente ao codigo inicial:\n");
        scanf("%d", &a);
        printf("Digite o numero correspondente ao codigo final:\n");
        scanf("%d", &b);

        for (int i = 0; i <= b; i++) {
            if (produto[i].ativo == 1) {
                printf("Codigo do produto: %d\n", produto[i].codProduto);
                printf("Descricao: %s\n", produto[i].descricao);
                printf("Estoque Minimo: %d\n", produto[i].estoqueMinimo);
                printf("Descricao: %d\n", produto[i].estoque);
                printf("Preco de custo: %.2f\n", produto[i].precoCusto);
                printf("Descricao: %.2f\n", produto[i].precoVenda);
                printf("\n\n");
            }

        }
    } else {
        for (int i = 0; i <= codigo->codigoProduto; i++) {
            if (produto[i].codProduto > 0 && produto[i].ativo == 1) {
                printf("Codigo do produto: %d\n", produto[i].codProduto);
                printf("Descricao: %s\n", produto[i].descricao);
                printf("Estoque Minimo: %d\n", produto[i].estoqueMinimo);
                printf("Descricao: %d\n", produto[i].estoque);
                printf("Preco de custo: %.2f\n", produto[i].precoCusto);
                printf("Descricao: %.2f\n", produto[i].precoVenda);
                printf("\n\n");
            }
        }
    }

    do {
        printf("Voltar para o menu anterior(1) / Menu Principal(2)\n");
        scanf("%d", &op);
        if (op == 1) {
            menuProdutos();
        }
        if (op == 2) {
            menuPrincipal();
        }
        if (op != 1 && op != 2) {
            printf("Opcao invalida!\n");
        }

    } while (op != 1 && op != 2);
}

void alterarHospede() {
    int cod, op;

    free(aux);
    aux = realloc(aux, sizeof(char) * 200);
    hospede = malloc(sizeof(Hospede) * (codigo->codigoHospede + 1));
    switch (modo){
        case 1:
            //memoria
            break;
        case 2:
            //texto
            break;
        case 3:
            LerArquivoHospede(hospede, codigo->codigoHospede + 1);
            break;
    }


    printf("Hospedes:\n");
    for (int i = 0; i <= codigo->codigoHospede; i++) {
        if (hospede[i].ativo == 1) {
            printf("Hospede :%d, %s\n", hospede[i].codHospede, hospede[i].nome);
        }
    }


    printf("Digite o codigo do hospede que deseja alterar dados:\n");
    scanf("%d", &cod);
    for (int j = 0; j <= codigo->codigoHospede; j++) {
        if (hospede[j].codHospede == cod && hospede[j].ativo == 1) {

            printf("Qual dado deseja alterar ? \n");
            printf("1 - Nome\n2 - CPF\n3 - Email\n4 - Data Nascimento\n5 - Estado civil\n6 - Sexo\n7 - Endereco - Estado\n8 - Cidade\n9 - Bairro\n10 - Rua\n11 - Numero\n12 - Telefone\n0 - Voltar\n");
            scanf("%d", &op);

            switch (op) {

                case 1:
                    printf("Digite o nome :\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 2:
                    printf("Digite o CPF :\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 3:
                    printf("Digite o Email :\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 4:
                    printf("Digite o Data Nascimento :\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 5:
                    printf("Digite o Estado Civil :\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 6:
                    printf("Digite o Sexo :\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 7:
                    printf("Digite o Estado :\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 8:
                    printf("Digite a Cidade :\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 9:
                    printf("Digite o Bairro :\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 10:
                    printf("Digite a rua :\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 11:
                    printf("Digite o numero :\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 12:
                    printf("Digite o telefone:\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 0:
                    menuHospedes();
                    break;

            }
            switch (modo){
                case 1:
                    //memoria
                    break;
                case 2:
                    //texto
                    break;
                case 3:
                    AlteraHospede(codigo->codigoHospede + 1, op, cod, aux);
                    break;
            }

            menuHospedes();
        } else {
            printf("Hospede nao encontrado\n");
            menuHospedes();
        }
    }

}

void alterarFornecedor() {
    int cod, op;

    free(aux);
    aux = realloc(aux, sizeof(char) * 200);
    fornecedores = malloc(sizeof(Fornecedores) * (codigo->codigoFornecedor + 1));
    switch (modo){
        case 1:
            //memoria
            break;
        case 2:
            //texto
            break;
        case 3:
            LerArquivoFornecedores(fornecedores, codigo->codigoFornecedor + 1);
            break;
    }


    printf("Fornecedores:\n");
    for (int i = 0; i <= codigo->codigoFornecedor; i++) {
        if (fornecedores[i].codFornecedor > 0 && fornecedores[i].ativo == 1) {
            printf("Fornecedor :%d, %s\n", fornecedores[i].codFornecedor, fornecedores[i].nomeFantasiaFornecedor);
        }
    }

    printf("Digite o codigo do Fornecedor que deseja alterar dados:\n");
    scanf("%d", &cod);
    for (int j; j <= codigo->codigoFornecedor; j++) {
        if (fornecedores[j].codFornecedor == cod && fornecedores[j].ativo == 1) {

            printf("Qual dado deseja alterar ? \n");
            printf("1 - Nome Fantasia\n2 - Razao Social\n3 - Inscricao Estadual\n4 - CNPJ\n5 - Telefone\n6 - Email\n7 - Estado\n8 - Cidade\n9 - Bairro\n10 - Rua\n0 - Voltar");
            scanf("%d", &op);

            switch (op) {
                case 1:
                    printf("Nome Fantasia\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 2:
                    printf("Razao Social:\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 3:
                    printf("Inscricao Estadual:\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 4:
                    printf("CNPJ:\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 5:
                    printf("Telefone:\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 6:
                    printf("Email:\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 7:
                    printf("Estado:\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 8:
                    printf("Cidade:\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 9:
                    printf("Bairro:\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 10:
                    printf("Rua:\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 0:
                    menuFornecedores();
                    break;
            }
            switch (modo){
                case 1:
                    //memoria
                    break;
                case 2:
                    //texto
                    break;
                case 3:
                    AlteraFornecedoresBinario(cod, op, aux, codigo->codigoFornecedor + 1);
                    break;
            }
            menuFornecedores();
        } else {
            printf("Fornecedor nao encontrado !\n");
            menuFornecedores();
        }
    }
    free(aux);
}

void alterarHotel() {
    int op,Intaux;

    aux = realloc(aux, sizeof(char) * 200);
    hotel = malloc(sizeof(Hotel));
    switch (modo) {
        case 1:
            break;
        case 2:
            //texto
            break;
        case 3:
            LerArquivohotel(hotel);
            break;
    }
    printf("Qual dado deseja alterar ?\n");
    printf("1 - Nome Fantasia\n2 - Razao Social\n3 - Inscricao Estadual\n4 - CNPJ\n5 - Estado\n6 - Cidade\n7 - Bairro\n8 - Rua\n9 - Numero\n10 - Email\n11 - Nome do Gerente\n12 - Telefone Hotel\n13 - Telefone Gerente\n14 - Percentagem Lucro\n15 - Horario de Checkin\n16 - Horario de Checkout\n0 - Voltar");
    scanf("%d", &op);
    switch (op) {
        case 1:
            printf("Digite o Nome Fantasia:\n");
            scanf(" %[^\n]s", aux);
            break;
        case 2:
            printf("Digite a Razao Social:\n");
            scanf(" %[^\n]s", aux);
            break;
        case 3:
            printf("Digite Inscricao Estadual:\n");
            scanf(" %[^\n]s", aux);
            break;
        case 4:
            printf("Digite o CNPJ:\n");
            scanf(" %[^\n]s", aux);
            break;
        case 5:
            printf("Digite o Estado:\n");
            scanf(" %[^\n]s", aux);
            break;
        case 6:
            printf("Digite a Cidade:\n");
            scanf(" %[^\n]s", aux);
            break;
        case 7:
            printf("Digite o bairro:\n");
            scanf(" %[^\n]s", aux);
            break;
        case 8:
            printf("Digite a Rua:\n");
            scanf(" %[^\n]s", aux);
            break;
        case 9:
            printf("Digite o Numero:\n");
            scanf(" %[^\n]s", aux);
            break;
        case 10:
            printf("Digite o Email:\n");
            scanf(" %[^\n]s", aux);
            break;
        case 11:
            printf("Digite o Nome do Gerente\n");
            scanf(" %[^\n]s", aux);
            break;
        case 12:
            printf("Digite o telefone do Hotel:\n");
            scanf("%d",&Intaux);
            break;
        case 13:
            printf("Digite o telefone do Gerente:\n");
            scanf("%d",&Intaux);
            break;
        case 14:
            printf("Digite a Margem de lucro:\n");
            scanf("%d",&Intaux);
            break;
        case 15:
            printf("Digite o Horario de checkin:\n");
            scanf(" %[^\n]s", aux);
            break;
        case 16:
            printf("Digite o Horario de Checkout:\n");
            scanf(" %[^\n]s", aux);
            break;
        case 0:
            menuHotel();
            break;
    }

    switch (modo) {
        case 1:
            break;
        case 2:
            //texto
            break;
        case 3:
            AlteraHotel(op,aux,Intaux);
            break;
    }
    menuHotel();

}

void alterarOperador() {
    int cod, op, auxInteiro = 0;

    free(aux);
    aux = realloc(aux, sizeof(char) * 200);

    operador = malloc(sizeof(Operadores) * (codigo->codigoOperador + 1));
    LerUltimosCodigos(3);
    switch (modo){
        case 1:
            //memoria
            break;
        case 2:
            //texto
            break;
        case 3:
            LerOperadorBinario(operador, codigo->codigoOperador + 1);
            break;
    }



    printf("Operadores:\n");
    for (int i = 0; i <= codigo->codigoOperador; i++) {
        if (operador[i].codOperador > 0 && operador[i].ativo == 1) {
            printf("Operador :%d, %s\n", operador[i].codOperador, operador[i].usuarioOperador);
        }
    }
    printf("Digite o codigo do Operador que deseja alterar dados:\n");
    scanf("%d", &cod);

    for (int j = 0; j <= codigo->codigoOperador; j++) {

        if (cod == codigo->codigoOperador && operador[j].ativo == 1) {
            printf("Qual dado deseja alterar ?\n");
            printf("1 - Nome\n2 - Nome de Usuario\n3 - Senha\n4 - Nivel de permissao\n0 - Voltar\n");
            scanf("%d", &op);

            switch (op) {
                case 1:
                    printf("Digite o Nome :\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 2:
                    printf("Digite o Nome de Usuario :\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 3:
                    printf("Digite a senha :\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 4:
                    printf("Digite o Nivel de permissao :\n");
                    scanf("%d", &auxInteiro);
                    break;
                case 0:
                    menuOperadores();
                    break;

            }
            switch (modo){
                case 1:
                    //memoria
                    break;
                case 2:
                    //texto
                    break;
                case 3:
                    AlteraOperadorBinario(cod, op, aux, auxInteiro, codigo->codigoOperador + 1);
                    break;
            }
            free(aux);
            menuOperadores();
        } else {
            printf("Codigo Invalido\n");
            menuOperadores();
        }
    }

}

void alterarAcomodacao() {
    int cod, op, Intaux;

    free(aux);
    aux = realloc(aux, sizeof(char) * 200);

    acomodacoes = malloc(sizeof(Acomodacoes) * (codigo->codigoAcomodacoes + 1));
    LerUltimosCodigos(4);

    switch (modo){
        case 1:
            //memoria
            break;
        case 2:
            //texto
            break;
        case 3:
            LerArquivoBinarioAcomodacoes(acomodacoes, codigo->codigoAcomodacoes + 1);
            break;
    }


    printf("Acomodacoes\n");
    for (int i = 0; i <= codigo->codigoAcomodacoes; i++) {
        if (acomodacoes[i].ativo == 1) {
            printf("Acomodacao: %d,Descricao: %s, Categoria: %s\n", acomodacoes[i].codAcomodacao,
                   acomodacoes[i].descricao, acomodacoes[i].categoria);
        }
    }
    printf("Digite o codigo da acomodacao que deseja alterar dados:\n");
    scanf("%d", &cod);

    for (int j = 0; j <= codigo->codigoAcomodacoes; j++) {
        if (cod == acomodacoes[j].codAcomodacao && acomodacoes[j].ativo == 1) {
            printf("Qual dado deseja alterar ?\n");
            printf("1 - Descricao\n2 - Facilidades\n3 - Categoria Acomodacao\n0 - Voltar\n");
            scanf("%d", &op);

            switch (op) {
                case 1:
                    printf("Digite a nova Descricao:\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 2:
                    printf("Facilidades:\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 3:
                    printf("Categoria:\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 0 :
                    menuAcomodacoes();
                    break;
            }
            switch (modo){
                case 1:
                    //memoria
                    break;
                case 2:
                    //texto
                    break;
                case 3:
                    AlteraAcomodacoes(codigo->codigoAcomodacoes + 1, op, cod, aux, Intaux);
                    break;
            }
            free(aux);
            menuAcomodacoes();
        } else {
            printf("Codigo Invalido!\n");
            menuAcomodacoes();
        }
    }

}

void alterarCategoriaAcomodacoes() {
    int cod, op, Intaux;
    float Floataux;

    free(aux);
    aux = realloc(aux, sizeof(char) * 200);

    categoriaAcomodacoes = malloc(sizeof(CategoriaAcomodacoes) * (codigo->codigoCategoriaAcomodacoes + 1));
    LerUltimosCodigos(5);

    switch (modo){
        case 1:
            //memoria
            break;
        case 2:
            //texto
            break;
        case 3:
            LerArquivoBinarioCategoriaAcomodacoes(categoriaAcomodacoes, codigo->codigoCategoriaAcomodacoes + 1);
            break;
    }


    printf("Categoria de Acomodacoes\n");
    for (int i = 0; i <= codigo->codigoCategoriaAcomodacoes; i++) {
        if (categoriaAcomodacoes[i].codCategoriaAcomodacoes > 0) {
            printf("Categoria de Acomodacao: %d,Descricao: %s, Quantidade hospedes suportada: %d, Valor da diaria: %.2f\n",
                   categoriaAcomodacoes[i].codCategoriaAcomodacoes,
                   categoriaAcomodacoes[i].descricaoCategoria, categoriaAcomodacoes[i].qntPessoas,
                   categoriaAcomodacoes[i].valorDiaria);
        }
    }
    printf("Digite o codigo da Categoria que deseja alterar dados:\n");
    scanf("%d", &cod);

    for (int i = 0; i <= codigo->codigoCategoriaAcomodacoes; i++) {
        if (cod == categoriaAcomodacoes[i].codCategoriaAcomodacoes) {
            printf("Qual dado deseja alterar ?\n");
            printf("1 - Descricao\n2 - Quantidade de Hospede suportada\n3 - Valor da diaria\n0 - Voltar\n");
            scanf("%d", &op);

            switch (op) {
                case 1:
                    printf("Digite a nova Descricao:\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 2:
                    printf("Quantidade de Hospedes suportada:\n");
                    scanf("%d", &Intaux);
                    break;
                case 3:
                    printf("Valor da diaria:\n");
                    scanf("%f", &Floataux);
                    break;
                case 0 :
                    menuCategoriaAcomodacoes();
                    break;
            }
            switch (modo){
                case 1:
                    //memoria
                    break;
                case 2:
                    //texto
                    break;
                case 3:
                    AlteraCategoriaAcomodacoes(codigo->codigoCategoriaAcomodacoes + 1, op, cod, aux, Intaux, Floataux);
                    break;
            }
            free(aux);
            menuCategoriaAcomodacoes();
        } else {
            printf("Categoria nao encontrada\n");
            menuCategoriaAcomodacoes();
        }
    }
}

void alterarProduto() {
    int cod, op, Intaux;
    float Floataux;

    free(aux);
    aux = realloc(aux, sizeof(char) * 200);
    produto = malloc(sizeof(Produto) * (codigo->codigoProduto + 1));
    switch (modo){
        case 1:
            //memoria
            break;
        case 2:
            //texto
            break;
        case 3:
            LerArquivoProduto(produto, codigo->codigoProduto + 1);
            break;
    }


    for (int i = 0; i < codigo->codigoProduto; i++) {
        if (produto[i].ativo == 1) {
            printf("Codigo do produto: %d\n", produto[i].codProduto);
            printf("Descricao: %s\n", produto[i].descricao);
            printf("Estoque Minimo: %d\n", produto[i].estoqueMinimo);
            printf("Estoque: %d\n", produto[i].estoque);
            printf("Preco de custo: %.2f\n", produto[i].precoCusto);
            printf("Preco venda: %.2f\n", produto[i].precoVenda);
            printf("\n\n");
        }
    }

    printf("Digite o codigo do produto que deseja alterar:\n");
    scanf("%d", &cod);
    for (int i = 0; i <= codigo->codigoProduto; i++) {
        if (cod == produto[i].codProduto && produto[i].ativo == 1) {
            printf("Qual dado deseja alterar ?\n");
            printf("1 - Descricao\n2 - Estoque Minimo\n3 - Estoque\n4 - Preco de custo\n5 - Preco de venda\n0 - Voltar\n");
            scanf("%d", &op);

            switch (op) {
                case 1:
                    printf("Digite a nova Descricao:\n");
                    scanf(" %[^\n]s", aux);
                    break;
                case 2:
                    printf("Digite o Estoque minimo:\n");
                    scanf("%d", &Intaux);
                    break;
                case 3:
                    printf("Digite o Estoque:\n");
                    scanf("%d", &Intaux);
                    break;
                case 4:
                    printf("Digite o preco de custo:\n");
                    scanf("%f", &Floataux);
                    break;
                case 5:
                    printf("Digite o preco de venda:\n");
                    scanf("%f", &Floataux);
                    break;
                case 0 :
                    menuProdutos();
                    break;
            }
            switch (modo){
                case 1:
                    //memoria
                    break;
                case 2:
                    //texto
                    break;
                case 3:
                    AlteraProduto(codigo->codigoProduto + 1, op, cod, aux, Intaux, Floataux);
                    break;
            }
            free(aux);
            menuProdutos();
        } else {
            printf("Produto nao encontrado\n");
            alterarProduto();
        }
    }

}

void buscarHospede() {
    CarregarCodigoBinario(codigo);
    hospede = malloc(sizeof(Hospede) * (codigo->codigoHospede + 1));
    LerArquivoHospede(hospede, codigo->codigoHospede + 1);
    int cod = 0;
    char mais;
    do {
        printf("Digite o codigo do Hospede que deseja encontrar:\n");
        scanf("%d", &cod);

        for (int i = 0; i < codigo->codigoHospede; i++) {

            if (cod == hospede[i].codHospede && hospede[i].ativo == 1) {
                printf("Hospede encontrado!\n");
                printf("Codigo do Hospede: %d\n", hospede[i].codHospede);
                printf("Nome: %s\n", hospede[i].nome);

            } else {
                printf("Hospede nao encontrado!\n");
                buscarHospede();
                break;
            }
        }
        printf("Deseja pesquisar outro hospede? [s/n]\n");
        scanf("%s", &mais);

    } while (mais != 'n');

    menuHospedes();

}

void buscarFornecedor() {
    CarregarCodigoBinario(codigo);
    fornecedores = malloc(sizeof(Fornecedores) * codigo->codigoFornecedor + 1);
    LerArquivoFornecedores(fornecedores, codigo->codigoFornecedor + 1);
    int cod;
    char mais;

    do {
        printf("Digite o codigo do Fornecedor que deseja encontrar:\n");
        scanf("%d", &cod);
        for (int i = 0; i <= codigo->codigoFornecedor; i++) {
            if (cod == fornecedores[i].codFornecedor && fornecedores[i].ativo == 1) {
                printf("Fornecedor encontrado!\n");
                printf("Codigo do Fornecedor: %d\n", fornecedores[i].codFornecedor);
                printf("Nome Fantasia Fornecedor: %s\n", fornecedores[i].nomeFantasiaFornecedor);

            } else {
                printf("Fornecedor nao encontrado!\n");
                buscarFornecedor();
                break;
            }
        }
        printf("Deseja pesquisar outro Fornecedor [s/n]?\n");
        scanf("%s", &mais);
    } while (mais != 'n');
    menuFornecedores();
}

void buscarOperador() {
    CarregarCodigoBinario(codigo);
    operador = malloc(sizeof(Operadores) * (codigo->codigoOperador + 1));
    LerOperadorBinario(operador, codigo->codigoOperador + 1);
    int cod;
    char mais;

    do {
        printf("Digite o codigo do operador que deseja encontrar:\n");
        scanf("%d", &cod);
        for (int i = 0; i <= codigo->codigoOperador; i++) {
            if (cod == codigo[i].codigoOperador && operador[i].ativo == 1) {
                printf("Operador encontrado!\n");
                printf("Login do Operador: %s\n", operador[i].usuarioOperador);
                printf("Codigo do Operador: %d\n", operador[i].codOperador);
                break;
            } else {
                printf("Operador nao encontrado!\n");
                buscarOperador();
                break;
            }
        }
        printf("Deseja buscar outro operador [s/n] ?\n");
        scanf("%s", &mais);

    } while (mais != 'n');

}

void buscarAcomodacao() {
    CarregarCodigoBinario(codigo);
    acomodacoes = malloc(sizeof(Acomodacoes) * (codigo->codigoAcomodacoes + 1));
    LerArquivoBinarioAcomodacoes(acomodacoes, codigo->codigoAcomodacoes + 1);
    int cod, existe;
    char mais;

    do {
        printf("Digite o codigo da Acomodacao que deseja encontrar:\n");
        scanf("%d", &cod);
        for (int (i) = 0; (i) < codigo->codigoAcomodacoes; ++(i)) {
            if (cod == acomodacoes[i].codAcomodacao && acomodacoes[i].ativo == 1) {
                printf("Acomodacao: %d\n", acomodacoes[i].codAcomodacao);
                printf("Descricao: %s\n", acomodacoes[i].descricao);
                printf("Facilidades: %s\n", acomodacoes[i].facilidades);
                printf("Categoria: %s\n", acomodacoes[i].categoria);

            } else {
                printf("Nao encontrado!\n");
                buscarAcomodacao();
                break;
            }
        }
        printf("Deseja buscar outra acomodacao [s/n] ?\n");
        scanf("%s", &mais);

    } while (mais == 's' || mais == 'S');
    menuAcomodacoes();
}

void buscarCategoriaAcomodacoes() {
    CarregarCodigoBinario(codigo);
    categoriaAcomodacoes = malloc(sizeof(categoriaAcomodacoes) * (codigo->codigoCategoriaAcomodacoes + 1));
    LerArquivoBinarioCategoriaAcomodacoes(categoriaAcomodacoes, codigo->codigoCategoriaAcomodacoes + 1);
    int cod, existe;
    char mais;

    do {
        printf("Digite o codigo da categoria que deseja buscar:\n");
        scanf("%d", &cod);

        for (int (i) = 0; (i) < codigo->codigoCategoriaAcomodacoes; ++(i)) {
            if (cod == categoriaAcomodacoes[i].codCategoriaAcomodacoes) {
                existe++;
            }
        }
        for (int i = 0; i < codigo->codigoCategoriaAcomodacoes; i++) {
            if (cod == existe) {
                printf("Codigo da categoria: %d\n", categoriaAcomodacoes[i].codCategoriaAcomodacoes);
                printf("Descricao: %s\n", categoriaAcomodacoes[i].descricaoCategoria);
                printf("Quantidade de pessoas suportadas: %d\n", categoriaAcomodacoes[i].qntPessoas);
                printf("Valor da diaria: %.2f\n", categoriaAcomodacoes[i].valorDiaria);
            } else {
                printf("Nao encontrei\n");
                menuCategoriaAcomodacoes();
                break;
            }
        }

        printf("Deseja buscar mais [s/n] ?\n");
        scanf(" %s", &mais);
    } while (mais == 's' || mais == 'S');


}

void buscarProduto() {
    produto = malloc(sizeof(Produto) * (codigo->codigoProduto + 1));
    LerUltimosCodigos(6);
    LerArquivoProduto(produto, codigo->codigoProduto + 1);
    int cod, existe = 0;
    char mais;

    do {
        printf("Digite o codigo do produto que deseja encontrar:\n");
        scanf("%d", &cod);

        for (int (i) = 0; (i) < codigo->codigoProduto; ++(i)) {
            if (cod == produto[i].codProduto && produto[i].ativo == 1) {
                existe++;
            }
        }
        for (int j = 0; j < codigo->codigoProduto; j++) {
            if (existe > 0) {
                printf("Codigo do produto: %d\n", produto[j].codProduto);
                printf("Descricao: %s\n", produto[j].descricao);
                printf("Estoque Minimo: %d\n", produto[j].estoqueMinimo);
                printf("Estoque: %d\n", produto[j].estoque);
                printf("Preco de custo: %.2f\n", produto[j].precoCusto);
                printf("Preco venda: %.2f\n", produto[j].precoVenda);
                printf("\n\n");

            } else {
                printf("Produto nao encontrado!\n");
                buscarProduto();
                break;
            }
        }
        menuProdutos();
        printf("Deseja buscar mais [s/n] ?\n");
        scanf("%s", &mais);

    } while (mais == 's' || mais == 'S');
}


void DesativarHospede() {
    int cod;
    printf("Digite o codigo do cliente que deseja desativar!\n");
    scanf("%d", &cod);
    DesativaHospede(cod, codigo->codigoHospede + 1);

}

void DesativarFornecedor() {
    int cod;
    printf("Digite o codigo do fornecedor que deseja excluir do registro!\n");
    scanf("%d", &cod);
    DesativaFornecedor(cod, codigo->codigoFornecedor + 1);
}

void DesativarOperador() {
    int cod;
    printf("Digite o codigo do operador que deseja desativar\n");
    scanf("%d", &cod);
    //DesativaOperador(cod, codigo->codigoOperador + 1);
    exit(1);
}

void DesativarAcomodacao() {
    int cod;
    printf("Digite o codigo da Acomodacao que deseja desativar!\n");
    scanf("%d", &cod);
    DesativaAcomodacoes(cod, codigo->codigoAcomodacoes + 1);
}

void DesativarCategoriaAcomodacao() {
    int cod;
    printf("Digite o codigo do Operador que deseja desativar!\n");
    scanf("%d", &cod);
    DesativarOperador(cod, codigo->codigoOperador + 1);

}

void DesativarProduto() {
    int cod;
    printf("Digite o codigo do produto que deseja desativar:\n");
    scanf("%d", &cod);
    DesativaProduto(cod, codigo->codigoProduto + 1);

}
