//Informa-se uma data e mostra a qual dia representa no ano

#include <stdio.h>

int main(void){
	int dia=1, mes=1, ano=1900, diaMax[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, soma=0;
	do{
		printf("Informe um dia: ");
		scanf("%d", &dia);
		fflush(stdin);
		if(dia<1 || dia>31) printf("Digite um dia valido\n");
	}while(dia<1 || dia>31);
	do{
		printf("Informe um mes: ");
		scanf("%d", &mes);
		fflush(stdin);
		if(mes<1 || mes>12) printf("Digite um mes valido\n");
	}while(mes<1 || mes>12);
	do{
		printf("Informe um ano: ");
		scanf("%d", &ano);
		fflush(stdin);
		if(ano<1900 || ano>2100) printf("Digite um ano valido\n");
	}while(ano<1900 || ano>2100);
	if(((ano%4)==0 && (ano%100)!=0) || (ano%400)==0) diaMax[1]=29;
	if(dia>diaMax[mes-1]) printf("Data invalida");
	else{
		for(int i=0; i<mes-1; i++) soma+=diaMax[i];
		printf("%d/%d/%d e o dia %d deste ano", dia, mes, ano, soma+dia);
	}
}
