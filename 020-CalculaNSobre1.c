//Calculo de S, sendo N informado pelo usuario S = 1/N + 2/(N-1) + 3/(N-2) + 4/(N-3) + ... + (N-1)/2 + N/1

#include <stdio.h>

int main(void){
    int N;
    float S;
    printf("Digite um valor: ");
    scanf("%d", &N);
    for(int i=0; i!=N; i++) S+=(1+i)/(float)(N-i);
    printf("Resultado: %f", S);
}
