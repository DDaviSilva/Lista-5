#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

Fila *cria_fila(){

	Fila *fi = (Fila *)malloc(sizeof(Fila));
	if(fi != NULL)
		*fi = NULL;
	return fi;

}

int insere_fila(Fila *fi, Cliente client){

	if(fi == NULL)
		return 0;
		
	Elem *no = (Elem *)malloc(sizeof(Elem));
	
	no->cliente = client;
	
	Elem *aux = (*fi);
	
	if(aux == NULL){
		(*fi) = no;
		no->prox = NULL;
		return 1;
	}
	
	while(aux->prox != NULL)
		aux = aux->prox;
	
	aux->prox = no;
	no->prox = NULL;
	
	return 1;
	
}

int remove_fila(Fila *fi){

	if(fi == NULL)
		return 0;
	if(*fi == NULL)
		return 0;
	
	Elem *aux = (*fi);
	
	(*fi) = (*fi)->prox;
	free(aux);
	
	return 1;

}

int print_fila(Fila *fi){

	if(fi == NULL)
		return 0;
	if(*fi == NULL)
		return 0;
		
	Elem *no = *fi;
	
	while(no != NULL){
	
		printf("================================\n");
		printf("Nome: %s.\n",no->cliente.nome);
		printf("CPF: %d.\n",no->cliente.cpf);
		printf("================================\n");
	
		no = no->prox;
	
	}
	
	return 1;

}
int libera_fila(Fila *fi){

	if(fi == NULL)
		return 0;
	
	Elem *aux;
	
	while((*fi) != NULL){
		aux = *fi;
		(*fi) = (*fi)->prox;
		free(aux);
	}
	
	free(fi);
	
	return 1;

}
