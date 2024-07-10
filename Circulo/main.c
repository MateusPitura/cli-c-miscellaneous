//Desenha circulo colorido aleatoriamente

#include <stdio.h>
#include <windows.h>
#include <math.h>
#include <time.h>

//Altera a posicao do cursor
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Mudar a cor de fundo do texto e sua cor
void mudarCor(int cor){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

float y;

//Equacao geral da circuferencia
float equaCircu(float x, float raio, float centroX, float centroY){
	y=sqrt(-pow(centroX,2)+2*centroX*x+pow(raio,2)-pow(x,2))+centroY;
	return y;
}

float equaCircuNeg(float x, float raio, float centroX, float centroY){
	y=-1*sqrt(-pow(centroX,2)+2*centroX*x+pow(raio,2)-pow(x,2))+centroY;
	return y;
}

int main(){
	srand(time(NULL));
	float controle;
	int cor;
	for(int raio=15; raio>0; raio--){
		cor=16+rand()%239;
		mudarCor(cor);
		for(float i=1; i<=35; i+=0.01){
			controle=equaCircu(i, raio, 20, 20)/1.5;
			if(controle>0 && controle<100){
				gotoxy(i, controle);
				printf(" ");
			}
			controle=equaCircuNeg(i, raio, 20, 20)/1.5;
			if(controle>0 && controle<100){
				gotoxy(i, controle);
				printf(" ");
			}
		}
	}
	mudarCor(0);
	gotoxy(0, 25);
}
