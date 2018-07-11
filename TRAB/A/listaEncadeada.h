#include <stdio.h>
#include <stdlib.h>

#define MAX 20

/* Estrutura de um Nodo
 * qualquer da lista*/
typedef struct nodo{
   int val;
   struct nodo *prox;
}Nodo;


/** Cria a cabeca de uma lista encadeada
 * head->prox deve apontar para NULL
 * @return endereço da cabeca alocada ou NULL*/
Nodo* cria_lista();

/** Testa se a lista está vazia (somente a cabeca)
   @param head descritor da lista
   @return -1 se ponteiro Nulo, 1 Se lista vazia, 0 Caso contrário*/
int lista_vazia(Nodo *head);

/** Retorna o comprimento da lista
  sugerido implementar antes da insere, deleta, get e set,
  pois todas precisam testar se a posicao é "valida" ( <= comprimento da lista)
* @param head descritor da lista
* @return comprimento da lista atual*/
int length(Nodo *head);


/** Destrói a lista, liberando a memória.
	!!!!ATENCAO!!!!
		Destruir uma lista encadeada nao implica somente
		em liberar a memoria da cabeca. Eh preciso liberar
		TODOS OS ELEMENTOS DA LISTA
			Sugestao: Loop de "0 ate o tamanho da Lista" (funcao length) com a funcao "deleta"
			apagando o primeiro elemento e depois  finalmente liberar a cabeca
 * @param head descritor da lista*/
void destroi_Lista(Nodo *head);


/** Insere um elemento na lista em uma posicao
Antes de inserir:
 * @param head descritor da lista
 * @param pos posicao para insercao (teste se a posicao a ser inserida é valida (use funcao length)
 * @param valor que será inserido
 * @return 1 se OK, 0 se erro*/
int insere(Nodo *head, int pos, int valor);


/** Remove um elemento de uma posicao
	Antes de apagar:
		Testar se a lista nao esta vazia(utilize funcao criada)
 * @param head descritor da lista
 * @param pos posicao para remocao (teste se a posicao a ser removida é valida (use funcao length)
 * @return 1 se OK, 0 se erro*/
int deleta(Nodo *head, int pos);


/** Retorna o valor do elemento.
 * @param head descritor da lista
 * @param pos posicao para elemento (teste se a posicao a ser inserida é valida (use funcao length)
 * @return valor caso encontre e 0 caso nao exista*/
 int get(Nodo *head, int pos);


/** Muda o valor do elemento.
 * @param head descritor da lista
 * @param pos posicao para elemento (teste se a posicao a ser inserida é valida (use funcao length)
 * @param a novo valor para item
 * @return 1 se OK, 0 se erro*/
int set(Nodo *head, int pos, int valor);



