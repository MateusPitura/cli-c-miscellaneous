/*
Crie uma funcao para somar dois arrays. Esta funcao deve receber dois arrays e retornar
a soma em um terceiro array. Caso o tamanho do primeiro e segundo array seja diferente
entao a funcao retornara ZERO (0). Caso a funcao seja concluida com sucesso a mesma
deve retornar o valor UM (1). Utilize aritmetica de ponteiros para manipulacao do array
*/

#include <stdio.h>

#define TAM_A 5
#define TAM_B 5
#define TAM_C 5

float sorteia(int tamMin, int tamMax);
void preenche(float *array, int size, int tamMin, int tamMax);
int somaVetores(float *arrayA, int sizeA, float *arrayB, int sizeB, float *arrayC);

int main(){
    float vetA[TAM_A], vetB[TAM_B], vetC[TAM_C];

}

float sorteia(int tamMin, int tamMax){
    return tamMin+(rand()%(tamMax-tamMin+1));
}

void preenche(float *array, int size, int tamMin, int tamMax){
    for(int i=0; i<size; i++){
        *(array+i)=sorteia(tamMin, tamMax);
    }
}

int somaVetores(float *arrayA, int sizeA, float *arrayB, int sizeB, float *arrayC){

}