typedef struct{
	int cpf;
	char nome[30];
}Cliente;

typedef struct elemento{
	Cliente cliente;
	struct elemento *prox;
}Elem;

typedef struct elemento *Fila;

Fila *cria_fila();
int insere_fila(Fila *fi, Cliente client);
int remove_fila(Fila *fi);
int print_fila(Fila *fi);
int libera_fila(Fila *fi);
