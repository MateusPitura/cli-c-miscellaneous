//Jogo de capturar a bolinha com thread

#include <stdio.h>
#include <pthread.h> //Para as threads
//#include <conio.h> //Para unix
//#include <unistd.h> //Para unix
#include <windows.h> //Para windows
#include <time.h> //Para windows: faz funcionar o "srand(time(NULL))";

//OBS.: salvar como .c

pthread_t t1; //Para as threads
pthread_t t2; //Para as threads

int tecla, colunaIcon=21, linhaIcon=9, colunaRand=0, linhaRand=0, score=0, controle=0; //Variaveis globais

// TEMPO INICIAL E BONUS
//***********************
int tempo=6;
int bonus=3;
//***********************

//Apenas para windows: cria uma funcao para windows equivalente ao gotoxy do unix 
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

//Serva apenas para comprimir as linhas repetitivas dos cases do switch
void imprimir(void){
    //system("clear"); //Para unix
    system("cls"); //Para windows
    gotoxy(colunaIcon, linhaIcon);  
    printf("^"); 
    gotoxy(colunaRand, linhaRand); 
    printf("o");
    //gotoxy(1, 1); //Para unix
    gotoxy(0,0); //Para windows
    printf("Score: %d    CAPTURE A BOLINHA    Time: %d\n\n", score, tempo);
}

void game(void){
    srand(time(NULL)); //Necessaria para fazer o rand gerar valores aleatorios
    //usleep(1*1000); //Para unix
	Sleep(1); //Para windows
    gotoxy(colunaIcon, linhaIcon);
    printf("^");
    while(colunaRand<0 || linhaRand==0 || colunaIcon==colunaRand || linhaIcon==linhaRand){ //Repete ate serem gerados valores validos
        colunaRand=rand() % 41; //Gera valores aleatorios na faixa de 0 a 41
        linhaRand=rand() % 16; //Gera valores aleatorios na faixa de 0 a 16
    }
    gotoxy(colunaRand, linhaRand);
    printf("o");
    while(1==1){
    	if(controle==1){ //Controle sera definida como 1 na funcao timer
    		//system("clear"); //Para unix
    		system("cls"); //Para windows
    		gotoxy(0,0);
    		printf("GAME OVER! Score: %d\n\n", score);
    		//exit(1); //Para unix
    		system("pause"); //Para computador
		}
        tecla=getch(); //Pega o valor de cada tecla digitada
        switch(tecla){
            case 97: //A
                colunaIcon--;
                if(colunaIcon<0) colunaIcon=0;
                imprimir();
                break;
            case 100: //D
                colunaIcon++; 
                if(colunaIcon==42) colunaIcon=41;
                imprimir();
                break;
            case 119: //S
                linhaIcon--;  
                if(linhaIcon==0) linhaIcon=1;
                imprimir();
                break;
            case 115: //W
                linhaIcon++;
                if(linhaIcon==17) linhaIcon=16;  
                imprimir();
                break;
            default: break;
        }
        if(colunaIcon==colunaRand && linhaIcon==linhaRand){ //Compara a posicao do icone com a posicao da bolinha
            gotoxy(colunaIcon, linhaIcon);
            printf("^");
            score++;
            linhaRand=0;
            while(colunaRand<0 || linhaRand==0 || colunaIcon==colunaRand || linhaIcon==linhaRand){ //Repete ate serem gerados valores validos
                colunaRand=rand() % 41; //Gera valores aleatorios na faixa de 0 a 41
                linhaRand=rand() % 16; //Gera valores aleatorios na faixa de 0 a 16
            }
            gotoxy(colunaRand, linhaRand);  
            printf("o");
            tempo+=bonus;
        }
    }
}

void timer(void){
    while(tempo>0){
    	//gotoxy(1,1); //Para unix
    	gotoxy(0,0); //Para  windows
    	printf("Score: %d    CAPTURE A BOLINHA    Time: %d", score, tempo);
    	//usleep(1000*1000); //Para unix
    	Sleep(1000); //Para windows
        tempo--;
    }
    //system("clear"); //Para unix
    system("cls"); //Para windows
    //gotoxy(1,1); //Para unix
    gotoxy(0,0); //Para windows
    printf("GAME OVER! Score: %d\n\n", score);
    controle=1;
    //exit(1); //Para unix
    system("pause"); //Para windows
}

int main(){
    pthread_create(&t1, NULL, (void *) game, NULL); //Para as threads
    pthread_create(&t2, NULL, (void *) timer, NULL); //Para as threads
    
    pthread_join(t1, NULL); //Para as threads
    pthread_join(t2, NULL); //Para as threads
}
