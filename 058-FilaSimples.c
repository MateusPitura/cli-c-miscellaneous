#include <stdio.h>

#define TAM 10

int fila[TAM];
int fim=-1;

void enqueue(int valor);
void dequeue();
void inicioFila();
void imprimi();
void movimentar();

int main(void){
    enqueue(1);
    enqueue(2);
    enqueue(3);
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
    if(fim==-1){
        printf("Fila vazia\n");
        return;
    }
    movimentar();
    fim--;
}

void inicioFila(){
    if(fim==-1){
        printf("Fila vazia\n");
        return;
    }
    printf("Inicio: %d\n", fila[0]);
}

void imprimi(){
    int i;
    for(i=0; i<TAM; i++){
        printf("| %d ", fila[i]);
    }
    printf("|\n");
}

void movimentar(){
    int i;
    for(i=0; i<=fim; i++){
        fila[i]=(fila[i+1]);
    }
}