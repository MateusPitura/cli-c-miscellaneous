//Multiplica dois valores usando apenas operacao basica de soma

#include <stdio.h>

int main(void){
    int num1, num2, produto=0;
    printf("Digite dois números: ");
    scanf("%d %d", &num1, &num2);
    for(int i=1; i<=abs(num2); i++) produto+=abs(num1);
    if(num1<0 ^ num2<0) printf("Produto: %d", produto*(-1));
    else printf("Produto: %d", produto);
}
