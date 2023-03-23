#include <stdio.h>

#define TAM 8

int pilha[TAM];
int topo=-1;

void push(int valor);
void pop();
void topoPilha();
void imprimi();

int main(void){
	push(1);
	push(2);
	push(3);
	push(4);
	pop();
	topoPilha();
	imprimi();
	return 0;
}

void push(int valor){
	if(topo==TAM-1){
		printf("Pilha cheia\n");
		return;
	}
	topo++;
	pilha[topo]=valor;
	printf("Adicionada\n");
}

void pop(){
	if(topo==-1)	{
		printf("Pilha vazia\n");
		return;
	}
	topo--;
	printf("Removida\n");
}

void topoPilha(){
	if(topo==-1){
		printf("Pilha vazia\n");
		return;
	}
	printf("Topo: %d\n", pilha[topo]);
}

void imprimi(){
	int i;
	for(i=topo; i>=0; i--){
		printf("| %d |\n", pilha[i]);
	}
}