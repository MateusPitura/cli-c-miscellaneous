//Tentativa de fazer o Pacman

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <pthread.h>

#define LinMatrizMapa 19
#define ColMatrizMapa 29

//OBS.: salvar como .c

pthread_t t1; //Para as threads
pthread_t t2; //Para as threads

int matrizMapa[LinMatrizMapa][ColMatrizMapa]={{0}, 
						{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
						{0, 0, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 3, 0}, 
						{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, 
						{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0},
						{0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0},
						{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
						{2, 2, 2, 2, 2, 2, 0, 1, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1, 0, 2, 2, 2, 2, 2}, 
						{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0}, 
						{2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2},
						{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0},
						{2, 2, 2, 2, 2, 2, 0, 1, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 1, 0, 2, 2, 2, 2, 2},
						{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
						{0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0},
						{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0},
						{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
						{0, 0, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 3, 0},
						{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
						{0}};
int tecla=0;

void principal();

void mudarCor(int cor); //Muda a cor do cursor

void gotoxy(int x, int y); //Altera a posicao do cursor

void criarMapa(); //Gera o mapa do jogo

void verificaMovimento(); //Verifica para onde o PacMan pode se mover

void mover(int *point_score); //Move o PacMan

void apagaPacMan(int *point_pacMan); //Apaga a posicao anterior do PacMan

void imprimePacMan(int *point_pacMan); //Imprime a posicao atual do PacMan

void teclaPrecionada(); //Retorna a tecla precionada

int main(void){
	pthread_create(&t1, NULL, (void *) teclaPrecionada, NULL); //Para as threads
    pthread_create(&t2, NULL, (void *) principal, NULL); //Para as threads

    pthread_join(t1, NULL); //Para as threads
    pthread_join(t2, NULL); //Para as threads
}

void principal(){
	int score=0;
	criarMapa();
	mover(&score);
    gotoxy(40, 40); //Mensagem final de execucao
	mudarCor(0); //Preto
}

void mudarCor(int cor){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void criarMapa(){
	int i=0, j=0;
	for(i=0; i<LinMatrizMapa; i++){
		for(j=0; j<ColMatrizMapa; j++){
			gotoxy(j, i);
			if(matrizMapa[i][j]==0){
				mudarCor(153); //Azul
				printf("  ");
			}
			else if(matrizMapa[i][j]==1){
				mudarCor(14); //Amarelo
				printf("'");
			}
			else if(matrizMapa[i][j]==2){
				mudarCor(0); //Preto
				printf("  ");
			}
			else if(matrizMapa[i][j]==3){
				mudarCor(14); //Amarelo
				printf("O");
			}
		}
	}
}

void verificaMovimento(int *point_pacMan, int *point_movimentoValido){
	if(matrizMapa[point_pacMan[1]][point_pacMan[0]-1]!=0){
		point_movimentoValido[0]=1;
	}
	else{
		point_movimentoValido[0]=0;
	}
	if(matrizMapa[point_pacMan[1]][point_pacMan[0]+1]!=0){
		point_movimentoValido[1]=1;
	}
	else{
		point_movimentoValido[1]=0;
	}
	if(matrizMapa[point_pacMan[1]-1][point_pacMan[0]]!=0){
		point_movimentoValido[2]=1;
	}
	else{
		point_movimentoValido[2]=0;
	}
	if(matrizMapa[point_pacMan[1]+1][point_pacMan[0]]!=0){
		point_movimentoValido[3]=1;
	}
	else{
		point_movimentoValido[3]=0;
	}
}

void mover(int *point_score){
	int auxTecla=0;
	int pacMan[2]={15, 15}; //Posicao inicial (coluna, linha) do pacMan
	int movimentoValido[4]={0, 0, 0, 0}; //Se for 0 o movimento nao e valido, se for 1 o movimento e valido (esquerda, direita, cima, baixo)
	imprimePacMan(pacMan);
	for(;;){
		verificaMovimento(pacMan, movimentoValido);
		switch(tecla){
			case 75: 
				if(movimentoValido[0]==1){
					auxTecla=tecla;
					apagaPacMan(pacMan);
					pacMan[0]--; 
					imprimePacMan(pacMan);
				}
				else{
					tecla=auxTecla;
				}
				break;
			case 77: 
				if(movimentoValido[1]==1){
					auxTecla=tecla;
					apagaPacMan(pacMan);
					pacMan[0]++; 
					imprimePacMan(pacMan);
				}
				else{
					tecla=auxTecla;
				}
				break;
			case 72: 
				if(movimentoValido[2]==1){
					auxTecla=tecla;
					apagaPacMan(pacMan);
					pacMan[1]--; 
					imprimePacMan(pacMan);
				}  
				else{
					tecla=auxTecla;
				}
				break;
			case 80: 
				if(movimentoValido[3]==1){
					auxTecla=tecla;
					apagaPacMan(pacMan);
					pacMan[1]++; 
					imprimePacMan(pacMan);
				}
				else{
					tecla=auxTecla;
				}
				break;
			default: break;
		}
		if(matrizMapa[pacMan[1]][pacMan[0]]==1 || matrizMapa[pacMan[1]][pacMan[0]]==3){
			matrizMapa[pacMan[1]][pacMan[0]]=4;
			gotoxy(30, 0);
			printf("%d", *point_score+=1);
		}
		Sleep(250);
	}
}

void apagaPacMan(int *point_pacMan){
	gotoxy(point_pacMan[0], point_pacMan[1]);
	mudarCor(0); //Preto
	printf(" ");
}

void imprimePacMan(int *point_pacMan){
	gotoxy(point_pacMan[0], point_pacMan[1]);
	mudarCor(14); //Amarelo
	printf("X"); 
}

void teclaPrecionada(){
	for(;;){
		tecla=getch();
		if(tecla==0 || tecla==0xE0) tecla=getch(); //Necessario para conseguir ler as setas. 0xE0: 224 em hexadecimal
	}
	
}
