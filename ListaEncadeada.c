#include <stdio.h>
#include <stdlib.h> 

typedef struct no{
		int num; //
		struct no *prox;
	}No;

No* criarNo(){
	No *novo = (No*)malloc(sizeof(No));
	return novo;
}

No* InserirInicio(No* lista, int dado){ //Empilhar
	No *novoNo = criarNo();
	novoNo->num = dado;

	if (lista==NULL){
		lista=novoNo;
		novoNo->prox = NULL;
	}
	else{
		novoNo->prox = lista;
		lista=novoNo; 
	}
	return lista;
}

No* InserirFinal(No* lista, int dado){ //Enfileirar
	No *novoNo = criarNo();
	novoNo->num = dado;
	if(lista==NULL){
		lista = novoNo;
		novoNo->prox = NULL;
	}
	else{
		No* aux = lista;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux -> prox = novoNo;
		novoNo->prox = NULL;
	}
	return lista;
}

void ImprimirLista(No* lista){
	No* aux = lista;
	while(aux != NULL){
		printf("%d ", aux->num);
		aux = aux->prox;
	}
}

int main(void) {
	No *Lista=NULL; //da inicio a lista em questao
  int a;
  scanf("%d", &a);
  while(a!=-1){
    Lista = InserirInicio(Lista, a);
    scanf("%d", &a);
  }
	ImprimirLista(Lista);
}