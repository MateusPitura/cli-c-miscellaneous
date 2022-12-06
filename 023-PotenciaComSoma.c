//Calcula a potencia de um valor apenas com operacao de soma

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    int auxBase, produto=1, negativo=1;
    float base, expoente=-1;
    while(abs((int)expoente)!=expoente || (int)base!=base){
    	system("cls");
    	printf("Digite a base (inteiro) e o expoente (natural): ");
    	scanf("%f %f", &base, &expoente);		
	}
    if(expoente==1) printf("Potencia: %d\n", base);
	else{
		if(base<0 && (int)expoente%2!=0) negativo=-1;
		auxBase=base;
    	for(int j=1; j<expoente; j++){
    		produto=0;
	    	for(int i=0; i<abs(auxBase); i++) produto+=abs(base);
			base=produto;
		}
		printf("Potencia: %d\n", produto*negativo);
	}
}
