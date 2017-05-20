#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

Pilha *cria_pilha(){

	Pilha *pi = (Pilha *)malloc(sizeof(Pilha));
	if(pi != NULL)
		*pi = NULL;
	return pi;

}

int insere_pilha(Pilha *pi, Cliente client){

	if(pi == NULL)
		return 0;
		
	Elem *no = (Elem *)malloc(sizeof(Elem));
	
	no->cliente = client;

	Elem *aux = *pi;
	
	if((*pi) == NULL){
		(*pi) = no;
		no->prox = NULL;
		return 1;
	}
	
	while(aux->prox != NULL)
		aux = aux->prox;
	
	aux->prox = no;
	no->prox = NULL;
	
	return 1;
	
}

int remove_pilha(Pilha *pi){

	if(pi == NULL)
		return 0;
	if(*pi == NULL)
		return 0;
	
	Elem *ant = NULL, *atual = (*pi);
	
	if(atual->prox == NULL){
		*pi = NULL;
		return 1;
	}
	
	while(atual->prox != NULL){
		ant = atual;
		atual = atual->prox;
	}
	
	ant->prox = NULL;
	free(atual);
	
	return 1;

}

int print_pilha(Pilha *pi){

	if(pi == NULL)
		return 0;
	if(*pi == NULL)
		return 0;
		
	Elem *no = *pi;
	
	while(no != NULL){
	
		printf("================================\n");
		printf("Nome: %s.\n",no->cliente.nome);
		printf("CPF: %d.\n",no->cliente.cpf);
		printf("================================\n");
	
		no = no->prox;
	
	}
	
	return 1;

}
int libera_pilha(Pilha *pi){

	if(pi == NULL)
		return 0;
	
	Elem *aux;
	
	while((*pi) != NULL){
		aux = *pi;
		(*pi) = (*pi)->prox;
		free(aux);
	}
	
	free(pi);
	
	return 1;

}
