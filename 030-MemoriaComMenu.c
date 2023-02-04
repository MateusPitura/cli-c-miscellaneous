//Jogo da memoria com menu

#include <stdio.h>
#include <windows.h> //Para mudarCor, system's etc.
#include <conio.h> //Para o getch()
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Declaração de constantes
const int AZUL_BRANCO=151, AMARELO_VERDE=226, LINHA_MINIMA=4, LINHA_MAXIMA=18, MENOR_COLUNA=20, MAIOR_COLUNA=35, COLUNA_INICIO_TEXTO=22;
#define tamTabuleiro 4

//Declaração de variaveis
int tecla, posicao=4, stop=1;
int tabuleiroAcertos[tamTabuleiro][tamTabuleiro]={0}, tabuleiroFiguras[tamTabuleiro][tamTabuleiro], figura, cont1=0, cont2, linFirst, colFirst, linSec, colSec, score, position; 

//Mudar a cor de fundo do texto e sua cor
void mudarCor(int cor){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

//Altera a posicao do cursor
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Muda o fundo do texto, escreve o texto dos menus
int mudarFundo(int linha, int cor){
	if(linha>LINHA_MAXIMA) posicao=LINHA_MAXIMA; //Para impedir de mover o cursor alem dos menus
	else if(linha<LINHA_MINIMA) posicao=LINHA_MINIMA; //Para impedir de mover o cursora alem dos menus
	gotoxy(COLUNA_INICIO_TEXTO, linha);
	mudarCor(cor);
	if(linha==4){
		printf("           ");
		gotoxy(COLUNA_INICIO_TEXTO, linha+1);
		printf("   START   ");
		gotoxy(COLUNA_INICIO_TEXTO, linha+2);
		printf("           ");
	}
	else if(linha==11){
        printf("           ");
		gotoxy(COLUNA_INICIO_TEXTO, linha+1);
		printf("  OPTIONS  ");
		gotoxy(COLUNA_INICIO_TEXTO, linha+2);
		printf("           ");
	}
	else if(linha==18){
        printf("           ");
		gotoxy(COLUNA_INICIO_TEXTO, linha+1);
	    printf("    END    ");
		gotoxy(COLUNA_INICIO_TEXTO, linha+2);
		printf("           ");
	}
	gotoxy(MENOR_COLUNA, 24);
	printf("!");
	mudarCor(240);
	printf("Use WS e ENTER");
}

//Desenho dos menus
int desenhoMenu(int linhaInicial, int linhaFinal, int linhaTextoInicial){
	mudarCor(0);
	for(int j=linhaInicial; j<linhaFinal; j++){
		for(int i=MENOR_COLUNA; i<MAIOR_COLUNA; i++){
			gotoxy(i, j);
			printf(" ");
		}
	}
	mudarFundo(linhaTextoInicial, AZUL_BRANCO);
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
	MAIN:
		score=0;
		system("Color F0"); //Fundo branco e texto preto
		//Desenho dos menus
	    desenhoMenu(3, 8, 4); //Menu start
	    desenhoMenu(10, 15, 11); //Menu credits
	    desenhoMenu(17, 22, 18); //Menu end
		//Escolha dos menus
		mudarFundo(4, AMARELO_VERDE);
		while(stop){
			mudarFundo(posicao+7, AZUL_BRANCO); //Voltar para azul
			mudarFundo(posicao-7, AZUL_BRANCO); //Voltar para azul
			gotoxy(0,0);
			tecla=getch();
			switch (tecla){
				case 119: //Valor ASCII do w
					posicao-=7;
					mudarFundo(posicao, AMARELO_VERDE);
					break;
				case 115: //Valor ASCII do s
					posicao+=7;
					mudarFundo(posicao, AMARELO_VERDE);
					break;
				case 13: //Valor ASCII do enter
					//Comandos do enter
					if(posicao==4){//Enter no start
						system("Color F0"); //Fundo branco e texto preto
						system("cls");
						gotoxy(0,0);
						//Inicio do codigo do jogo
					    char *posChar, figurasRepetidas[tamTabuleiro*tamTabuleiro+1]={0}; //{0} inicializa o vetor com todos os elementos iguais a 0
					    //Inicialização das letras do tabuleiroFiguras
					    srand(time(NULL));
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
					            gotoxy((j+1)*4, (i+1)*2);
					            printf("%c", tabuleiroFiguras[i][j]);
					        }
					        printf("\n");
					    }
					    Sleep(2000);
					    system("cls");
					    //Escolha das posições
					    while(score<(tamTabuleiro*tamTabuleiro)/2){
					        desenho();
					    	printf("\n\n\n Primeira carta: ");
					        do{
					            scanf("%d", &position);
					            fflush(stdin);
					            linFirst=position/10;
					            colFirst=position-(linFirst*10);
					            if(linFirst<1 || linFirst>tamTabuleiro || colFirst<1 || colFirst>tamTabuleiro){ //Caso o valores digitado seja menor que o menor e maior que o maior
					            	printf(" Invalido (digite junto, ex.: 13)! Primeira carta: ");
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
					            	printf(" Invalido (digite junto, ex.: 13)! Segunda carta: ");
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
						printf("VOCE VENCEU!");
						Sleep(2000);
						system("cls");
						posicao=4;
						goto MAIN;
						//Fim do codigo do jogo
					}
					else if(posicao==11){//Enter no credits
						system("Color F0"); //Fundo branco e texto preto
						system("cls");
						gotoxy(0,0);
						printf("Dificuldades (ainda nao funciona):\n1 - Facil\n2 - Medio\n3 - Dificil\n\nEscolha a dificuldade: ");
						int auxtamTabuleiro;
						do{
							scanf("%d", &auxtamTabuleiro);
							if(auxtamTabuleiro<1 || auxtamTabuleiro>3) printf("Entrada invalida! Escolha a dificuldade: ");
						}while(auxtamTabuleiro<1 || auxtamTabuleiro>3);
						system("cls");
						posicao=4;
						goto MAIN;
					}
					else{//Enter no end
						system("Color 0F");
						system("cls");
						gotoxy(0,0);
						stop=0;
					}
					break;	
			}
		}
}
