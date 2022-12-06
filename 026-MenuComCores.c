//Selecao de menu com cores

#include <stdio.h>
#include <windows.h> //Para mudarCor, system's etc.
#include <conio.h> //Para o getch()

//Declaração de constantes
const int AZUL_BRANCO=151, AMARELO_VERDE=226, LINHA_MINIMA=4, LINHA_MAXIMA=18, MENOR_COLUNA=20, MAIOR_COLUNA=35, COLUNA_INICIO_TEXTO=22;

//Declaração de variaveis
int tecla, posicao=4, stop=1;

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

//Muda o fundo do texto, escreve o texto dos menus, 
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
		printf("  CREDITS  ");
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

int main(void){
	system("Color F0"); //Fundo branco e texto preto
	//Desenho dos menus
    desenhoMenu(3, 8, 4); //Menu start
    desenhoMenu(10, 15, 11); //Menu credits
    desenhoMenu(17, 22, 18); //Menu end
	//Escolha dos menus
	{
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
					{
						if(posicao==4){//Enter no start
							system("Color 0F");
							system("cls");
							gotoxy(0,0);
							printf("O programa inicializou corretamente!");
							stop=0;
						}
						else if(posicao==11){//Enter no credits
							system("Color 0F");
							system("cls");
							gotoxy(0,0);
							printf("Desenvolvido por Mateus Pitura");
							stop=0;
						}
						else{//Enter no end
							system("Color 0F");
							system("cls");
							gotoxy(0,0);
							stop=0;
						}
						break;	
					}//Fim Comandos do enter
			}
		}
	}//Fim Escolha dos menus
}
