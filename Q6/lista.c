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
	
	if(atual == NULL && i == pos)
		no->prox = (*li);
	else
		no->prox = atual;
	
	ant->prox = no;
	
	return 1;
	
}

int remove_lista(Lista *li, int pos){

	if(li == NULL)
		return 0;
	if((*li) == NULL)
		return 0;
	if(pos < 1)
		return 0;
	
	Elem *ant = NULL, *atual = (*li);
	
	if(pos == 1){		// significa que será removido o primeiro elemento
	
	ant = (*li);		// ant = primeiro elemento
	
		if((*li)->prox == NULL){
			printf("Entrou.\n");
			(*li) = NULL;
			free(ant);
			return 1;
		}
		
	printf("Entrou.\n");
	
	*li = atual->prox;
	
	while(atual->prox != ant)
		atual = atual->prox;
		
		atual->prox = (*li);
		
		free(atual);
		return 1;
	}
	
	int i;
	for(i = 1; (i < pos) && (atual != NULL); i++){
		ant = atual;
		atual = atual->prox;
	}
	
	if(atual == NULL)		// posição não existe na lista
		return 0;
	
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
	int cont = 0;
	int i = 1;
	while((aux->cliente.cpf != client.cpf) && (cont != 2 || (aux != (*li)))){
		if(aux != (*li))
			cont++;
		aux = aux->prox;
		i++;
	}
	
	if(cont == 2)
		return 0;
	
	return i;

}

int print_lista(Lista *li){

	if(li == NULL)
		return 0;
	if(*li == NULL)
		return 0;
		
	Elem *no = *li;
	int cont = 0;
	
	while((cont != 2)){
	
		if(no == NULL)
			break;
	
		if(no == (*li))
			cont++;
		
		if(cont < 2){
		
			printf("================================\n");
			printf("Nome: %s.\n",no->cliente.nome);
			printf("CPF: %d.\n",no->cliente.cpf);
			printf("================================\n");
	
			no = no->prox;
	
		}
	
	}
	
	return 1;

}
int libera_lista(Lista *li){

	if(li == NULL)
		return 0;
	
	Elem *aux;
	Elem *prim = *li;
	int cont = 0;
	
	while(cont < 2){
		if((*li) == NULL)
			break;
		if((*li) == prim)
			cont++;
		if(cont < 2){
			aux = *li;
			(*li) = (*li)->prox;
			free(aux);
		}
	}
	
	free(li);
	
	return 1;

}
