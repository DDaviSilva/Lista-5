#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

Lista *cria_lista(){

	Lista *li = (Lista *)malloc(sizeof(Lista));
	if(li != NULL)
		*li = NULL;
	return li;

}

int insere_lista(Lista *li, Cliente client, int pos){

	if(li == NULL)
		return 0;
	if(pos < 1)
		return 0;
		
	Elem *no = (Elem *)malloc(sizeof(Elem));
	
	no->cliente = client;
	
	if(pos == 1){
	
		no->prox = (*li);
		*li = no;
		return 1;
	
	}
	
	Elem *ant = NULL,*atual = *li;
	
	int i;
	for(i = 1; (i < pos) && (atual != NULL); i++){
		ant = atual;
		atual = atual->prox;
	}
	
	if(atual == NULL && i != pos)
		return 0;
	
	ant->prox = no;
	no->prox = atual;
	
	return 1;
	
}

int remove_lista(Lista *li, int pos){

	if(li == NULL)
		return 0;
	if(*li == NULL)
		return 0;
	if(pos < 1)
		return 0;
	
	Elem *ant = NULL, *atual = (*li);
	
	int i;
	for(i = 1; (i < pos) && (atual != NULL); i++){
		ant = atual;
		atual = atual->prox;
	}
	
	if(atual == NULL)		// posição não existe na lista
		return 0;
	
	if(ant == NULL){		// significa que será removido o primeiro elemento
		*li = atual->prox;
		free(atual);
		return 1;
	}
	
	ant->prox = atual->prox;
	free(atual);
	
	return 1;

}
int pos_lista(Lista *li, Cliente client){

	if(li == NULL)
		return 0;
	if(*li == NULL)
		return 0;
		
	Elem *aux = (*li);
	int i = 1;
	while((aux != NULL) && (aux->cliente.cpf != client.cpf)){
		aux = aux->prox;
		i++;
	}
	
	if(aux == NULL)
		return 0;
	
	return i;

}

int print_lista(Lista *li){

	if(li == NULL)
		return 0;
	if(*li == NULL)
		return 0;
		
	Elem *no = *li;
	
	while(no != NULL){
	
		printf("================================\n");
		printf("Nome: %s.\n",no->cliente.nome);
		printf("CPF: %d.\n",no->cliente.cpf);
		printf("================================\n");
	
		no = no->prox;
	
	}
	
	return 1;

}
int libera_lista(Lista *li){

	if(li == NULL)
		return 0;
	
	Elem *aux;
	
	while((*li) != NULL){
		aux = *li;
		(*li) = (*li)->prox;
		free(aux);
	}
	
	free(li);
	
	return 1;

}
