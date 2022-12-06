//Verifica se um numero e perfeito (a soma de seus divisores, exceto ele mesmo, e ele mesmo)

#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	int num, div, soma=0;
	printf("Digite um numero: ");
	scanf("%d", &num);
	div=num-1;
	while(div>0){
		if(num%div==0) soma=soma+div;
		div=div-1;
	}
	if(soma==num) printf("%d e um numero perfeito \n", num);
	else printf("%d nao e um numero perfeito \n", num);
}
