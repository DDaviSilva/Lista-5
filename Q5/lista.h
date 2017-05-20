typedef struct{
	int cpf;
	char nome[30];
}Cliente;

typedef struct elemento{
	Cliente cliente;
	struct elemento *ant;
	struct elemento *prox;
}Elem;

typedef struct elemento *Lista;

Lista *cria_lista();
int insere_lista(Lista *li, Cliente client, int pos);
int remove_lista(Lista *li, int pos);
int pos_lista(Lista *li, Cliente client);
int print_lista(Lista *li);
int libera_lista(Lista *li);
