#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

int main(){

	Lista *li = cria_lista();
	Cliente c;
	
	int n,pos;
	
	for(;;){
	
		printf("1 - insere\n");
		printf("2 - remove\n");
		printf("3 - indice\n");
		printf("4 - print\n");
		printf("5 - sair\n");
		printf("Opção: ");
		scanf("%d",&n);
		printf("\n");
		
		switch (n){
		
			case 1:
		 		
		 		printf("Nome: ");
		 		scanf("%s",&c.nome);
		 		printf("CPF: ");
		 		scanf("%d",&c.cpf);
		 		printf("Posicao: ");
		 		scanf("%d",&pos);
		 		printf("\n");
		 		
		 		printf("%d.\n",insere_lista(li, c, pos));
		 		
		 	break;
		 	
		 	case 2:
		 	
		 		printf("Posicao: ");
		 		scanf("%d",&pos);
		 		printf("\n");
		 		
		 		printf("%d.\n",remove_lista(li, pos));
		 	
		 	break;
		 	
		 	case 3:

		 		printf("CPF: ");
		 		scanf("%d",&c.cpf);
		 		printf("\n");
		 		
		 		printf("Posição: %d.\n\n",pos_lista(li, c));
		 	
		 	break;
		 	
		 	case 4:
		 	
		 		printf("%d.\n",print_lista(li));
		 	
		 	break;
		 	
		 	case 5:
		 	
		 		libera_lista(li);
		 		return 0;
		 		
		}
	
	}
	
return 0;
}
