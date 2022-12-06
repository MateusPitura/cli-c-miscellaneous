//Jogo da memoria sem menu

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

const int tamTabuleiro=4; 
int tabuleiroAcertos[tamTabuleiro][tamTabuleiro]={0}, tabuleiroFiguras[tamTabuleiro][tamTabuleiro], figura, cont1=0, cont2, linFirst, colFirst, linSec, colSec, score=0, position;

//Altera a posicao do cursor
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Desenha as posicoes da tabela
int desenho(void){
    for(int linha=0; linha<tamTabuleiro; linha++){
        for(int coluna=0; coluna<tamTabuleiro; coluna++){
            gotoxy((coluna+1)*4, (linha+1)*2); //*4 e *2 e para distanciar os elementos um dos outros
            if(tabuleiroAcertos[linha][coluna]==1) printf("%c", tabuleiroFiguras[linha][coluna]); //tabuleiroAcertos inicializa com tudo igual a 0, quando uma figura esta certa ele recebe 1 na position da figura
            else printf("%d", (linha+1)*10+(coluna+1)); //Se linha=1 e coluna=1, vai mostrar 22
        }
    }
}

int main(void){
	system("Color F0"); //Fundo branco e texto preto
    char *posChar, figurasRepetidas[tamTabuleiro*tamTabuleiro+1]={0}; //{0} inicializa o vetor com todos os elementos iguais a 0
    //Inicialização das letras do tabuleiroFiguras
    srand(time(NULL));
    //gotoxy(0, 30);
    for(int i=0; i<tamTabuleiro; i++){
        for(int j=0; j<tamTabuleiro; j++){
            do{
                cont2=0;
                figura=65+rand()%(tamTabuleiro*tamTabuleiro)/2; //Gera valores de 65=A até 72=H (quando tamTabuleiro=4)
                posChar=strchr(figurasRepetidas, figura); //Passa para pozChar o ponteiro da figura em figurasRepetidas, caso aquela não apareça nesta pozChar receberá NULL
                while(posChar!=NULL){ //pozChar será NULL quando figura não aparececer em figurasRepetidas 
                    cont2++;
                    posChar=strchr(posChar+1, figura);
                }
            }while(cont2>=2); //Verifica quantas vezes figura aparece em figurasRepetidas, se aparecer 2 ou mais vezes eu recomeço pois não quero aquela figura
            tabuleiroFiguras[i][j]=figura;
            figurasRepetidas[cont1]=figura;
            cont1++;
            //printf("%c", tabuleiroFiguras[i][j]);
        }
        //printf("\n");
    }
    //Escolha das posições
    while(score<(tamTabuleiro*tamTabuleiro)/2){
        desenho();
    	printf("\n\n\n Primeira carta: ");
        do{
            scanf("%d", &position);
            fflush(stdin);
            linFirst=position/10;
            colFirst=position-(linFirst*10);
            if(linFirst<1 || linFirst>tamTabuleiro || colFirst<1 || colFirst>tamTabuleiro){ //Caso o valores digitado seja menor que o menor e maior que o mair
            	printf(" Invalido! Primeira carta: ");
            	position=0;
			}
			if(tabuleiroAcertos[linFirst-1][colFirst-1]==1){
				printf(" Essa carta ja foi revelada! Primeira carta: ");
				position=0;
			}
        }while(position==0);
        printf(" Segunda carta: ");
        do{
            scanf("%d", &position);
            fflush(stdin);
            linSec=position/10;
            colSec=position-(linSec*10);
            if(linSec<1 || linSec>tamTabuleiro || colSec<1 || colSec>tamTabuleiro){
            	printf(" Invalido! Segunda carta: ");
            	position=0;
			}
			if(tabuleiroAcertos[linSec-1][colSec-1]==1){
				printf(" Essa carta ja foi revelada! Segunda carta: ");
				position=0;
			}
			if(linFirst==linSec && colFirst==colSec){
				printf(" Essa posicao ja foi escolhida! Segunda carta: ");
				position=0;
			}
        }while(position==0);
        //Mostra a figura da carta escolhida
	    gotoxy(colFirst*4, linFirst*2);
	    printf("%c ", tabuleiroFiguras[linFirst-1][colFirst-1]);
	    gotoxy(colSec*4, linSec*2);
	    printf("%c ", tabuleiroFiguras[linSec-1][colSec-1]);
	    Sleep(1500);
        system("cls");
		if(tabuleiroFiguras[linFirst-1][colFirst-1]==tabuleiroFiguras[linSec-1][colSec-1]){ //Compara se duas figuras são iguais
			tabuleiroAcertos[linFirst-1][colFirst-1]=1;
			tabuleiroAcertos[linSec-1][colSec-1]=1;
			score++;
		}
	}
}
