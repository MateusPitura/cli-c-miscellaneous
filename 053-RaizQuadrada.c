/*
Implemente uma funcao que calcule as raizes de uma equacao do segundo grau do tipo
Ax^2 + Bx + C = 0. Lembrando que: X=(−B±√∆)/2A. Onde: ∆=B^2−4AC
A variavel A tem que ser diferente de zero.
- Se ∆ < 0 nao existe real.
- Se ∆ = 0 existe uma raiz real.
- Se ∆ ≥ 0 existem duas ra´ızes reais.
Essa funcao deve obedecer ao seguinte prototipo: int raizes(float A,float B,float C,float *X1,float *X2);
Essa funcao deve ter como valor de retorno o numero de raizes reais e distintas da
equacao. Se existirem raizes reais, seus valores devem ser armazenados nas variaveis apontadas por X1 e X2
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int raizes(float A, float B, float C, float *X1, float *X2);
float calculaDelta(float A, float B, float C);

int main(void){
    int A, B, C;
    float raiz1, raiz2;
    printf("Digite A, B e C: ");
    scanf("%d %d %d", A, B, C);
    switch(raizes(A, B, C, &raiz1, &raiz2)){
        case -1: printf("Não existe raizes reais"); break;
        case 0: printf("Existe uma raiz real"); break;
        case 1: printf("Existe duas raizes reais"); break;
        default: printf("Retorno invalido"); exit(-1);
    }
    printf("Raiz 1: %6.2f Raiz 2: %6.2f", raiz1, raiz2);
}

int raizes(float A, float B, float C, float *X1, float *X2){ //0: delta==0, 1: delta>0, -1: delta<0
    float delta;
    delta=calculaDelta(A, B, C);
    if(delta>=0){
        *X1=(-B+sqrt(delta))/(2*A);
        *X2=(-B-sqrt(delta))/(2*A);
        if(delta==0){
            return 0;
        }
        else{
            return 1;
        }        
    }
    else{ //delta<0
        return -1;
    }
}

float calculaDelta(float A, float B, float C){
    return pow(B,2)-(4*A*C);
}