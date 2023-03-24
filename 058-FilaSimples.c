#include <stdio.h>

#define TAM 5

int fila[TAM];
int inicio=0;
int fim=-1;
int elementos=0;

void enqueue(int valor);
void dequeue();
void inicioFila();
void imprimi();

int main(void){
    enqueue(8);
    enqueue(10);
    enqueue(7);
    enqueue(11);
    enqueue(5);
    dequeue();
    inicioFila();
    imprimi();
    return 0;
}

void enqueue(int valor){
    if(fim==(TAM-1)){
        printf("Fila cheia\n");
        return;
    }
    fim++;
    fila[fim]=valor;
}

void dequeue(){
    if(inicio<=fim){
        printf("Fila vazia\n");
        return;
    }
    inicio++;
}

void inicioFila(){
    if(inicio<=fim){
        printf("Fila vazia\n");
        return;
    }
    printf("Inicio: %d\n", fila[inicio]);
}

void imprimi(){
    int i;
    for(i=inicio; i<=fim; i++){
        printf("| %d ", fila[i]);
    }
    printf("|\n");
}