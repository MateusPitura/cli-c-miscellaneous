#include <stdio.h>
#include <time.h>

#define N 25

void ordena(float *array, int size, char ctrl); //0: crescente, 1: decrescente
void exibe(float *array, int size);
float sorteia(int min, int max);
void fill(float *array, int size, int min, int max);
void comuta(float *varA, float *varB);

int main(){
    float vetor[N];
    srand(time(NULL));
    fill(vetor, N, 5, 10);
    exibe(vetor, N);
    printf("\n");
    ordena(vetor, N, '1');
    exibe(vetor, N);
    printf("\n");
}

void ordena(float *array, int size, char ctrl){
    for(int i=0; i<size; i++){
        for(int j=i; j<size; j++){
            if(ctrl=='0'?*(array+i)>*(array+j):*(array+i)<*(array+j)){
                comuta(array+i, array+j);
            }
        }
    }
}

void exibe(float *array, int size){
    for(int i=0; i<size; i++){
        printf("Array[%2d]=%6.2f\n", i, *(array+i));
    }
}

float sorteia(int min, int max){
    return min+(rand()%(max+1-min));
}

void fill(float *array, int size, int min, int max){
    for(int i=0; i<size; i++){
        *(array+i)=sorteia(min, max);
    }
}

void comuta(float *varA, float *varB){
    *varA+=*varB; //A=A+B (ex.: A=8 e B=3)
    *varB=*varA-*varB; //B=A-B (ex.: B=5 e A=8)
    *varA-=*varB; //A=A-B (ex.: A=3 e B=5)
}