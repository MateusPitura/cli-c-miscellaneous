// 1 de 3 arquivos. Funcoes para desenhar o menu

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define CINZA_CINZA 136 //CorFundo_CorTexto
#define PRETO_PRETO 0
#define AZUL_BRANCO 159 
#define AMARELO_VERDE 226

//Escopos de draw
void mudarCor(int cor);
void gotoxy(int x, int y);
void drawBloco(int coluna, int linha, int largura, int altura, int cor);
void drawBotao(int coluna, int linha, int largura, int altura, int corSdw, int corBrd, int corCore, char *str);
int keys(void);
void blocos(int pos, int auxPos, int corCore);

//Escopo de cad
#define CPF 12
#define NAME 50

void principal(int option);
void copiar(FILE *fpi, FILE *fpo);
FILE *fileOpen(char *arqName, char *mode);
void clear(char *str, int tamanho);
int validaStr(char *str, int tamanho, int rangeMin, int rangeMax);
int filelen(FILE *fp);
int busca(char *wtdCpf);
int incluir(void);
int alterar(void);
int situacao(void);
int consultar(void);
void listar(char sit);
void cleanTrash(void);
void limparTexto(void);

int main(void){
	system("mode con:cols=140 lines=31"); //Redimensiona o tamanho do prompt de execucao
	int tecla=72, pos=2, auxPos; //Esses valores fazem o primeira bloco comecar marcado
	system("Color 70"); //Fundo branco
	gotoxy(14, 29);
	mudarCor(AZUL_BRANCO);
	printf("!");
	mudarCor(112);
	printf(" Use as setas e Enter");
	for(int i=1; i<=8; i++){
		blocos(i, 0, AZUL_BRANCO);
	}
	do{
		auxPos=pos;
		switch(tecla){
			case 72: if(pos>1) pos--; break; //Seta pra cima. O limite e para impedir que estoure do range
			case 80: if(pos<8) pos++; break; //Seta pra baixo
			case 75: if(pos>4) pos-=4; break; //Seta pra esquerda
			case 77: if(pos<5) pos+=4; break; //Seta pra direita
			case 13: limparTexto(); principal(pos); break; //Enter
			default: break;
		}
		blocos(pos, auxPos, AMARELO_VERDE);
		tecla=keys();
	}while(tecla!=27); //Esc
	gotoxy(0, 27); //Para o texto de final de execucao
	mudarCor(112); //Cinza_Preto
}
