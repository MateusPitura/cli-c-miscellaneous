//Calcula o fatorial de um numero

#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");
    int num, soma=1;
    printf("Digite um numero: ");
    scanf("%d", &num);
    if(num>=0){
        while(num>1){
            soma=soma*num;
            num=num-1;
        }
        printf("Seu fatorial e %d", soma);
    }
    else printf("Erro: numero menor que 0");
}
