#ifndef DEFINITIVO_HOTEL_H
#define DEFINITIVO_HOTEL_H

#endif //DEFINITIVO_HOTEL_H

typedef struct
{
    char nome[100];
    char razaoSocial[100];
    char inscricaoEstadual[200];
    char CNPJ[14];
    char bairro[50];
    char rua[50];
    char estado[50];
    char numero[10];
    char cidade[50];
    char email[200];
    char nomeGerente[200];
    int telefone;
    int telefoneGerente;
    char checkin[50];
    char checkout[50];
    int lucro;
    int numeroHotel;// Variavel de controle, usada para verificar se existe ou nao um hotel ja cadastrado

} Hotel;