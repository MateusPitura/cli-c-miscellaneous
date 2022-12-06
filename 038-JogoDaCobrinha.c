#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <pthread.h>
#include <time.h>

//OBS.: salvar como .c

pthread_t t1; //Para as threads
pthread_t t2; //Para as threads

//Variaveis globais
char corpo[2][50]={0}, tecla; //x: corpo[0][i] y: corpo[1][i]
int auxTecla=77, corpoMax=1, larMax=50, altMax=25, i, j, k=0, linBol, colBol, proporsion, control, score=0, speed=250, filtro1=5, filtro2=5;

//Constantes
int const LAR=50, ALT=25;

//Altera a posicao do cursor
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Altera a cor da letra e do fundo
void mudarCor(int cor){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

//Desenha o painel
void painel(void){
    //Texto do cabecalho
	mudarCor(15);
	gotoxy(53, 1);
	printf("JOGO DA COBRINHA");
	gotoxy(53, 3);
	printf("Score: %d", score);
	//Texto do "aumenta o tamanho"
	mudarCor(96);
	gotoxy(53, 5);
	printf(" ");
	mudarCor(15);
	printf(" Aumenta o tamanho");
	//Texto do "aumenta a velocidade"
	mudarCor(16);
	gotoxy(53, 7);
	printf(" ");
	mudarCor(15);
	printf(" Aumenta a velocidade");
	//Texto do "diminui o mapa"
	mudarCor(64);
	gotoxy(53, 9);
	printf(" ");
	mudarCor(15);
	printf(" Diminui o mapa");
	//Texto instrucoes
	gotoxy(53, 11);
	printf("Usa as setas para mover");
}

//Desenha o mapa
void geraMapa(void){
	for(i=0; i<LAR; i++)
		for(j=0; j<ALT; j++){
			gotoxy(i, j);
			printf(" ");	
		}
}
	
//Contorna de preto as bordas para nao aparecer rastro branco da cobra quando o mapa diminuir
void contorno(void){
	mudarCor(15);
	for(i=50; i>=0; i--) //Faz um retangulo com a base maior que a largura
		for(j=25; j>=altMax; j--){
			gotoxy(i, j);
			printf(" ")	;
		}
	for(i=50; i>=larMax; i--) //Faz um retangulo com a base menor que a largura
		for(j=25; j>=0; j--){
			gotoxy(i, j);
			printf(" ")	;
		}
}

//Gerar bolinhas aleatorias
void bolinhas(void){
	srand(time(NULL));
	do{
		control=0;
		linBol=rand()%altMax; //Gera a posicao da bolinha
		colBol=rand()%larMax;
		for(i=0; i<=corpoMax; i++) //Verifica se a bolinha gerada nao esta numa mesma posicao que o corpo
			if(corpo[0][i]==colBol && corpo[1][i]==linBol) control=1;
	}while(control==1); //Repete ate gerar uma bolinha que nao esta numa posicao do corpo
	gotoxy(colBol, linBol);
    if(speed==50) filtro1=3; //Isso vai impedir que quando a velocidade maxima seja atingida novas bolinhas azuis sejam geradas
    if(larMax==10) filtro2=4; //Isso vai impedir que quando o mapa atinga o tamanho minimo novas bolinhas vermelhas sejam geradas
    do{
        proporsion=rand()%5; //Gera valores para que as bolinhas aparecam na proporcao 3/1/1 (amarelo, azul, vermelho)
    }while(proporsion==filtro1 || proporsion==filtro2); //Impede que novas bolinhas azuis ou vermelhas sejam geradas caso os limites sejama atingidos
	if(proporsion>=0 && proporsion<=2) mudarCor(96); //Amarelo
	else if(proporsion==3) mudarCor(16); //Azul
	else mudarCor(64); //Vermelho
	printf(" ");
}

//Confere se a bolinha foi capturada ou se a cobra morreu
void hitBox(void){
	if(corpo[0][0]==colBol && corpo[1][0]==linBol){ //Se a posicao da cebeca for igual da bolinha
		if(proporsion>=0 && proporsion<=2) corpoMax++; //Se capturar a bolinha amaela aumenta de tamanho
		else if(proporsion==3) speed-=50; //Se capturar a bolinha azul aumenta a velocidade
		else{ //Se capturar a bolinha vermelha diminui o mapa
			altMax-=5;
			larMax-=10;
			k=corpoMax; //Para saber quantas vezes deve ser chamar a funcao contorno
		}
		score++;
		painel();
		bolinhas();
	}
	for(j=0; j<=corpoMax; j++) //Se a posicao de alguma parte do corpo for igual a outra parte do corpo, encerra o game
		for(i=j+1; i<=corpoMax; i++)
			if(corpo[0][j]==corpo[0][i] && corpo[1][j]==corpo[1][i]){
				gotoxy(53, 13);
				mudarCor(228);
				printf("GAME OVER!");
				mudarCor(15);
				Sleep(5000);
				exit(0);
			}
}

//Mudar posicao da cebeca
void changePosi(int coluna, int linha){
	mudarCor(255);
	for(i=0; i<corpoMax; i++){
		gotoxy(corpo[0][i], corpo[1][i]); //Vai para as posicoes do corpo e apaga (troca a cor da posicao por preto)
		printf(" ");
	}
	for(i=corpoMax-1; i>=0; i--){ //posiciona cada termo da matriz um termo para frente {3, 4, 2, 1} -> {_, 4, 3, 2} (assim as posicoes anteriores sao salvas e atualizadas a cada movimento)
		corpo[0][i+1]=corpo[0][i];
		corpo[1][i+1]=corpo[1][i];
	}
	corpo[0][0]=corpo[0][1]+coluna; //a cabeca (corpo[0][0]) recebe o termo anterior +/- 1: {_, 4, 3, 2} -> {4+/-1, 4, 3, 2}
	corpo[1][0]=corpo[1][1]+linha;
	if(corpo[0][0]<0) corpo[0][0]+=larMax; //Teletransporta a cobra para oposto
	else if(corpo[0][0]>=larMax) corpo[0][0]=0;
	if(corpo[1][0]<0) corpo[1][0]+=altMax;
	else if (corpo[1][0]>=altMax) corpo[1][0]=0;
	mudarCor(175);
	gotoxy(corpo[0][0], corpo[1][0]);
		printf(":");
	mudarCor(160);
	for(i=1; i<corpoMax; i++){
		gotoxy(corpo[0][i], corpo[1][i]); //Vai para as posicoes e muda a cor para verde
		printf(":");	
	}
	if(k>0){ //k>0 so quando a cobra capturar uma bolinha vermelha, corresponde ao tamanho da cobra
		contorno();
		k--;
	}
	hitBox();
	Sleep(speed); 
}

void keys(void){
	for(;;){
		tecla=getch();
		if(tecla==0 || tecla==0xE0) tecla=getch(); //Necessario para conseguir ler as setas. 0xE0: 224 em hexadecimal
	}
}

void game(void){
	painel();
    mudarCor(255);
	geraMapa();
	bolinhas();
	for(;;){
		switch(tecla){
			case 75: //Esquerda
				if(corpoMax!=1 && auxTecla==77) tecla=77; //Caso a pessoa digite D quando a cobra estiver indo para a esquerda, nada acontece
                else{
                    auxTecla=tecla;
				    changePosi(-1, 0); 
                }
				break;
			case 77: //Direita
				if(corpoMax!=1 && auxTecla==75) tecla=75;
                else{
                    auxTecla=tecla;
				    changePosi(1, 0);
                }
				break; 
			case 80: //Baixo
				if(corpoMax!=1 && auxTecla==72) tecla=72;
                else{
                    auxTecla=tecla;
				    changePosi(0, 1);
                }
				break; 
			case 72: //Cima
				if(corpoMax!=1 && auxTecla==80) tecla=80;
                else{
                    auxTecla=tecla;
				    changePosi(0, -1);
                }
				break; 
			default: tecla=auxTecla;
		}	
	}
}

int main(){
    pthread_create(&t1, NULL, (void *) keys, NULL); //Para as threads
    pthread_create(&t2, NULL, (void *) game, NULL); //Para as threads

    pthread_join(t1, NULL); //Para as threads
    pthread_join(t2, NULL); //Para as threads
}
