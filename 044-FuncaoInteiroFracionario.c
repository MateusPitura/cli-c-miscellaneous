#include <stdio.h>

void frac(float num, int *inteiro, float *frac);

int main(void){
    float valor, parteFracValor;
    int parteInteiraValor;
    printf("Digite um valor: ");
    scanf("%f", &valor);
    frac(valor, &parteInteiraValor, &parteFracValor);
    printf("Parte inteira: %d\nParte fracionaria: %f", parteInteiraValor, parteFracValor);
}

void frac(float num, int *inteiro, float *frac){
    *inteiro=num; //Como *inteiro e um int apenas ira receber a parte inteira de um valor fracionario
    *frac=num-(*inteiro); //O numero fracionario menos sua parte inteira e igual a apenas seu numero fracionario
}