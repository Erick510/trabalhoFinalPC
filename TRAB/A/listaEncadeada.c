#include "listaEncadeada.h"

/*
typedef struct nodo{
   int val;
   struct nodo *prox;
}Nodo;
*/

Nodo *cria_lista()
{
	Nodo *novo;
	if((novo = (Nodo *)malloc(sizeof(Nodo))) == NULL)
	{
		puts("Erro na criação de um objeto!\n");
		exit(1);
	}
	novo->prox= NULL;
	return novo;
}



int lista_vazia(Nodo *head)
{
	if (head == NULL) 
		return -1;
	else
	{
		if (head->prox == NULL)
			return 1;
		else
			return 0;
	}
}

int length(Nodo *head)
{
	int i;
	Nodo *aux;
	for (i = 0,aux = head; aux->prox != NULL; i++, aux=aux->prox);
	return i;
}