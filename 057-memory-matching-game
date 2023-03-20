#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Para o srand
#include <windows.h> //Para o Sleep
//#include <math.h>

#define CODIGO_ASCII_A 65
#define POSICAO_MENOR_CARTA 11
#define TAMANHO_INT sizeof(int)
#define TAMANHO_CHAR sizeof(char)

int tamanhoTabuleiro=4;
char nomeJogadorAtual[11];
FILE *tabuleiro;

int exibirMenuPrincipal(void);
int jogarJogoMemoria(void);
void identificarJogador(void);
void criarArquivoJogador(void);
void exibirRank(void);
void organizarRank(void);
void escolherNivelJogo(void);
void inicializarTabuleiroCartas(void);
void exibirTabuleiro(void);
int gerarSimboloValido(void);
int gerarSimboloAleatorio(void);
int calcularQuantidadeSimbolos();
int gerarNumeroAleatorio(int menorNumeroAleatorio, int maiorNumeroAleatorio);
int contarRepeticoesTabuleiro(int simboloProcurado);
int contarZerosTabuleiro(void);
void escolherCarta(void);
void exibirCartasEscolhidas(int primeiraCartaEscolhida, int segundaCartaEscolhida);
int calcularLinhaEscolhida(int posicaoEscolhida);
int calcularColunaEscolhida(int posicaoEscolhida);
int verificarCartasEscolhidas(int primeiraCartaEscolhida, int segundaCartaEscolhida);
int calcularQuantidadeRegistros(FILE *fp);
void escreverArquivosPontuacao(int pontuacaoJogador);
void organizarRankScore(void);
int continuarPartida(void);

int main(void){
    srand(time(NULL));
    while(exibirMenuPrincipal()==1);
    return 0;
}

int exibirMenuPrincipal(void){
    int opcaoMenuJogador;
    system("cls");
    printf("1 - Jogar\n2 - Nivel\n3 - Continuar\n4 - Rank\n5 - Sair\n\nEscolha uma opcao: ");
    scanf("%d", &opcaoMenuJogador);
    fflush(stdin);
    switch(opcaoMenuJogador){
        case 1:
            escreverArquivosPontuacao(jogarJogoMemoria());
            fclose(tabuleiro);
            break;
        case 2:
            escolherNivelJogo();
            break;
        case 3:
            escreverArquivosPontuacao(continuarPartida());
            fclose(tabuleiro);
            break;
        case 4:
            exibirRank();
            break;
        case 5:
            return 0;
            break;
        default: 
            printf("Escolha invalida\n\n");
            system("pause");
            break;
    }
    return 1;
}

void escreverArquivosPontuacao(int pontuacaoJogador){
    FILE *rankPontuacaoJogadores=fopen("pontuacaoJogadores.txt", "a+b");
    if(rankPontuacaoJogadores==NULL){
        exit(1);
    } 
    fwrite(&pontuacaoJogador, TAMANHO_INT, 1, rankPontuacaoJogadores);
    fwrite(nomeJogadorAtual, TAMANHO_CHAR, 11, rankPontuacaoJogadores);
    fclose(rankPontuacaoJogadores);
}

int jogarJogoMemoria(){
    int tentativasJogador=0;
    identificarJogador();
    criarArquivoJogador();
    inicializarTabuleiroCartas();
    while(contarZerosTabuleiro()<(tamanhoTabuleiro*tamanhoTabuleiro)){
        escolherCarta();
        tentativasJogador++;
    }
    printf("\nTentativas: %d\n\n", tentativasJogador);
    system("pause");
    return tentativasJogador;
}

void identificarJogador(void){
    system("cls");
    printf("Informe seu nickname: ");
    scanf("%s", nomeJogadorAtual);
    fflush(stdin);
}

void criarArquivoJogador(void){
    tabuleiro=fopen(nomeJogadorAtual, "a+b"); //Cria caso não exista
    fclose(tabuleiro);
    tabuleiro=fopen(nomeJogadorAtual, "r+b"); //O a+b adiciona apenas no final, é necessáiro o r+b para sobreescrever
    if(tabuleiro==NULL){
        exit(1);
    }
}

void inicializarTabuleiroCartas(){
    int i, j;
    int simboloValido;
    int posicaoGerada;
    fseek(tabuleiro, 0, SEEK_SET);
    for(i=0; i<tamanhoTabuleiro; i++){
        for(j=0; j<tamanhoTabuleiro; j++){
            simboloValido=gerarSimboloValido();
            posicaoGerada=((i+1)*10)+(j+1);
            fwrite(&simboloValido, TAMANHO_INT, 1, tabuleiro);
            fwrite(&posicaoGerada, TAMANHO_INT, 1, tabuleiro);
        }
    }
}

int gerarSimboloValido(){
    int simboloAleatorio;
    do{
        simboloAleatorio=gerarSimboloAleatorio();
    }while(contarRepeticoesTabuleiro(simboloAleatorio)>=2); //2 é a quantidade de vezes que um numero deve se repetir
    return simboloAleatorio;
}

int gerarSimboloAleatorio(){
    int quantidadeSimbolosDiferentes=calcularQuantidadeSimbolos();
    return gerarNumeroAleatorio(CODIGO_ASCII_A, CODIGO_ASCII_A+quantidadeSimbolosDiferentes-1); //-1 pois o A também entra na contagem
}

int calcularQuantidadeSimbolos(){
    return (tamanhoTabuleiro*tamanhoTabuleiro)/2;
}

int gerarNumeroAleatorio(int menorNumeroAleatorio, int maiorNumeroAleatorio){
    return menorNumeroAleatorio+rand()%(maiorNumeroAleatorio-menorNumeroAleatorio+1);
}

int contarRepeticoesTabuleiro(int simboloProcurado){
    int count=0;
    int i, j;
    int simboloEncontrado;
    fseek(tabuleiro, 0, SEEK_SET);
    for(i=0; i<tamanhoTabuleiro; i++){
        for(j=0; j<tamanhoTabuleiro; j++){
            fread(&simboloEncontrado, TAMANHO_INT, 1, tabuleiro);
            if(simboloEncontrado==simboloProcurado){
                count++;
            }
            fread(&simboloEncontrado, TAMANHO_INT, 1, tabuleiro);
        }
    }
    return count;
}

int contarZerosTabuleiro(){
    int count=0;
    int i, j;
    int posicaoIdentificada;
    fseek(tabuleiro, 0, SEEK_SET);
    for(i=0; i<tamanhoTabuleiro; i++){
        for(j=0; j<tamanhoTabuleiro; j++){
            fread(&posicaoIdentificada, TAMANHO_INT, 1, tabuleiro);
            fread(&posicaoIdentificada, TAMANHO_INT, 1, tabuleiro);
            if(posicaoIdentificada==0){
                count++;
            }
        }
    }
    return count;
}

void escolherCarta(){
    int primeiraCartaEscolhida;
    int segundaCartaEscolhida;
    do{
        exibirTabuleiro();
        printf("\nEscolha a primeira carta: ");
        scanf("%d", &primeiraCartaEscolhida);
        printf("\nEscolha a segunda carta: ");
        scanf("%d", &segundaCartaEscolhida);
    }while(verificarCartasEscolhidas(primeiraCartaEscolhida, segundaCartaEscolhida)==0);
    exibirCartasEscolhidas(primeiraCartaEscolhida, segundaCartaEscolhida);
    Sleep(1000);
}

void exibirCartasEscolhidas(int primeiraCartaEscolhida, int segundaCartaEscolhida){
    int i, j;
    int cartaLida;
    int posicaoLida;
    fseek(tabuleiro, 0, SEEK_SET);
    system("cls");
    printf("\n");
    for(i=0; i<tamanhoTabuleiro; i++){
        for(j=0; j<tamanhoTabuleiro; j++){
            fread(&cartaLida, TAMANHO_INT, 1, tabuleiro);
            fread(&posicaoLida, TAMANHO_INT, 1, tabuleiro);
            if(posicaoLida==primeiraCartaEscolhida || posicaoLida==segundaCartaEscolhida || posicaoLida==0){
                printf("%5c", cartaLida);
            }
            else{
                printf("%5d", posicaoLida);
            }
        }
        printf("\n");
    }
}

void exibirTabuleiro(){
    int i, j;
    int cartaLida;
    int posicaoLida;
    fseek(tabuleiro, 0, SEEK_SET);
    system("cls");
    printf("\n");
    for(i=0; i<tamanhoTabuleiro; i++){
        for(j=0; j<tamanhoTabuleiro; j++){
            fread(&cartaLida, TAMANHO_INT, 1, tabuleiro);
            fread(&posicaoLida, TAMANHO_INT, 1, tabuleiro);
            if(posicaoLida==0){
                printf("%5c", cartaLida);
            }
            else{
                printf("%5d", posicaoLida);
            }
        }
        printf("\n");
    }
}

int verificarCartasEscolhidas(int primeiraCartaEscolhida, int segundaCartaEscolhida){
    int linhaPrimeiraCartaEscolhida=calcularLinhaEscolhida(primeiraCartaEscolhida);
    int colunaPrimeiraCartaEscolhida=calcularColunaEscolhida(primeiraCartaEscolhida);
    int linhaSegundaCartaEscolhida=calcularLinhaEscolhida(segundaCartaEscolhida);
    int colunaSegundaCartaEscolhida=calcularColunaEscolhida(segundaCartaEscolhida);
    int primeiraCartaLida;
    int segundaCartaLida;
    int primeiraPosicaoLida;
    int segundaPosicaoLinda;
    int variavelComZero=0;
    fseek(tabuleiro, TAMANHO_INT*((linhaPrimeiraCartaEscolhida*tamanhoTabuleiro)+colunaPrimeiraCartaEscolhida)*2, SEEK_SET);
    fread(&primeiraCartaLida, TAMANHO_INT, 1, tabuleiro);
    fread(&primeiraPosicaoLida, TAMANHO_INT, 1, tabuleiro);
    fseek(tabuleiro, TAMANHO_INT*((linhaSegundaCartaEscolhida*tamanhoTabuleiro)+colunaSegundaCartaEscolhida)*2, SEEK_SET);
    fread(&segundaCartaLida, TAMANHO_INT, 1, tabuleiro);
    fread(&segundaPosicaoLinda, TAMANHO_INT, 1, tabuleiro);
    if(primeiraCartaEscolhida==segundaCartaEscolhida){
        printf("A mesma carta foi escolhida duas vezes\n");
    }
    else if(primeiraCartaEscolhida<POSICAO_MENOR_CARTA || segundaCartaEscolhida<POSICAO_MENOR_CARTA){
        printf("Essa carta nao existe\n");
    }
    else if(linhaPrimeiraCartaEscolhida>=tamanhoTabuleiro || colunaPrimeiraCartaEscolhida>=tamanhoTabuleiro || linhaSegundaCartaEscolhida>=tamanhoTabuleiro || colunaSegundaCartaEscolhida>=tamanhoTabuleiro){
        printf("Essa carta nao existe\n");
    }
    else if(primeiraPosicaoLida==0 || segundaPosicaoLinda==0){
        printf("Essa carta ja foi revelada\n");        
    }
    else if(primeiraCartaLida==segundaCartaLida){
        fseek(tabuleiro, TAMANHO_INT*((linhaPrimeiraCartaEscolhida*tamanhoTabuleiro)+colunaPrimeiraCartaEscolhida)*2+TAMANHO_INT, SEEK_SET);
        fwrite(&variavelComZero, TAMANHO_INT, 1, tabuleiro);
        fseek(tabuleiro, TAMANHO_INT*((linhaSegundaCartaEscolhida*tamanhoTabuleiro)+colunaSegundaCartaEscolhida)*2+TAMANHO_INT, SEEK_SET);
        fwrite(&variavelComZero, TAMANHO_INT, 1, tabuleiro);
        return 1; //Em caso de acerto
    }
    else{
        return 1; //Em caso de erro
    }
    printf("\n");
    system("pause");
    return 0; //Entrada de cartas invalidas
}

int calcularLinhaEscolhida(int posicaoEscolhida){
    return (posicaoEscolhida/10)-1; //Mesmo que a divisão seja um número decimal, apenas a parte inteira retorna por ser int. -1 pois a matriz começa em 0
}

int calcularColunaEscolhida(int posicaoEscolhida){
    return (posicaoEscolhida-((posicaoEscolhida/10)*10))-1; //Ex.: 34/10=3 (po ser int a parte decimal é descartada). 3*10=30. 34-30=4. -1 pois a matriz começa em 0
}

void escolherNivelJogo(void){
    int opcaoNivelJogador;
    system("cls");
    printf("1 - Facil\n2 - Medio\n3 - Dificil\n\nEscolha um nivel: ");
    scanf("%d", &opcaoNivelJogador);
    fflush(stdin);
    switch(opcaoNivelJogador){
        case 1:
            tamanhoTabuleiro=2;
            break;
        case 2:
            tamanhoTabuleiro=4;
            break;
        case 3:
            tamanhoTabuleiro=6;
            break;
        default: 
            printf("Escolha invalida\n\n"); 
            system("pause");
            break;
    }
}

void exibirRank(void){
    organizarRankScore();
    system("cls");
    int pontuacaoJogador;
    char nomeJogador[11];
    int i;
    FILE *rankPontuacaoJogadores=fopen("pontuacaoJogadores.txt", "a+b");
    if(rankPontuacaoJogadores==NULL){
        exit(1);
    } 
    int quantidadeRegistrosJogadores=calcularQuantidadeRegistros(rankPontuacaoJogadores);
    fseek(rankPontuacaoJogadores, 0, SEEK_SET);
    printf("RANK DOS SCORES DOS JOGADORES\n\n");
    for(i=0; i<quantidadeRegistrosJogadores; i++){
        fread(&pontuacaoJogador, TAMANHO_INT, 1, rankPontuacaoJogadores);
        fread(nomeJogador, TAMANHO_CHAR, 11, rankPontuacaoJogadores);
        printf("Pontos: %-5d", pontuacaoJogador);
        printf("Nome: %10s\n", nomeJogador);
    }
    printf("\n");
    system("pause");
    fclose(rankPontuacaoJogadores);
}

void organizarRankScore(void){

}

int calcularQuantidadeRegistros(FILE *fp){
    fseek(fp, 0, SEEK_END);
    return ftell(fp)/((TAMANHO_CHAR*11)+TAMANHO_INT);
}

int continuarPartida(void){
    int tentativasJogador=0;
    identificarJogador();
    tabuleiro=fopen(nomeJogadorAtual, "r+b");
    //tamanhoTabuleiro=sqrt((ftell(tabuleiro)/TAMANHO_INT)/2);
    while(contarZerosTabuleiro()<(tamanhoTabuleiro*tamanhoTabuleiro)){
        escolherCarta();
        tentativasJogador++;
    }
    printf("\nTentativas: %d\n\n", tentativasJogador);
    system("pause");
    return tentativasJogador;
}
