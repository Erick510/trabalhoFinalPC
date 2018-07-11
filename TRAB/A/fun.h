#include <stdio.h>
#include <stdlib.h>

typedef struct str
{
	int num;
	str *prox;
}str;

str *newObj()
{
	str *nova;
	if((nova = (str *)malloc(sizeof(str))) == NULL)
	{
		puts("Erro na criação de um objeto!\n");
		exit(1);
	}
	nova->prox= NULL;
	return nova;
}

void imprimeLista(str *head)
{
	str *aux;
	for (aux = head->prox; aux != NULL; aux = aux->prox)
	{
		printf("%d\n", aux->num );
		printf("%p\n", aux->prox );
	}
}

void insereInicio(int valor, str *head)
{
	str *nova;
	nova = newObj();
	nova->num = valor;
	nova->prox=head->prox;
	head->prox=nova;
}

void insereFim(int valor, str *head)
{
	str *nova,*atual, *ant;
	nova = newObj();
	nova->num = valor;
	nova->prox=NULL;

	atual = head;
	while(atual != NULL)
	{
		ant=atual;
		atual=atual->prox;
	}
	ant->prox = nova;
}

