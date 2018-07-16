#include "listaEncadeada.h"

Lista* cria_lista(){
	Lista *L;
	L=malloc(sizeof(Nodo));
	if (L == NULL) {
		printf("ERRO NO ALOCAR\n");
	}
	L->qtd = 0;
	L->first = NULL;
	return L;
}


int lista_cheia(Lista *L){
	if (L == NULL) {
		return -1;
	}else if (L->qtd == 100){
		return 1;
	}
	return 0;
}

int lista_vazia(Lista *L){
	if (L == NULL) {
		return -1;
	}else if (L->qtd > 0){
		return 0;
	}
	return 1;
}

void imprimeLista(Lista *L){
	// Nao tem no cofigo .h que ele enviou
	// usar somente pra me encontra no codigo 
	int vazia = 0;
	Nodo *newNodo = L->first;
	vazia = lista_vazia(L);
	if (vazia == 1) {
		printf("Lista vazia !\n");
	}else {
		do {
			printf("[%d]\n", newNodo->val);
			newNodo = newNodo->prox;
		}while(newNodo->prox != NULL);
	}
}

int insere(Lista *L, int pos, int valor){
	Nodo *newNodo, *nodoAuxiliar;
	int cheia = 0;
	// Nessa situacao nao podera ser inserido um novo nodo
	if (pos > MAX-1 || pos > L->qtd) {
		return 0;
	}
	cheia = lista_cheia(L);
	// Nessa situacao a lista esta cheia e nao podera inserir
	if (cheia == 1) {
		return 0;
	}else{
		newNodo = malloc(sizeof(Nodo));
		if (newNodo == NULL) {
			return 0;
		}
		newNodo->val = valor;
	 	// Caso a lista nao contenha nada
	 	if (L->first == NULL) {
			newNodo->prox = NULL;
			L->first = newNodo;
		}else {
			//Caso pos == 0			
			if (pos == 0) {
				newNodo->prox = L->first;
				L->first = newNodo;
			} else{
				// Para insercao em qualquer outro caso
				nodoAuxiliar = L->first;
				for (int i = 0; i < pos-1; ++i) {
					nodoAuxiliar = nodoAuxiliar->prox;
				}
				newNodo->prox = nodoAuxiliar->prox;
				nodoAuxiliar->prox = newNodo;
			}
		}
	}
	L->qtd += 1;
	return 1;
}

int deleta(Lista *L, int pos){
	Nodo *newNodo, *nodo;
	int vazia;
	vazia = lista_vazia(L);
	if (vazia == 1) {
		return 0;
	} else if (pos > MAX-1 || pos > L->qtd) {
		return 0;
	} else if (pos == 0) {
		newNodo = L->first;
		L->first = newNodo->prox;
		free(newNodo);
		L->qtd -= 1;
		return 1;
	}else {
		newNodo = L->first;
		for (int i = 0; i < pos-1; ++i) {
				newNodo = newNodo->prox;
		}
		nodo = newNodo->prox; //Nodo o qual quero remover
		newNodo->prox = nodo->prox;
		free(nodo);
		L->qtd -= 1;
		return 1;
	}
	return 0;
}

void destroi_Lista(Lista *L){
	Nodo *newNodo, nodo;
	while(L->first != NULL){
		newNodo = L->first;
		L->first = newNodo->prox;
		free(newNodo);
	}
}


int get(Lista *L, int pos){
	Nodo *newNodo;
	newNodo = L->first;
	if (pos > L->qtd || pos > MAX-1) {
		return 0;
	}
	for (int i = 0; i < pos; ++i) {
		newNodo = newNodo->prox;
	}	
	return newNodo->val;
}


int set(Lista *L, int pos, int valor){
	Nodo *newNodo, *nodo;
	newNodo = L->first;
	if (pos > L->qtd || pos > MAX-1){
		return 0;
	}
	for (int i = 0; i < pos; ++i) {
		nodo = newNodo->prox;
	}
	if (nodo != NULL) {
		nodo->val = valor;
		L->qtd += 1;
		return 1;
	}
	return 0;
}

int locate(Lista *L, int numero){
	int i = 0;
	Nodo *newNodo;
	newNodo = L->first;
	if (newNodo->val == numero) {	
		return i;
	}
	for (i = 1; i < L->qtd; ++i){
		newNodo = newNodo->prox;
		if (newNodo->val == numero) {
			return i;
		}

	}
	return -1;
}


int length(Lista *L){
	return L->qtd;
}
