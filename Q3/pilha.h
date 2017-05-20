typedef struct{
	int cpf;
	char nome[30];
}Cliente;

typedef struct elemento{
	Cliente cliente;
	struct elemento *prox;
}Elem;

typedef struct elemento *Pilha;

Pilha *cria_pilha();
int insere_pilha(Pilha *pi, Cliente client);
int remove_pilha(Pilha *pi);
int print_pilha(Pilha *pi);
int libera_pilha(Pilha *pi);
