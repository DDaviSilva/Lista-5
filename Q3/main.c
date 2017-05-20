#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

int main(){

	Pilha *pi = cria_pilha();
	Cliente c;
	
	int n;
	
	for(;;){
	
		printf("1 - insere\n");
		printf("2 - remove\n");
		printf("3 - print\n");
		printf("4 - sair\n");
		printf("Opção: ");
		scanf("%d",&n);
		printf("\n");
		
		switch (n){
		
			case 1:
		 		
		 		printf("Nome: ");
		 		scanf("%s",&c.nome);
		 		printf("CPF: ");
		 		scanf("%d",&c.cpf);
		 		printf("\n");
		 		
		 		printf("%d.\n",insere_pilha(pi, c));
		 		
		 	break;
		 	
		 	case 2:
		 		
		 		printf("%d.\n",remove_pilha(pi));
		 	
		 	break;
		 	
		 	case 3:
		 	
		 		printf("%d.\n",print_pilha(pi));
		 	
		 	break;
		 	
		 	case 4:
		 	
		 		libera_pilha(pi);
		 		return 0;
		 		
		}
	
	}
	
return 0;
}
