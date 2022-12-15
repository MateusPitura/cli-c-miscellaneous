#include <stdio.h>
#include <time.h>

#define N 25

void ordena(float *array, int size);
void exibe(float *array, int size);
float sorteia(int min, int max);
void fill(float *array, int size, int min, int max);

int main(){
    float vetor[N];
    srand(time(NULL));
    fill(vetor, N, 5, 10);
    exibe(vetor, N);
    printf("\n");
    ordena(vetor, N);
    exibe(vetor, N);
    printf("\n");
}

void ordena(float *array, int size){
    for(int i=0; i<size; i++){
        for(int j=i; j<size; j++){
            if(*(array+i)>*(array+j)){
                *(array+i)+=*(array+j); //A=A+B (A: 8 e B: 3)
                *(array+j)=*(array+i)-*(array+j); //B=A-B (B: 5 e A: 8)
                *(array+i)-=*(array+j); //A=A-B (A: 3 e B: 5)
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