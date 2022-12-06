//Calcula S, sendo N informado pelo usuario S = 1/1 + 1/2 + 1/3 + 1/4 + ... + 1/N

#include <stdio.h>

int main(void){
    int N;
    float S;
    printf("Digite um valor: ");
    scanf("%d", &N);
    for(int i=1; i<=N; i++) S=S+(1/(float)i);
    printf("Resultado: %f", S);
}
