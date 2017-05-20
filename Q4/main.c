#include<stdio.h>
#include<stdlib.h>
#include"fila.h"

int main(){

	Fila *fi = cria_fila();
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
		 		
		 		printf("%d.\n",insere_fila(fi, c));
		 		
		 	break;
		 	
		 	case 2:
		 		
		 		printf("%d.\n",remove_fila(fi));
		 	
		 	break;
		 	
		 	case 3:
		 	
		 		printf("%d.\n",print_fila(fi));
		 	
		 	break;
		 	
		 	case 4:
		 	
		 		libera_fila(fi);
		 		return 0;
		 		
		}
	
	}
	
return 0;
}
