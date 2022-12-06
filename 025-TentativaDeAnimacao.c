//Tentativa de animacao

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void mudarCor(int cor){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

int main(void){
	//Céu azul
	mudarCor(48);
	for(int i=0; i<120; i++){
		for(int j=0; j<27; j++){
			gotoxy(i,j);
			printf(" ");
		}
	}
	//Chão verde
	mudarCor(47);
	for(int i=0; i<120; i++){
		gotoxy(i,27);
		printf("/");
	}
	//Chão marrom
	mudarCor(224);
	for(int i=0; i<240; i++){
		gotoxy(i,28);
		printf(" ");
	}
	//Canos cinzas
	for(int l=0; l<120; l++){
		int c=128;
		while(c>=48){
			mudarCor(c);
			for(int k=l; k<121; k+=16){
				for(int i=k; i<k+5; i++){
					for(int j=0; j<10; j++){
						gotoxy(i,j);
						printf(" ");
					}
					for(int j=17; j<27; j++){
						gotoxy(i,j);
						printf(" ");
					}
				}
			}
			c-=80;
			//Sleep(100);
		}
	}
	gotoxy(1,29);
	mudarCor(15);
}
