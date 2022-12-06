//1 de 3 arquivos. Funcoes que desenham o menu

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define CINZA_CINZA 136 //CorFundo_CorTexto
#define PRETO_PRETO 0
#define AZUL_AZUL 153
#define AZUL_BRANCO 159 

void mudarCor(int cor){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void drawBloco(int coluna, int linha, int largura, int altura, int cor){
	mudarCor(cor);
	for(int i=coluna; i<largura+coluna; i++){
		for(int j=linha; j<altura+linha; j++){
			gotoxy(i, j);
			printf(" ");
		}
	}
}

void drawBotao(int coluna, int linha, int largura, int altura, int corSdw, int corBrd, int corCore, char *str){
	drawBloco(coluna+2, linha+1, largura, altura, corSdw);
	drawBloco(coluna, linha, largura, altura, corBrd);
	drawBloco(coluna+2, linha+1, largura-4, altura-2, corCore);
	gotoxy(coluna+3, linha+2);
	printf(str);
}

int keys(void){
	int tecla;
	tecla=getch();
	if(tecla==0 || tecla==0xE0){
		tecla=getch(); //Necessario para conseguir ler as setas. 0xE0: 224 em hexadecimal
	}
	return tecla;
}

void blocos(int pos, int auxPos, int corCore){
	switch(pos){
		case 1:
			blocos(auxPos, 0, AZUL_BRANCO);
			drawBotao(4, 1, 17, 5, CINZA_CINZA, PRETO_PRETO, corCore, "  Incluir  ");
			break;
		case 2:
			blocos(auxPos, 0, AZUL_BRANCO);
			drawBotao(4, 8, 17, 5, CINZA_CINZA, PRETO_PRETO, corCore, "  Alterar  ");
			break;
		case 3:	
			blocos(auxPos, 0, AZUL_BRANCO);
			drawBotao(4, 15, 17, 5, CINZA_CINZA, PRETO_PRETO, corCore, " Mudar Sit ");
			break;
		case 4:
			blocos(auxPos, 0, AZUL_BRANCO);
			drawBotao(4, 22, 17, 5, CINZA_CINZA, PRETO_PRETO, corCore, " Consultar ");
			break;
		case 5:
			blocos(auxPos, 0, AZUL_BRANCO);
			drawBotao(27, 1, 17, 5, CINZA_CINZA, PRETO_PRETO, corCore, "   Lista   ");
			break;
		case 6:
			blocos(auxPos, 0, AZUL_BRANCO);
			drawBotao(27, 8, 17, 5, CINZA_CINZA, PRETO_PRETO, corCore, "  Lixeira  ");
			break;
		case 7:	
			blocos(auxPos, 0, AZUL_BRANCO);
			drawBotao(27, 15, 17, 5, CINZA_CINZA, PRETO_PRETO, corCore, "  Excluir  ");
			break;
		case 8:
			blocos(auxPos, 0, AZUL_BRANCO);
			drawBotao(27, 22, 17, 5, CINZA_CINZA, PRETO_PRETO, corCore, "    End    ");
			break;
		default: break;
	}
}

void limparTexto(void){
	int i, j;
	mudarCor(112);
	for(i=50; i<140; i++){
		for(j=1; j<25; j++){
			gotoxy(i, j);
			printf(" ");
		}
	}
	
}
