//Calcula a media de N termos

#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");
    float valor, soma=0;
    int count=0;
    printf("Digite um valor: ");
    scanf("%f", &valor);
    while(valor>0){
        soma+=valor;
        printf("Digite outro valor: ");
        scanf("%f", &valor);
        count++;
    }
    printf("A media e %.2f", soma/count);
}
