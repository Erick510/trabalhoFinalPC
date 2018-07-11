#include "simpletest.h"
#include "listaEncadeada.h"

void imprimeLista(Nodo *head){
  Nodo *aux = head->prox;
  for (int i = 0; i < length(head); ++i){
    printf("%d", aux->val);
    if(aux->prox != NULL){
      printf(" -> ");
    }else
      printf("-|");

    aux = aux->prox;
  }
  printf("\n");
}



void test_create(){
	DESCRIBE("CRIA LISTA");
	IF("Eu crio uma lista");
	THEN("Resultado deve ser ponteiro para a cabeca");
	Nodo *l = cria_lista();
	isNotNull(l);

	IF("Eu Testo o tamanho");
	THEN("Comprimento deve ser 0");
	isEqual(length(l),0);

	destroi_Lista(l);
}

void test_inserts(){
	int i;

	Nodo *l = cria_lista();

	printf("\n\n");
	DESCRIBE("INSERE ELEMENTOS");
	WHEN("Eu insiro elementos em ordem");
	IF("Insiro tantos quanto o maximo");
	THEN("Deve inserir todos");
	for(i=0; i<MAX; i++){
		isEqual_Spaced(insere(l, i, i), 1);
	}

	printf("\n\n");
	printf("%sImpressao lista ordenada%s\n",KYEL,KNRM);
	imprimeLista(l);
	printf("\n");



	THEN_VALUE("Comprimento deve ser MAX",MAX);
	isEqual(length(l),MAX);

	destroi_Lista(l);
	l = cria_lista();

	WHEN("Eu insiro os elementos de ordenados na posicao 0");
	IF("Insiro tantos quanto o maximo");
	THEN("Deve inserir todos");
	for(i=0; i<MAX; i++){
		isEqual_Spaced(insere(l, 0, i), 1);
	}

	printf("\n\n");
	printf("%sImpressao lista inversamente ordenada%s\n",KYEL,KNRM);
	imprimeLista(l);
	printf("\n");

   
    THEN_VALUE("Primeiro elemento deve ser ",MAX-1);
	isEqual(get(l,0),MAX-1);

	THEN("Ultimo elemento deve ser 0");
	isEqual(get(l,MAX-1),0);

	destroi_Lista(l);
}

void test_delete(){

	int i;

	Nodo *l = cria_lista();
	for(i=0; i<MAX; i++){
		insere(l, i, i);
	}
	printf("\n\n");
	DESCRIBE("REMOVE ELEMENTOS");


	printf("\n\n");
	printf("%sImpressao completa%s\n",KYEL,KNRM);
	imprimeLista(l);
	printf("\n");


	WHEN("Eu removo os elementos no inicio");
	THEN("Deve remover o primeiro");
	for(i=0; i < MAX/2; i++){
		isEqual_Spaced(deleta(l, 0),1);
	}

	printf("\n\n");
	printf("%sImpressao lista com %d remocoes no inicio%s\n",KYEL, MAX/2,KNRM);
	imprimeLista(l);
	printf("\n");

	WHEN("Eu removo os elementos no FIM");
	THEN("Deve remover o ultimo");
	for(i=MAX/2; i > MAX/4 ; i--){
		isEqual_Spaced(deleta(l, i-1),1);
	}

	printf("\n\n");
	printf("%sImpressao lista com %d remocoes no final%s\n",KYEL, MAX/4,KNRM);
	imprimeLista(l);
	printf("\n");

	destroi_Lista(l);
}

void test_get_set(){
	int i;

	Nodo *l = cria_lista();
	for(i=0; i < MAX; i++){
		insere(l, i, i);
	}
	printf("\n\n");
	DESCRIBE("CONSULTANDO E MUDANDO ELEMENTOS");

	WHEN("Eu consulto um elemento inserido");
	THEN("Ele deve estar presente");
	isEqual(get(l,1), 1);

	WHEN("Eu consulto uma posicao inexistente");
	THEN("Ele deve retornar Zero");
	isEqual(get(l,MAX),0);

	WHEN("Eu mudo o valor de um elemento existente");
	THEN("Ele deve mudar");
	isEqual(set(l,1,99), 1);
	isEqual(get(l,1), 99);

	WHEN("Eu mudo o valor de um elemento inexistente");
	THEN("Ele deve retornar erro");
	isEqual(set(l,MAX,1),0);

	destroi_Lista(l);
}



int main () {
	test_create();
	test_inserts();
	test_delete();
	test_get_set();
}
