//Tratamento de entradas

#include <stdio.h>

int main(){
    float num1=-1;
    while(abs((int)num1)!=num1){ // Recusa valor negativo e/ou com virgula, precisa inicializar num1 com valor com virgula ou negativo
    //while((int)num1!=num1){ // Recusa valor com virgula, precisa inicializar num1 com valor com virgula
    //while(fabs(num1)!=num1){ // Recusa valor negativo, precisa inicializar num1 com valor negativo. É bom usar math.h
	    printf("Digite um valor valido: ");
	    scanf("%f", &num1);
    }
    printf("Valor valido");
}
