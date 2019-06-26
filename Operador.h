typedef struct {
    int codOperador;
    char nomeOperador[50];
    char usuarioOperador[10];
    char senhaOperador[6];
    int permissaoAcesso; // Define quais modulos o funcionario tera acesso no sistema;
    int ativo;

} Operadores;
