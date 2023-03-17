#include <stdio.h>
#include <stdlib.h>

void torreHanoi(int hasteAtual);
int informarPosicaoPeca(int haste);
void moverPeca(int hasteOrigem, int hasteDestino);
void iniciarTorre(int pecas);
void exibirTorre(void);
int informarHasteMenorPeca(int hasteAtual);
int descobrirHasteComplementares(int hastePrincipal, int *hasteA, int *hasteB);

int torre[8][3]={0};
int i=0;

int main(void){
    int pecas;
    scanf("%d", &pecas);
    iniciarTorre(pecas);
    exibirTorre();
    torreHanoi(1);
    printf("Resolvida em %d passos\n", i-1);
}

void torreHanoi(int hasteAtual){ //(se a maior peça das torres for uma maior || 1 para 4 || mais a esquerda) Mover a menor sem repetir
    i++;
    int hastePecaMenor=informarHasteMenorPeca(hasteAtual);
    int posicaoPecaMenor=informarPosicaoPeca(hastePecaMenor);
    if(hastePecaMenor==(-1)) return;
    if(posicaoPecaMenor==8){
        printf("Erro");
        exit(1); //A haste da menor peca nao pode estar vazia
    } 
    int hastePecaA, hastePecaB;
    descobrirHasteComplementares(hastePecaMenor, &hastePecaA, &hastePecaB);
    int posicaoPecaA=informarPosicaoPeca(hastePecaA);
    int posicaoPecaB=informarPosicaoPeca(hastePecaB);
    int posicaoHasteDesino, hastePecaDestino;
    if(posicaoPecaA!=8 && torre[posicaoPecaMenor][hastePecaMenor]==(torre[posicaoPecaA][hastePecaA]-1)){
        hastePecaDestino=hastePecaA;
        posicaoHasteDesino=posicaoPecaA;
    }
    else if(posicaoPecaB!=8 && torre[posicaoPecaMenor][hastePecaMenor]==(torre[posicaoPecaB][hastePecaB]-1)){
        hastePecaDestino=hastePecaB;
        posicaoHasteDesino=posicaoPecaB;
    }
    else if(posicaoPecaA!=8 && torre[posicaoPecaMenor][hastePecaMenor]==1 && torre[posicaoPecaA][hastePecaA]==4){
        hastePecaDestino=hastePecaA;
        posicaoHasteDesino=posicaoPecaA;
    }
    else if(posicaoPecaB!=8 && torre[posicaoPecaMenor][hastePecaMenor]==1 && torre[posicaoPecaB][hastePecaB]==4){
        hastePecaDestino=hastePecaB;
        posicaoHasteDesino=posicaoPecaB;
    }
    else{
        hastePecaDestino=hastePecaA;
        if(posicaoPecaA!=8 && torre[posicaoPecaMenor][hastePecaMenor]>torre[posicaoPecaA][hastePecaA]) hastePecaDestino=hastePecaB;
    }
    moverPeca(hastePecaMenor, hastePecaDestino);
    exibirTorre();
    torreHanoi(hastePecaDestino);
}

int informarPosicaoPeca(int haste){
    int i;
    for(i=0; i<8; i++){
        if(torre[i][haste]!=0){
            return i;
        }
    }
    return 8; //A torrre nao possui nenhuma peca
}

void moverPeca(int hasteOrigem, int hasteDestino){
    int posicaoPecaOrigem=informarPosicaoPeca(hasteOrigem);
    int posicaoPecaDestino=informarPosicaoPeca(hasteDestino)-1;
    torre[posicaoPecaDestino][hasteDestino]=torre[posicaoPecaOrigem][hasteOrigem];
    torre[posicaoPecaOrigem][hasteOrigem]=0;
}

void iniciarTorre(int quantidadePecas){
    int i;
    int pecas=quantidadePecas; 
    for(i=7; i>(7-quantidadePecas); i--){
        torre[i][0]=pecas--;
    }
}

void exibirTorre(void){
    int i, j;
    printf("\n");
    for(i=0; i<8; i++){
        printf("\t|");
        for(j=0; j<3; j++){
            printf(" %d |", torre[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int informarHasteMenorPeca(int hasteAtual){
    int hasteA, hasteB;
    descobrirHasteComplementares(hasteAtual, &hasteA, &hasteB);
    int posicaoHasteA=informarPosicaoPeca(hasteA);
    int posicaoHasteB=informarPosicaoPeca(hasteB);
    if(posicaoHasteA==8 && posicaoHasteB==8) return -1;
    if(posicaoHasteA==8) return hasteB;
    if(posicaoHasteB==8) return hasteA;
    if(torre[posicaoHasteA][hasteA]>torre[posicaoHasteB][hasteB]){
        return hasteB;
    }
    else{
        return hasteA;
    }
}

int descobrirHasteComplementares(int hastePrincipal, int *hasteA, int *hasteB){
    if(hastePrincipal==0){
        *hasteA=1;
        *hasteB=2;
    }
    else if(hastePrincipal==1){
        *hasteA=0;
        *hasteB=2;
    }
    else{
        *hasteA=0;
        *hasteB=1;
    }
}

/*
1 para 0 (se tiver uma peça uma unidade maior || 1 e 4 || mais a esquerda) mover a menor sem repetir
2 para 0 
1 para 2    Torre de 2 (3) 
3 para 0   
1 para 4 
2 para 3
1 para 2	Torre de 3 (7)
4 para 0 	
1 para 4 
2 para 5
1 para 2
3 para 4
1 para 0
2 para 3
1 para 2	Torre de 4 (15)
5 para 0 
1 para 0
2 para 5
1 para 2
3 para 0
1 para 4
2 para 3
1 para 2
4 para 5
1 para 4
2 para 0
1 para 2
3 para 4
1 para 0
2 para 3
1 para 2	Torre de 5 (31)
*/