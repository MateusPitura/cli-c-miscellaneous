//Fatoracao de um valor inteiro (reais) em notas de 100, 50, 10, 5 e 1

#include <stdio.h>

int main(void){
    int valor, cem, cinquenta, dez, cinco;
    printf("Digite um valor: ");
    scanf("%d", &valor);
    for(cem=0; valor>=100; cem++) valor-=100;
    for(cinquenta=0; valor>=50; cinquenta++) valor-=50;
    for(dez=0; valor>=10; dez++) valor-=10;
    for(cinco=0; valor>=5; cinco++) valor-=5;
    printf("%d de 100, %d de 50, %d de 10, %d de 5 e %d de 1", cem, cinquenta, dez, cinco, valor);
}
