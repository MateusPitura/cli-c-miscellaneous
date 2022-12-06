//Le valores e informar os 3 maiores. Negativo ou zero encerra o programa

#include <stdio.h>

int main(void){
    float num=1, maior1=0, maior2=0, maior3=0;
    while(num>0){
        printf("Digite um valor: ");
        scanf("%f", &num);
        if(num>maior3) maior3=num;
        if(num>maior2){
        	maior3=maior2;
        	maior2=num;
		}
		if(num>maior1){
			maior2=maior1;
			maior1=num;
		}
	}
    printf("Os 3 maiores valores: %.2f, %.2f, %.2f", maior1, maior2, maior3);
}
