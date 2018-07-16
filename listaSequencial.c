#include "listaSequencial.h"

Lista* cria_lista(){
	Lista *ponteiro;
	ponteiro = malloc(sizeof(Lista));
	ponteiro->qtd = 0;
	return ponteiro;
}

int lista_cheia(Lista *L){
	if (L == NULL) {
		return -1;
	}else if (L->qtd >= MAX) {
		return 1;
	}
	return 0;
}

int lista_vazia(Lista *L){
	if (L == NULL) {
		return -1;
	}else if (L->qtd == 0) {
		return 1;
	}
	return 0;
}

void destroi_Lista(Lista *L){
	free(L);
}

int insere(Lista *L, int pos, int valor){
	int cheia = 0;
	cheia = lista_cheia(L);
	if (cheia == 1 || pos > MAX-1 || pos < 0) {
		return 0;
	}else {	
		for (int i = L->qtd; i > pos; --i) {
			L->dados[i] = L->dados[i-1];			
		}
	}
	L->dados[pos] = valor;
	L->qtd = L->qtd + 1;
	return 1;
}

int deleta(Lista *L, int pos){
	int vazia = 0;
	vazia = lista_vazia(L);
	if (vazia == 1 || pos > L->qtd || pos < 0) {
		return 0;
	}else {
		for (int i = pos; i < MAX-1; ++i) {
			L->dados[i] = L->dados[i+1];
		}
	}
	L->qtd -= 1;
	return 1;	
}

int get(Lista *L, int pos){
	int valor = 0;
	if (L->dados[pos] != NULL && pos <MAX) {
		valor = L->dados[pos];
		return valor;
	}
	return 0;
}

int set(Lista *L, int pos, int valor){
	if (L == NULL || pos > MAX-1 || pos < 0) {
		return 0;
	}else {
		L->dados[pos] = valor;
		L->qtd = L->qtd +1;
	} 
	return 1;	
}

int locate(Lista *L, int numero){
	for (int i = 0; i < MAX; ++i) {
		if (L->dados[i] == numero) {
			return i;
		}
	}
	return -1;
}


int length(Lista *L){
	return L->qtd;
}
