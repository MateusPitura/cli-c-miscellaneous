/*
Implemente uma funcao que receba como parametro um array de numeros reais de
tamanho N e retorne quantos numeros negativos ha nesse array. Essa funcao deve
obedecer ao prototipo: int negativos(float *vet, int N);
*/

#include <stdio.h>
#include <time.h>

#define TAM 100

float sorteia(int limMin, int limMax);
void preenche(float *array, int size, int limMin, int limMax);
int negativos(float *array, int size);

int main(){
    float vetor[TAM];
    int quantNeg;
    srand(time(NULL));
    preenche(vetor, TAM, -10, 10);
    quantNeg=negativos(vetor, TAM);
    printf("A quantidade de numeros negativos no vetor e %d", quantNeg);
}

float sorteia(int limMin, int limMax){
    return limMin+rand()%(limMax-limMin+1);
}

void preenche(float *array, int size, int limMin, int limMax){
    for(int i=0; i<size; i++){
        *(array+i)=sorteia(limMin, limMax);
    }
}

int negativos(float *array, int size){
    int count=0;
    for(int i=0; i<size; i++){
        if(*(array+i)<0){
            count++;
        }
    }
    return count;
}