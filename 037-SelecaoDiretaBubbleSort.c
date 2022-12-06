//Ordena por selecao direta e por bubble sort

#include <stdio.h>

int main(void){
	//Ordenacao por selecao direta
	int vet[20]={0, 5, 5, 6, 7, 9, 8, 8, 4, 1, 2, 3, 2, 4, 5, 6, 8, 9, 2, 8}, aux;
	for(int i=0; i<19; i++){
		for(int j=i+1; j<20; j++){
			if(vet[i]>vet[j]){
				aux=vet[i];
				vet[i]=vet[j];
				vet[j]=aux;
			}
		}
	}
	
	//Ordenacao por bubble sort
	for(int i=19; i>0; i--){
		for(int j=0; j<i; j++){
			if(vet[j]<vet[j+1]){
				aux=vet[j];
				vet[j]=vet[j+1];
				vet[j+1]=aux;
			}
		}
	}

  //Exibi o resultado
	for(int i=0; i<20; i++) printf("%d | ", vet[i]);
}
