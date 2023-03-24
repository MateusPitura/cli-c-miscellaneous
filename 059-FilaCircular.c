#include <stdio.h>

#define TAM 7

int fila[TAM];
int final=-1;
int inicio=0;
int tamanho=0;

void enqueue(int valor);
void dequeue();
void inicioFila();
void imprimir();

int main(void){
    enqueue('A');
    enqueue('B');
    enqueue('C');
    enqueue('E');
    enqueue('F');
    enqueue('G');
    enqueue('H');
    enqueue('I');
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    inicioFila();
    imprimir();
}

void enqueue(int valor){
    if((tamanho+1)>TAM){
        printf("Pilha cheia\n");
        return;
    }
    tamanho++;
    final++;
    if(final>=TAM){
        final=0;
    }
    fila[final]=valor;
}

void dequeue(){
    if((tamanho-1)<=0){
        printf("Pilha vazia\n");
        return;
    }
    tamanho--;
    inicio++;
    if(inicio>=TAM){
        inicio=0;
    }
}

void inicioFila(){
    printf("Inicio da fila: %c\n", fila[inicio]);
}

void imprimir(){
    int i;
    for(i=0; i<TAM; i++){
        if(i==inicio){
            printf("| <%c ", fila[i]);    
        } else if(i==final){
            printf("| %c> ", fila[i]);
        } else{
            printf("| %c ", fila[i]);
        }
    }
    printf("|\n");
}
