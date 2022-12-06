//Verifica se um numero e primo

#include <stdio.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int num, div=2;
	printf("Digite um numero: ");
	scanf("%d", &num);
	while(num>div){
	    if(num%div==0){
	        div=num;
	        printf("%d nao e primo \n", num);
		}  
	    div++;
	}
	if(div==num) printf("%d e primo \n", num);
	if(num<=1) printf("%d nao e primo \n", num);
}
