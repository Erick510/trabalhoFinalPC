#include "listaEncadeada.h"
#include "simpletest.h"

void imprimeLista(Nodo *head){
  Nodo *aux = head->prox;
  int tam = length(head);
  printf("Tamanho da lista: %d.\n",tam);
  for (int i = 0; i < tam; ++i){
    printf("%d", aux->val);
    if(aux->prox != NULL){
      printf(" -> ");
    }else
      printf("-|");

    aux = aux->prox;
  }
  printf("\n");
}



int main(){

	int opc, pos, elem, tam;
	Nodo *l = cria_lista();
	while(1){

		printf("\n\n%s### Trabalho Final de PC - 2017_2 ###%s \n",KGRN, KNRM);
		printf("Escolha sua opcao: \n");
		printf("\t0. Sair\n");
		printf("\t1. Imprimir Lista\n");
		printf("\t2. Inserir Elemento\n");
		printf("\t3. Remover Elemento\n");
		printf("\t4. Mostrar Elemento (Por Posicao)\n");
		printf("\t5. Modificar Elemento\n");
		printf("\t6. Apagar tudo e recomecar\n");
		do{
			printf("\nEscolha sua opcao: ");
			scanf("%d", &opc);
		}while(opc<0 || opc > 6);
		 
		if(opc == 0){
			printf("Destruindo lista e limpando a memoria...\n");
			destroi_Lista(l);
			printf("Saindo do Programa...\n");
			return 0;	
		}
		else{
		 	switch( opc ){
				case 1:
			    	printf("\n\n%s========Imprimindo Lista=======%s\n",KYEL,KNRM);
					imprimeLista(l);
				    break;
			 
				case 2:
			    	printf("\n\n%s========Inserindo elementos=======%s\n",KYEL,KNRM);
		   			tam = length(l);
					if(tam != 0){
						printf("Digite a posicao desejada entre 0 e %d para inserir\n", tam);
						do{
							printf("\nEscolha a posicao: ");
							scanf("%d", &pos);
						}while(pos<0 || pos >tam);
					}
					printf("Elemento a ser inserido: ");
					scanf("%d", &elem);
					if(insere(l, pos, elem) == 1)
						printf("Inserido com sucesso. Voltando ao menu...\n\n");
			    	break;
			  
			  	case 3:
			    	printf("\n\n%s========Removendo elementos=======%s\n",KYEL,KNRM);
		   			tam = length(l);
					
					printf("Digite a posicao desejada entre 0 e %d para remover\n", tam-1);
					do{
						printf("\nEscolha a posicao: ");
						scanf("%d", &pos);
					}while(pos<0 || pos >tam-1);
					
					if(deleta(l, pos) == 1)
						printf("Removido com sucesso. Voltando ao menu...\n\n");
			    	break;

			    case 4:
			    	printf("\n\n%s========Mostrando elemento=======%s\n",KYEL,KNRM);
		   			tam = length(l);
					
					printf("Digite a posicao desejada entre 0 e %d\n", tam-1);
					do{
						printf("\nEscolha a posicao: ");
						scanf("%d", &pos);
					}while(pos<0 || pos >tam-1);
					
					
					printf("Elemento na posicao %d: %d\n. Voltando ao menu...\n\n",pos,get(l,pos));
			    	break;

			    case 5:
			    	printf("\n\n%s========Modificando elemento=======%s\n",KYEL,KNRM);
		   			tam = length(l);
					
					printf("Digite a posicao desejada entre 0 e %d\n", tam-1);
					do{
						printf("\nEscolha a posicao: ");
						scanf("%d", &pos);
					}while(pos<0 || pos >tam-1);

					printf("Novo valor: ");
					scanf("%d", &elem);
					if(set(l, pos, elem) == 1)
						printf("Elemento modificado. Voltando ao menu...\n\n");
			    	break;
			 
			  	case 6:
				    printf("\n\n%s========Apagando lista=======%s\n",KYEL,KNRM);
		   			printf("Destruindo lista...\n");
					destroi_Lista(l);
					printf("Inicializando lista...\n");
					l = cria_lista();
					printf("Voltando ao menu...\n\n");
				    break;
			
	 		}
		}
	}
	return 0;
}
