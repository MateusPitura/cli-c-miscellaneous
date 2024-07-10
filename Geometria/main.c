//Realiza o escalonamento de uma matriz e calcula seu posto e a matriz inversa

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void mostra(float **matriz, int linhas, int colunas);

void trocaLinhas(float vetAux[], float **matriz, int linha1, int linha2, int colunas);

float **criaMatriz(int linhas, int colunas);

float *criaVetor(int tamanho);

void excluiMatriz(float **matriz, int linhas);

int posto(float **matriz, int linhas, int colunas);

int main(){
    float **matriz, **matrizInversa, *vetAux, escalar1, escalar2; 
    int flag, linhas, colunas, valorPosto, i, j, k, l, m, n, o;
    printf(" Digite o numero de linhas e colunas: ");
    scanf("%d %d", &linhas, &colunas);
    matriz=criaMatriz(linhas, colunas);
    matrizInversa=criaMatriz(linhas, colunas);
    vetAux=criaVetor(colunas);
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            if(i==j){
                matrizInversa[i][j]=1;
            }
            else{
                matrizInversa[i][j]=0;
            }
        }
    }
    for(n=0; n<linhas; n++){
        for(o=0; o<colunas; o++){
            printf(" Digite o elemento da posicao %dx%d: ", n+1, o+1);
            scanf("%f", &matriz[n][o]);
        }
    }
    mostra(matriz, linhas, colunas);
    for(i=0, j=0; i<linhas; i++, j++){
        flag=1;
        POINT1:
        if(matriz[i][j]==0){
            for(m=i+1; m<linhas && flag!=0; m++){
                if(matriz[m][j]!=0){
                    trocaLinhas(vetAux, matriz, i, m, colunas);
                    trocaLinhas(vetAux, matrizInversa, i, m, colunas);
                    flag=0;
                    printf("\n Trocou as linhas %d e %d de posicao\n", i+1, m+1);
                    mostra(matriz, linhas, colunas);
                    printf("\n Trocou as linhas %d e %d de posicao da Matriz Inversa\n", i+1, m+1);
                    mostra(matrizInversa, linhas, colunas);
                }
            }
            if(flag==1){
                j++;
                goto POINT1;
            }
        }
        for(k=i+1; k<linhas; k++){
            if(matriz[k][j]!=0){
                escalar1=(-1)*(matriz[k][j]/matriz[i][j]);
                for(l=0; l<colunas; l++){
                    matriz[k][l]=matriz[k][l]+escalar1*matriz[i][l];
                    matrizInversa[k][l]=matrizInversa[k][l]+escalar1*matrizInversa[i][l];
                }    
                printf("\n Somou a linha %d com a linha %d vezes %.2f\n", k+1, i+1, escalar1);
                mostra(matriz, linhas, colunas);  
                printf("\n Somou a linha %d com a linha %d vezes %.2f da Matriz Inversa\n", k+1, i+1, escalar1);
                mostra(matrizInversa, linhas, colunas);  
            }
        }
    }
    printf("\n\n=========================MATRIZ ESCALONADA=========================\n\n");
    mostra(matriz, linhas, colunas);
    printf("\n\n===================================================================\n\n");
    valorPosto=posto(matriz, linhas, colunas);
    for(i=1, j=1; i<linhas; i++, j++){
        while(matriz[i][j]==0){
            j++;
        }
        for(k=i-1; k>=0; k--){
            if(matriz[k][j]!=0){
                escalar1=(-1)*(matriz[k][j]/matriz[i][j]);
                for(l=0; l<colunas; l++){
                    matriz[k][l]=matriz[k][l]+escalar1*matriz[i][l];
                    matrizInversa[k][l]=matrizInversa[k][l]+escalar1*matrizInversa[i][l];
                }
                printf("\n Somou a linha %d com a linha %d vezes %.2f\n", k+1, i+1, escalar1);
                mostra(matriz, linhas, colunas);
                printf("\n Somou a linha %d com a linha %d vezes %.2f da Matriz Inversa\n", k+1, i+1, escalar1);
                mostra(matrizInversa, linhas, colunas);      
            }
        }
    }
    for(i=0, j=0; i<linhas; i++, j++){
        POINT3:
        if(matriz[i][j]!=1){
            escalar2=1/matriz[i][j];
            for(k=0; k<colunas; k++){
                matriz[i][k]=matriz[i][k]*escalar2;
                matrizInversa[i][k]=matrizInversa[i][k]*escalar2;
            }
            printf("\n Multiplicou a linha %d por %.2f\n", i+1, escalar2);
            mostra(matriz, linhas, colunas);
            printf("\n Multiplicou a linha %d por %.2f da Matriz Inversa\n", i+1, escalar2);
        	mostra(matrizInversa, linhas, colunas);
        }
        if(matriz[i][j]==0){
            j++;
            goto POINT3;
        }
    }
	printf("\n\n==========================MATRIZ INVERSA==========================\n\n");
    mostra(matrizInversa, linhas, colunas);
    printf("\n\n==================================================================\n\n");
    printf("\n O posto da matriz e %d\n\n", valorPosto);
    if(vetAux!=0){
    	free(vetAux);
	}
	excluiMatriz(matriz, linhas);
    excluiMatriz(matrizInversa, linhas);
    system("Pause");
}

void mostra(float **matriz, int linhas, int colunas){
    int i, j;
	printf("\n");
	for(i=0; i<linhas; i++){
		printf(" |");
        for(j=0; j<colunas; j++){
            printf("%10.2f", matriz[i][j]);
        }
        printf(" |");
        printf("\n");
    }
}

void trocaLinhas(float vetAux[], float **matriz, int linha1, int linha2, int colunas){
    int j;
    for(j=0; j<colunas; j++){
        vetAux[j]=matriz[linha1][j];
        matriz[linha1][j]=matriz[linha2][j];
        matriz[linha2][j]=vetAux[j];
    }
}

float **criaMatriz(int linha, int coluna){
    float **p;
    int i;
    p=(float **) malloc(linha*sizeof(float *));
    if(p==NULL){
        return NULL;
    }
    for(i=0; i<linha; i++){
        p[i]=(float *) malloc(coluna*sizeof(float));
        if(p[i]==NULL){
            return NULL;
        }
	}
    return p;  
}

float *criaVetor(int tamanho){
    float *v;
    v=(float *)malloc(tamanho*sizeof(float));
    return v;      
}

void excluiMatriz(float **matriz, int linhas){
    int i;
    if(matriz!=NULL){
        for(i=0; i<linhas; i++){
    		if (matriz[i]!=NULL){
    			free(matriz[i]);
			}
		}
        free(matriz);                
    }
}

int posto(float **matriz, int linhas, int colunas){
    int count=0, i, j;
    for(i=0, j=0; i<linhas && j<colunas; i++, j++){
        POINT2:
    	if(i<linhas && j<colunas){
    		if(matriz[i][j]!=0){
            	count++;
        	}
        	else{
            	j++;
            	goto POINT2;
        	}
		}
    }
    return count;
}
