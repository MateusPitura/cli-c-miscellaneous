//Calcula a media dos 8 termos vizinhos de uma matriz

#include <stdio.h>
#define N 5

int main(void){
	int mat[N][N], val, linha, coluna, count=0;
	float media=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			mat[i][j]=N*i+j;
			printf("\t%d [%d]", mat[i][j], (i+1)*10+(j+1));
		}
		printf("\n");
	}
	do{
		printf("\nInforme um elemento: ");
		scanf("%d", &val);
		if(val<11 || val>55) printf("Digite um elemento valido");
	}while(val<11 || val>55);
	linha=val/10;
	coluna=val-linha*10;
	for(int i=linha-2; i<=linha; i++)
		for(int j=coluna-2; j<=coluna; j++)
			if((i>=0 && j>=0 && i<=4 && j<=4) && (i!=linha-1 || j!=coluna-1)){
				media+=mat[i][j]; 
				//printf("%d j: %d i: %d\n", mat[j][i], j, i);
				count++;
			}
	printf("%f, %f", media/count, media);
}
