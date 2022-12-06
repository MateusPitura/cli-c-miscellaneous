//Le 50 fichas (altura, sexo) e informa maior/menor altura, altura media masculina e feminina, altura media

#include <stdio.h>

int main(void){
    int i=0, j=0;
    float sexo, altura, media=0, mediaMulher=0, mediaHomem=0, maiorAltura=0, menorAltura=3;
    while((i+j)<5){
    	printf("Digite a altura e o sexo (1: mulher e 2: homem): ");
        scanf("%f %f", &altura, &sexo);
    	if(altura>=3 || altura<=0 || (sexo!=1 && sexo!=2)) printf("Digite valores validos\n");
	    else{
	        if(altura>maiorAltura) maiorAltura=altura;
	        if(altura<menorAltura) menorAltura=altura;
	        if(sexo==1){
	            mediaMulher+=altura;
	            i++;
	        }
	        if(sexo==2){
	            mediaHomem+=altura;
	            j++;
			}
	        media+=altura;
    	}
    }
    printf("\nMaior altura: %.2f\nMenor altura: %.2f\nAltura media das mulheres: %.2f\nAltura media dos homens: %.2f\nAltura media da turma: %.2f", maiorAltura, menorAltura, mediaMulher/i, mediaHomem/j, media/(i+j));
}
