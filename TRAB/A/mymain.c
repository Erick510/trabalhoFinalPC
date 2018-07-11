#include <stdio.h>
#include <stdlib.h>
#include "listaEncadeada.h"

int main(int argc, char const *argv[])
{
	int a;
	Nodo *head;
	a = lista_vazia(head);
	printf("%d\n", a);

	head = cria_lista();
	a = lista_vazia(head);
	printf("%d\n", a);
	
	a = length(head);
	printf("%d\n", a);

	return 0;
}