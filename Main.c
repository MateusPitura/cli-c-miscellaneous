/*SUMARIO
1 - CALCULO DA MEDIA DE 3 NOTAS
2 - MOSTRA SE E PAR OU IMPAR
3 - CALCULO IMC
4 - CATEGORIA DO NADADOR (EXERCICIO 25)
5 - PESO EM OUTROS PLANETAS (EXERCICIO 43)
6 - MOSTRA "M" GRANDE
7 - CALCULA O MAIOR VALOR
8 - INFORME SE FORMA TRIANGULO E O CLASSIFICA
9 - CALCULA AS COLORIAS DE UMA REFEICAOO (EXERCICIO 39)
10 - MOSTRA O ENESIMO TERMO DA SEQUENCIA DE FIBONACCI (1, 1, 2, 3, 5, 8, 13...)
11 - VERIFICA SE E PRIMO
12 - VERIFICA SE E PERFEITO (A SOMA DE SEUS DIVISORES, EXCETO ELE MESMO, E ELE MESMO)
13 - MEDIA DE N TERMOS
14 - CALCULA O FATORIAL
15 - MULTIPLICA DOIS VALORES USANDO APENAS SOMAS
16 - DIVIDE DOIS VALORES USANDO APENAS SUBTRACOES
17 - TRATAMENTO DE ENTRADAS
18 - (EXERCICIOS 17/06) Calculo de S, sendo N informado pelo usuario S = 1/1 + 1/2 + 1/3 + 1/4 + ... + 1/N
19 - (EXERCICIOS 17/06) Fatoracao de um valor inteiro (reais) em notas de 100, 50, 10, 5 e 1
20 - (EXERCICIOS 17/06) Calculo de S, sendo N informado pelo usuario S = 1/N + 2/(N-1) + 3/(N-2) + 4/(N-3) + ... + (N-1)/2 + N/1
21 - (EXERCICIOS PARA 24/06/2022) Leia 50 fichas (altura, sexo) e informe maior/menor altura, altura media masculina e feminina, altura media
22 - (EXERCICIOS PARA 24/06/2022) Ler valores e informar os 3 maiores. Negativo ou zero encerra o programa
23 - (EXERCICIOS PARA 24/06/2022) Dado um numero inteiro, eleve a uma potencia usando apenas soma
24 - CHICO TEM 1.5 METRO E CRESCE 2 CM AO ANO, JUCA TEM 1.1 METRO E CRESCE 3 CM AO ANO, DAQUI QUANTOS ANOS JUCA VAI SER MAIS QUE CHICO
25 - TENTATIVA DE ANIMACAO
26 - SELECAO DE MENUS COM CORES
27 - (TRABALHO DO ALCEU DE STRINGS) Contar quantidade de palavras, letras e vogai
28 - (TRABALHO DO ALCEU DE STRINGS) Jogo da forca
29 - JOGO DA MEMORIA
30 - JOGO DA MEMORIA COM MENU
31 - JOGO DA VELHA
32 - CAPTURE A BOLINHA
33 - DESENHO DE CIRCULO COLORIDO ALEATORIAMENTE
34 - INFORMA-SE UMA DATA E MOSTRA A QUAL DIA REPRESENTA NO ANO
35 - MEDIA DOS 8 TERMOS VIZINHOS DE UMA MATRIZ
36 - VERIFICA SE E UM PALINDROMO 
37 - ORDENAÇÃO POR SELEÇÃO DIRETA E POR BUBBLE SORT
38 - JOGO DA COBRINHA
39 - ESCALONAMENTO, POSTO E INVERSA
40 - PACMAN
41 - CONTA QUANTIDADE DE PALAVARAS, LINHAS E CARACTERES
42 - CRIPTOGRAFIA DE ARQUIVOS
43 - MANUTENCAO DE CADASTRO
44 - 
45 -
*/

/*1*/
/*
#include <stdio.h> 

int main(){
    printf("Informe as notas: ");
    int valor1, valor2, valor3, media;
    scanf("%d %d %d", &valor1, &valor2, &valor3);
    media = (valor1 + valor2 + valor3)/3;
    printf("A media de suas notas e %d", media);
    return 0;
}
*/

/*2*/
/*
#include <stdio.h>

int main(){
    int valor, divisao;
    printf("Informe um valor: ");
    scanf("%d", &valor);
    divisao = valor % 2;
    if(divisao == 0){
        printf("%d e par", valor);
    }
    else{
        printf("%d e impar", valor);
    }
    return 0;
}
*/

/*3*/
/*
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
    float PesoAtual, Altura, Imc, PesoIdeal, Kilos;
    printf("Informe seu peso em kilogramas: ");
    setlocale(LC_ALL, "Portuguese");
    scanf("%f", &PesoAtual);
    printf("Informe sua altura em metros: ");
    scanf("%f", &Altura);
    Imc=PesoAtual/pow(Altura,2);
    printf("Seu IMC e %.2f \n", Imc);
    if(Imc<20){
        printf("Abaixo do peso\n");
        PesoIdeal=20*pow(Altura,2);
        Kilos=PesoIdeal-PesoAtual;
        printf("E necessario ganhar %.2f kilogramas, seu peso ideal e %.2f", Kilos, PesoIdeal);
    }
        else if(Imc<25) printf("Peso normal\nMantenha seu peso");
            else if(Imc<30){
                printf("Sobrepeso\n");
                PesoIdeal=25*pow(Altura,2);
                Kilos=PesoAtual-PesoIdeal;
                printf("E necessario perder %.2f kilogramas, seu peso ideal e %.2f", Kilos, PesoIdeal);
            }
                else if(Imc<40){
                    printf("Obeso\n");
                    PesoIdeal=25*pow(Altura,2);
                    Kilos=PesoAtual-PesoIdeal;
                    printf("E necessario perder %.2f kilogramas, seu peso ideal e %.2f", Kilos, PesoIdeal);
                }
                    else{
                        printf("Obeso morbido\n");
                        PesoIdeal=25*pow(Altura,2);
                        Kilos=PesoAtual-PesoIdeal;
                        printf("E necessario perder %.2f kilogramas, seu peso ideal e %.2f", Kilos, PesoIdeal);
                    }
    return 0;
}
*/

/*4*/
/*
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int idade;
    printf("Informe sua idade: ");
    scanf("%d", &idade);
    if(idade<=5) printf("Sem categoria, menor de 5 anos");
        else if(idade<=7) printf("Categoria infantial A");
            else if(idade<=10) printf("Categoria infantil B");
                else if(idade<=13) printf("Categoria juvenil A");
                    else if(idade<=17) printf("Categproa juvenil B");
                        else printf("Categoria senior");
    return 0;
}
*/

/*5*/
/*
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float PesoTerra;
    int Planeta;
    printf("Informe seu peso em kilogramas: ");
    scanf("%f", &PesoTerra);
    printf("1: Mercurio\n2: Venus\n3: Marte\n4: Jupiter\n5: Saturno\n6: Urano\nEscolha um planeta digitando seu numero: ");
    scanf("%d", &Planeta);
    switch (Planeta){
        case 1: printf("Seu peso em Mercurio e %.2f kilogramas", PesoTerra*0.37); break;
        case 2: printf("Seu peso em Venus e %.2f kilogramas", PesoTerra*0.88); break;
        case 3: printf("Seu pesso em Marte e %.2f kilogramas", PesoTerra*0.38); break;
        case 4: printf("Seu peso em Jupiter e %.2f kilogramas", PesoTerra*2.64); break;
        case 5: printf("Seu peso em Saturno e %.2f kilogramas", PesoTerra*1.15); break;
        case 6: printf("Seu pesso em Urano e %.2f kilogramas", PesoTerra*1.17); break;
        default: printf("Voce digitou um numero que nao corresponde a um planeta"); break;
    }
    return 0;
}
*/

/*6*/
/*
#include <stdio.h>

int main(){
    printf(" ___  ___ \n");
    printf("|   \\/   |\n");
    printf("| |\\  /| |\n");
    printf("| | \\/ | |\n");
    printf("| |    | |\n");
    printf("|_|    |_|");
    return 0;
}
*/

/*7*/
/*
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float A, B, C;
    printf("Digite 3 valores: ");
    scanf("%f %f %f", &A, &B, &C);
    if (A>B && A>C) printf("%.2f e o maior valor", A);
        else if(B>C) printf("%.2f e o maior valor", B);
            else printf("%.2f e o maior valor", C);
    return 0;
}
*/

/*8*/   
/*
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float A, B, C; 
    printf("Informe 3 medidas: ");
    scanf("%f %f %f", &A, &B, &C);
    if(A+B>C && A+C>B && C+B>A)
        if(A==B && B==C) printf("As 3 medidas formam um triangulo equilatero");
            else if(A==B || B==C || C==A) printf("As 3 medidas formam um triangulo isosceles");
                else printf("As 3 medidas formam um triangulo escaleno");
    else printf("As 3 medidas nao formam um triangulo");
    return 0;
}
*/

/*9*/
/*
#include <stdio.h>
#include <locale.h>

int main(){
setlocale(LC_ALL, "Portuguese");
char Prato, Sobremesa, Bebida;
int Calorias;
Calorias=0;
printf(" _____________________________________ \n");
printf("| PRATO       | SOBREMESA   | BEBIDA  | \n");
printf("|'''''''''''''|'''''''''''''|'''''''''|\n");
printf("| Vegetariano | Abacaxi     | Cha     | \n");
printf("| Peixe       | Sorvete     | Laranja | \n");
printf("| Frango      | Mouse       | Melao   | \n");
printf("| Carne       | Chocolate   | Refri   | \n");
printf("''''''''''''''''''''''''''''''''''''''' \n");
printf("Escolha um prato, uma sobremesa e uma bebida digitando sua letre inicial: ");
scanf("%c %c %c", &Prato, &Sobremesa, &Bebida);
switch(Prato){
	case 'v': 
	case 'V': Calorias=Calorias+180; break;
	case 'p':
	case 'P': Calorias=Calorias+230; break;
	case 'f':
	case 'F': Calorias=Calorias+250; break;
	case 'c':
	case 'C': Calorias=Calorias+350; break;
	default: break;
}
switch(Sobremesa){
	case 'a': 
	case 'A': Calorias=Calorias+75; break;
	case 's':
	case 'S': Calorias=Calorias+110; break;
	case 'm':
	case 'M': Calorias=Calorias+170; break;
	case 'c':
	case 'C': Calorias=Calorias+200; break;
	default: break;
}
switch(Bebida){
	case 'c': 
	case 'C': Calorias=Calorias+20; break;
	case 'l':
	case 'L': Calorias=Calorias+70; break;
	case 'm':
	case 'M': Calorias=Calorias+100; break;
	case 'r':
	case 'R': Calorias=Calorias+65; break;
	default: break;
}
printf("Seu prato vai ter %d calorias", Calorias);
return 0;
}
*/

/*10*/
/*
#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int termo, ultimo=1, penultimo=1, antepenultimo=1;
    printf("Qual termo da sequencia de Fibonacci voce deseja ver? ");
    scanf("%d", &termo);
    if(termo>0){
        while(termo>2){
            ultimo=ultimo+antepenultimo;
            antepenultimo=penultimo;
            penultimo=ultimo;
            termo=termo-1;
        }
        printf("%d", ultimo);
    }
}
*/

/*11*/
/*
#include <stdio.h>
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int num, div=2;
	printf("Digite um numero: ");
	scanf("%d", &num);
	while(num>div){
	    if(num%div==0){
	        div=num;
	        printf("%d nao e primo \n", num);
		}  
	    div++;
	}
	if(div==num) printf("%d e primo \n", num);
	if(num<=1) printf("%d nao e primo \n", num);
}
*/

/*12*/
/*
#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	int num, div, soma=0;
	printf("Digite um numero: ");
	scanf("%d", &num);
	div=num-1;
	while(div>0){
		if(num%div==0) soma=soma+div;
		div=div-1;
	}
	if(soma==num) printf("%d e um numero perfeito \n", num);
	else printf("%d nao e um numero perfeito \n", num);
}
*/

/*13*/
/*
#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");
    float valor, soma=0;
    int count=0;
    printf("Digite um valor: ");
    scanf("%f", &valor);
    while(valor>0){
        soma+=valor;
        printf("Digite outro valor: ");
        scanf("%f", &valor);
        count++;
    }
    printf("A media e %.2f", soma/count);
}
*/

/*14*/
/*
#include <stdio.h>
#include <locale.h>

int main(void){
    setlocale(LC_ALL, "Portuguese");
    int num, soma=1;
    printf("Digite um numero: ");
    scanf("%d", &num);
    if(num>=0){
        while(num>1){
            soma=soma*num;
            num=num-1;
        }
        printf("Seu fatorial e %d", soma);
    }
    else printf("Erro: numero menor que 0");
}
*/

/*15*/
/*
#include <stdio.h>

int main(void){
    int num1, num2, produto=0;
    printf("Digite dois números: ");
    scanf("%d %d", &num1, &num2);
    for(int i=1; i<=abs(num2); i++) produto+=abs(num1);
    if(num1<0 ^ num2<0) printf("Produto: %d", produto*(-1));
    else printf("Produto: %d", produto);
}
*/

/*16*/
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num1, num2, i, j, produto, casasDecimais=6, negativo=1; // j e produto poderiam ser removidos se fosse usado "num1=num1*10;"
float quociente;
char textQuociente[] = "", concatQuociente[] = "0";

void divisao(void){
    for(i=0; num1>=num2; i++) num1-=num2; // Divisao usando apenas subtracao
    sprintf(textQuociente, "%d", i); // Converte o valor inteiro de i para uma string
    strcat(concatQuociente, textQuociente); // Concatena as strings concatQuociente com textQuociente
    if(strstr(concatQuociente, ".")==0) strcat(concatQuociente, "."); // Diz quantos "." ha na string concatQuociente, se nao ha concatena concatQuociente com ".", se ha um ou mais o if e ignorado
    for(j=1; j<=10; j++) produto+=num1; // Essa,
	num1=produto; // essa e
	produto=0; // essa poderiam ser substituidas por um unico "num1=num1*10;", multiplica-se por 10 pois e equivalente a "abaixar um zero"
    while(casasDecimais>0){ // Chama a funcao decimal 6 vezes, pois essa e a quantidade de casas decimais que aparece num float em um printf
        casasDecimais--;
        divisao();
    }
}

int main(void){
    printf("Digite dois numeros: ");
    scanf("%d %d", &num1, &num2);
    if(num1<0 ^ num2<0) negativo=-1; // Ou exclusivo: se um e apenas um número for negativo o quociente sera negativo
    num1=abs(num1); // "abs" mesmo que "modulo"
    num2=abs(num2);
    divisao(); // Chama a funcao decimal
    quociente=atof(concatQuociente); // Converte a string concatQuociente para um float
	printf("Quociente: %f", quociente*negativo);
}
*/

/*17*/
/*
#include <stdio.h>

int main(){
    float num1=-1;
    while(abs((int)num1)!=num1){ // Recusa valor negativo e/ou com virgula, precisa inicializar num1 com valor com virgula ou negativo
    //while((int)num1!=num1){ // Recusa valor com virgula, precisa inicializar num1 com valor com virgula
    //while(fabs(num1)!=num1){ // Recusa valor negativo, precisa inicializar num1 com valor negativo. É bom usar math.h
	    printf("Digite um valor valido: ");
	    scanf("%f", &num1);
    }
    printf("Valor valido");
}
*/

/*18*/ 
/*
#include <stdio.h>

int main(void){
    int N;
    float S;
    printf("Digite um valor: ");
    scanf("%d", &N);
    for(int i=1; i<=N; i++) S=S+(1/(float)i);
    printf("Resultado: %f", S);
}
*/

/*19*/
/*
#include <stdio.h>

int main(void){
    int valor, cem, cinquenta, dez, cinco;
    printf("Digite um valor: ");
    scanf("%d", &valor);
    for(cem=0; valor>=100; cem++) valor-=100;
    for(cinquenta=0; valor>=50; cinquenta++) valor-=50;
    for(dez=0; valor>=10; dez++) valor-=10;
    for(cinco=0; valor>=5; cinco++) valor-=5;
    printf("%d de 100, %d de 50, %d de 10, %d de 5 e %d de 1", cem, cinquenta, dez, cinco, valor);
}
*/

/*20*/
/*
#include <stdio.h>

int main(void){
    int N;
    float S;
    printf("Digite um valor: ");
    scanf("%d", &N);
    for(int i=0; i!=N; i++) S+=(1+i)/(float)(N-i);
    printf("Resultado: %f", S);
}
*/

/*21*/
/*
#include <stdio.h>

int main(void){
    int i=0, j=0;
    float sexo, altura, media=0, mediaMulher=0, mediaHomem=0, maiorAltura=0, menorAltura=3;
    while((i+j)<5){
    	printf("Digite a altura e o sexo (1: mulher e 2: homem): ");
        scanf("%f %f", &altura, &sexo);
    	if(altura>=3 || altura<=0 || (sexo!=1 && sexo!=2)) printf("Digite valores validos\n");
	    else{
	        if(altura>maiorAltura) maiorAltura=altura;
	        if(altura<menorAltura) menorAltura=altura;
	        if(sexo==1){
	            mediaMulher+=altura;
	            i++;
	        }
	        if(sexo==2){
	            mediaHomem+=altura;
	            j++;
			}
	        media+=altura;
    	}
    }
    printf("\nMaior altura: %.2f\nMenor altura: %.2f\nAltura media das mulheres: %.2f\nAltura media dos homens: %.2f\nAltura media da turma: %.2f", maiorAltura, menorAltura, mediaMulher/i, mediaHomem/j, media/(i+j));
}
*/

/*22*/
/*
#include <stdio.h>

int main(void){
    float num=1, maior1=0, maior2=0, maior3=0;
    while(num>0){
        printf("Digite um valor: ");
        scanf("%f", &num);
        if(num>maior3) maior3=num;
        if(num>maior2){
        	maior3=maior2;
        	maior2=num;
		}
		if(num>maior1){
			maior2=maior1;
			maior1=num;
		}
	}
    printf("Os 3 maiores valores: %.2f, %.2f, %.2f", maior1, maior2, maior3);
}
*/

/*23*/
/*
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
    int auxBase, produto=1, negativo=1;
    float base, expoente=-1;
    while(abs((int)expoente)!=expoente || (int)base!=base){
    	system("cls");
    	printf("Digite a base (inteiro) e o expoente (natural): ");
    	scanf("%f %f", &base, &expoente);		
	}
    if(expoente==1) printf("Potencia: %d\n", base);
	else{
		if(base<0 && (int)expoente%2!=0) negativo=-1;
		auxBase=base;
    	for(int j=1; j<expoente; j++){
    		produto=0;
	    	for(int i=0; i<abs(auxBase); i++) produto+=abs(base);
			base=produto;
		}
		printf("Potencia: %d\n", produto*negativo);
	}
}
*/

/*24*/
/*
#include <stdio.h>

int main(void){
	float c, j, i;
	for(c=1.5, j=1.1, i=0; c>j; c+=0.02, j+=0.03, i++);
	printf("Chico vai ser mais alto que Juca daqui a %.0f anos, Juca vai ter %.2f metros", i, j);
}
*/

/*25*/
/*
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
*/

/*26*/
/*
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
*/

/*27*/
/*
#include <stdio.h>
#include <string.h>

int main(){
    char frase[51]="bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
    int quantEspaco=0, quantPalavras, quantLetras, quantA=0, quantE=0, quantI=0, quantO=0, quantU=0;
    gets(frase);
    for(int i=0; i<51; i++){
    	if(frase[i]==' ') quantEspaco++;
    	switch (frase[i]){
			case 'a': 
			case 'A': quantA++; break;
			case 'e':
			case 'E': quantE++; break;
			case 'i':
			case 'I': quantI++; break;
			case 'o':
			case 'O': quantO++; break;
			case 'u':
			case 'U': quantU++; break;
			default: break;
		}
	}
    printf("Palavras: %d\nLetras %d\nA: %d E:%d I:%d O:%d U:%d", quantEspaco+1, strlen(frase)-quantEspaco, quantA, quantE, quantI, quantO, quantU);
}
*/

/*28*/ 
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char letra, palavra[21], palavraAux[21], boneco[7]="      ";
int acertos=0, count=0, erros=0, quantLetras;

int desenho(void){
	printf(" _______ \n");
	printf("|\t| \n");
	printf("|\t%c \n", boneco[0]);
	printf("|      %c%c%c \n", boneco[2], boneco[1], boneco[3]);
	printf("|      %c %c \n", boneco[4], boneco[5]);
	printf("|%s\t%d \n", palavraAux, acertos);
}

int main(){
	printf("Escolha uma palavra: ");
	gets(palavra);
 quantLetras=strlen(palavra);
 for(int k=0; k<quantLetras; k++){
  palavraAux[k]='-';
 }
	system("cls");
	desenho();
	for(int i=0; i<27 && acertos!=quantLetras && erros<6; i++){
		printf("\nEscolha uma letra: ");

		scanf("%c", &letra);
  fflush(stdin);
		count=0;
		for(int j=0; j<quantLetras; j++){

			if(letra==palavra[j]){
    acertos++;
    palavraAux[j]=palavra[j];
    palavra[j]=' ';
   }
			else count++;

			if(count==quantLetras){
				erros++;
				switch (erros){
					case 1: boneco[0]='o'; break;
					case 2: boneco[1]='|'; break;
					case 3: boneco[2]='/'; break;
					case 4: boneco[3]='\\'; break;
					case 5: boneco[4]='/'; break;
					case 6: boneco[5]='\\'; break;
				}
			}
		}
		system("cls");
		desenho();
	}

	if(acertos==quantLetras) printf("VENCEU");
	else printf("GAME OVER");

}
*/

/*29*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

const int tamTabuleiro=4; 
int tabuleiroAcertos[tamTabuleiro][tamTabuleiro]={0}, tabuleiroFiguras[tamTabuleiro][tamTabuleiro], figura, cont1=0, cont2, linFirst, colFirst, linSec, colSec, score=0, position;

//Altera a posicao do cursor
void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//Desenha as posicoes da tabela
int desenho(void){
    for(int linha=0; linha<tamTabuleiro; linha++){
        for(int coluna=0; coluna<tamTabuleiro; coluna++){
            gotoxy((coluna+1)*4, (linha+1)*2); //*4 e *2 e para distanciar os elementos um dos outros
            if(tabuleiroAcertos[linha][coluna]==1) printf("%c", tabuleiroFiguras[linha][coluna]); //tabuleiroAcertos inicializa com tudo igual a 0, quando uma figura esta certa ele recebe 1 na position da figura
            else printf("%d", (linha+1)*10+(coluna+1)); //Se linha=1 e coluna=1, vai mostrar 22
        }
    }
}

int main(void){
	system("Color F0"); //Fundo branco e texto preto
    char *posChar, figurasRepetidas[tamTabuleiro*tamTabuleiro+1]={0}; //{0} inicializa o vetor com todos os elementos iguais a 0
    //Inicialização das letras do tabuleiroFiguras
    srand(time(NULL));
    //gotoxy(0, 30);
    for(int i=0; i<tamTabuleiro; i++){
        for(int j=0; j<tamTabuleiro; j++){
            do{
                cont2=0;
                figura=65+rand()%(tamTabuleiro*tamTabuleiro)/2; //Gera valores de 65=A até 72=H (quando tamTabuleiro=4)
                posChar=strchr(figurasRepetidas, figura); //Passa para pozChar o ponteiro da figura em figurasRepetidas, caso aquela não apareça nesta pozChar receberá NULL
                while(posChar!=NULL){ //pozChar será NULL quando figura não aparececer em figurasRepetidas 
                    cont2++;
                    posChar=strchr(posChar+1, figura);
                }
            }while(cont2>=2); //Verifica quantas vezes figura aparece em figurasRepetidas, se aparecer 2 ou mais vezes eu recomeço pois não quero aquela figura
            tabuleiroFiguras[i][j]=figura;
            figurasRepetidas[cont1]=figura;
            cont1++;
            //printf("%c", tabuleiroFiguras[i][j]);
        }
        //printf("\n");
    }
    //Escolha das posições
    while(score<(tamTabuleiro*tamTabuleiro)/2){
        desenho();
    	printf("\n\n\n Primeira carta: ");
        do{
            scanf("%d", &position);
            fflush(stdin);
            linFirst=position/10;
            colFirst=position-(linFirst*10);
            if(linFirst<1 || linFirst>tamTabuleiro || colFirst<1 || colFirst>tamTabuleiro){ //Caso o valores digitado seja menor que o menor e maior que o mair
            	printf(" Invalido! Primeira carta: ");
            	position=0;
			}
			if(tabuleiroAcertos[linFirst-1][colFirst-1]==1){
				printf(" Essa carta ja foi revelada! Primeira carta: ");
				position=0;
			}
        }while(position==0);
        printf(" Segunda carta: ");
        do{
            scanf("%d", &position);
            fflush(stdin);
            linSec=position/10;
            colSec=position-(linSec*10);
            if(linSec<1 || linSec>tamTabuleiro || colSec<1 || colSec>tamTabuleiro){
            	printf(" Invalido! Segunda carta: ");
            	position=0;
			}
			if(tabuleiroAcertos[linSec-1][colSec-1]==1){
				printf(" Essa carta ja foi revelada! Segunda carta: ");
				position=0;
			}
			if(linFirst==linSec && colFirst==colSec){
				printf(" Essa posicao ja foi escolhida! Segunda carta: ");
				position=0;
			}
        }while(position==0);
        //Mostra a figura da carta escolhida
	    gotoxy(colFirst*4, linFirst*2);
	    printf("%c ", tabuleiroFiguras[linFirst-1][colFirst-1]);
	    gotoxy(colSec*4, linSec*2);
	    printf("%c ", tabuleiroFiguras[linSec-1][colSec-1]);
	    Sleep(1500);
        system("cls");
		if(tabuleiroFiguras[linFirst-1][colFirst-1]==tabuleiroFiguras[linSec-1][colSec-1]){ //Compara se duas figuras são iguais
			tabuleiroAcertos[linFirst-1][colFirst-1]=1;
			tabuleiroAcertos[linSec-1][colSec-1]=1;
			score++;
		}
	}
}
*/

/*30*/
/*
#include <stdio.h>
#include <windows.h> //Para mudarCor, system's etc.
#include <conio.h> //Para o getch()
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Declaração de constantes
const int AZUL_BRANCO=151, AMARELO_VERDE=226, LINHA_MINIMA=4, LINHA_MAXIMA=18, MENOR_COLUNA=20, MAIOR_COLUNA=35, COLUNA_INICIO_TEXTO=22;
const int tamTabuleiro=4;

//Declaração de variaveis
int tecla, posicao=4, stop=1;
int tabuleiroAcertos[tamTabuleiro][tamTabuleiro]={0}, tabuleiroFiguras[tamTabuleiro][tamTabuleiro], figura, cont1=0, cont2, linFirst, colFirst, linSec, colSec, score, position; 

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

//Muda o fundo do texto, escreve o texto dos menus
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
		printf("  OPTIONS  ");
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
	gotoxy(MENOR_COLUNA, 24);
	printf("!");
	mudarCor(240);
	printf("Use WS e ENTER");
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

//Desenha as posicoes da tabela
int desenho(void){
    for(int linha=0; linha<tamTabuleiro; linha++){
        for(int coluna=0; coluna<tamTabuleiro; coluna++){
            gotoxy((coluna+1)*4, (linha+1)*2); //*4 e *2 e para distanciar os elementos um dos outros
            if(tabuleiroAcertos[linha][coluna]==1) printf("%c", tabuleiroFiguras[linha][coluna]); //tabuleiroAcertos inicializa com tudo igual a 0, quando uma figura esta certa ele recebe 1 na position da figura
            else printf("%d", (linha+1)*10+(coluna+1)); //Se linha=1 e coluna=1, vai mostrar 22
        }
    }
}

int main(void){
	MAIN:
		score=0;
		system("Color F0"); //Fundo branco e texto preto
		//Desenho dos menus
	    desenhoMenu(3, 8, 4); //Menu start
	    desenhoMenu(10, 15, 11); //Menu credits
	    desenhoMenu(17, 22, 18); //Menu end
		//Escolha dos menus
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
					if(posicao==4){//Enter no start
						system("Color F0"); //Fundo branco e texto preto
						system("cls");
						gotoxy(0,0);
						//Inicio do codigo do jogo
					    char *posChar, figurasRepetidas[tamTabuleiro*tamTabuleiro+1]={0}; //{0} inicializa o vetor com todos os elementos iguais a 0
					    //Inicialização das letras do tabuleiroFiguras
					    srand(time(NULL));
					    for(int i=0; i<tamTabuleiro; i++){
					        for(int j=0; j<tamTabuleiro; j++){
					            do{
					                cont2=0;
					                figura=65+rand()%(tamTabuleiro*tamTabuleiro)/2; //Gera valores de 65=A até 72=H (quando tamTabuleiro=4)
					                posChar=strchr(figurasRepetidas, figura); //Passa para pozChar o ponteiro da figura em figurasRepetidas, caso aquela não apareça nesta pozChar receberá NULL
					                while(posChar!=NULL){ //pozChar será NULL quando figura não aparececer em figurasRepetidas 
					                    cont2++;
					                    posChar=strchr(posChar+1, figura);
					                }
					            }while(cont2>=2); //Verifica quantas vezes figura aparece em figurasRepetidas, se aparecer 2 ou mais vezes eu recomeço pois não quero aquela figura
					            tabuleiroFiguras[i][j]=figura;
					            figurasRepetidas[cont1]=figura;
					            cont1++;
					            gotoxy((j+1)*4, (i+1)*2);
					            printf("%c", tabuleiroFiguras[i][j]);
					        }
					        printf("\n");
					    }
					    Sleep(2000);
					    system("cls");
					    //Escolha das posições
					    while(score<(tamTabuleiro*tamTabuleiro)/2){
					        desenho();
					    	printf("\n\n\n Primeira carta: ");
					        do{
					            scanf("%d", &position);
					            fflush(stdin);
					            linFirst=position/10;
					            colFirst=position-(linFirst*10);
					            if(linFirst<1 || linFirst>tamTabuleiro || colFirst<1 || colFirst>tamTabuleiro){ //Caso o valores digitado seja menor que o menor e maior que o maior
					            	printf(" Invalido (digite junto, ex.: 13)! Primeira carta: ");
					            	position=0;
								}
								if(tabuleiroAcertos[linFirst-1][colFirst-1]==1){
									printf(" Essa carta ja foi revelada! Primeira carta: ");
									position=0;
								}
					        }while(position==0);
					        printf(" Segunda carta: ");
					        do{
					            scanf("%d", &position);
					            fflush(stdin);
					            linSec=position/10;
					            colSec=position-(linSec*10);
					            if(linSec<1 || linSec>tamTabuleiro || colSec<1 || colSec>tamTabuleiro){
					            	printf(" Invalido (digite junto, ex.: 13)! Segunda carta: ");
					            	position=0;
								}
								if(tabuleiroAcertos[linSec-1][colSec-1]==1){
									printf(" Essa carta ja foi revelada! Segunda carta: ");
									position=0;
								}
								if(linFirst==linSec && colFirst==colSec){
									printf(" Essa posicao ja foi escolhida! Segunda carta: ");
									position=0;
								}
					        }while(position==0);
					        //Mostra a figura da carta escolhida
						    gotoxy(colFirst*4, linFirst*2);
						    printf("%c ", tabuleiroFiguras[linFirst-1][colFirst-1]);
						    gotoxy(colSec*4, linSec*2);
						    printf("%c ", tabuleiroFiguras[linSec-1][colSec-1]);
						    Sleep(1500);
					        system("cls");
							if(tabuleiroFiguras[linFirst-1][colFirst-1]==tabuleiroFiguras[linSec-1][colSec-1]){ //Compara se duas figuras são iguais
								tabuleiroAcertos[linFirst-1][colFirst-1]=1;
								tabuleiroAcertos[linSec-1][colSec-1]=1;
								score++;
							}
						}
						printf("VOCE VENCEU!");
						Sleep(2000);
						system("cls");
						posicao=4;
						goto MAIN;
						//Fim do codigo do jogo
					}
					else if(posicao==11){//Enter no credits
						system("Color F0"); //Fundo branco e texto preto
						system("cls");
						gotoxy(0,0);
						printf("Dificuldades (ainda nao funciona):\n1 - Facil\n2 - Medio\n3 - Dificil\n\nEscolha a dificuldade: ");
						int auxtamTabuleiro;
						do{
							scanf("%d", &auxtamTabuleiro);
							if(auxtamTabuleiro<1 || auxtamTabuleiro>3) printf("Entrada invalida! Escolha a dificuldade: ");
						}while(auxtamTabuleiro<1 || auxtamTabuleiro>3);
						system("cls");
						posicao=4;
						goto MAIN;
					}
					else{//Enter no end
						system("Color 0F");
						system("cls");
						gotoxy(0,0);
						stop=0;
					}
					break;	
			}
		}
}
*/

/*31*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int jogada1, jogada2, jogada3, jogada4, jogada5, jogada6, jogada7, jogada8, jogada9, parar;
    char p1, p2, p3, p4, p5, p6, p7, p8, p9;
    p1=' ';
    p2=' ';
    p3=' ';
    p4=' ';
    p5=' ';
    p6=' ';
    p7=' ';
    p8=' ';
    p9=' ';
    printf("\n      |     |     \n   1  |  2  |  3  \n _____|_____|_____\n      |     |     \n   4  |  5  |  6  \n _____|_____|_____\n      |     |     \n   7  |  8  |  9  \n      |     |     \n");
    printf("\n Escolha um número: ");
    scanf("%d", &jogada1);
    switch(jogada1){
        case 1: p1='X'; break;
        case 2: p2='X'; break;
        case 3: p3='X'; break;
        case 4: p4='X'; break;
        case 5: p5='X'; break;
        case 6: p6='X'; break;
        case 7: p7='X'; break;
        case 8: p8='X'; break;
        case 9: p9='X'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    printf("\n Escolha outro número: ");
    scanf("%d", &jogada2);
    if(jogada2==jogada1){ 
        system("cls");
        printf("Esse número já foi escolhido, fim de jogo!");
        Sleep(5000);
        exit(1);
    }
    switch(jogada2){
        case 1: p1='O'; break;
        case 2: p2='O'; break;
        case 3: p3='O'; break;
        case 4: p4='O'; break;
        case 5: p5='O'; break;
        case 6: p6='O'; break;
        case 7: p7='O'; break;
        case 8: p8='O'; break;
        case 9: p9='O'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    printf("\n Escolha outro número: ");
    scanf("%d", &jogada3);
    if(jogada3==jogada1 || jogada3==jogada2){
        system("cls");
        printf("Esse número já foi escolhido, fim de jogo!");
        Sleep(5000);
        exit(1);
    }
    switch(jogada3){
        case 1: p1='X'; break;
        case 2: p2='X'; break;
        case 3: p3='X'; break;
        case 4: p4='X'; break;
        case 5: p5='X'; break;
        case 6: p6='X'; break;
        case 7: p7='X'; break;
        case 8: p8='X'; break;
        case 9: p9='X'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    printf("\n Escolha outro número: ");
    scanf("%d", &jogada4);
    if(jogada4==jogada1 || jogada4==jogada2 || jogada4==jogada3){
        system("cls");
        printf("Esse número já foi escolhido, fim de jogo!");
        Sleep(5000);
        exit(1);
    }
    switch(jogada4){
        case 1: p1='O'; break;
        case 2: p2='O'; break;
        case 3: p3='O'; break;
        case 4: p4='O'; break;
        case 5: p5='O'; break;
        case 6: p6='O'; break;
        case 7: p7='O'; break;
        case 8: p8='O'; break;
        case 9: p9='O'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    printf("\n Escolha outro número: ");
    scanf("%d", &jogada5);
    if(jogada5==jogada1 || jogada5==jogada2 || jogada5==jogada3 || jogada5==jogada4){
        system("cls");
        printf("Esse número já foi escolhido, fim de jogo!");
        Sleep(5000);
        exit(1);
    }
    switch(jogada5){
        case 1: p1='X'; break;
        case 2: p2='X'; break;
        case 3: p3='X'; break;
        case 4: p4='X'; break;
        case 5: p5='X'; break;
        case 6: p6='X'; break;
        case 7: p7='X'; break;
        case 8: p8='X'; break;
        case 9: p9='X'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    if((p1=='X' && p2=='X' && p3=='X') || (p4=='X' && p5=='X' && p6=='X') || (p7=='X' && p8=='X' && p9=='X') || (p1=='X' && p4=='X' && p7=='X') || (p2=='X' && p5=='X' && p8=='X') || (p3=='X' && p6=='X' && p9=='X')  || (p1=='X' && p5=='X' && p9=='X') || (p3=='X' && p5=='X' && p7=='X')){
        printf("\n X VENCEU!");
        Sleep(5000);
        exit(1);
    }
    printf("\n Escolha outro número: ");
    scanf("%d", &jogada6);
    if(jogada6==jogada1 || jogada6==jogada2 || jogada6==jogada3 || jogada6==jogada4 || jogada6==jogada5){
        system("cls");
        printf("Esse número já foi escolhido, fim de jogo!");
        Sleep(5000);
        exit(1);
    }
    switch(jogada6){
        case 1: p1='O'; break;
        case 2: p2='O'; break;
        case 3: p3='O'; break;
        case 4: p4='O'; break;
        case 5: p5='O'; break;
        case 6: p6='O'; break;
        case 7: p7='O'; break;
        case 8: p8='O'; break;
        case 9: p9='O'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    if((p1=='X' && p2=='X' && p3=='X') || (p4=='X' && p5=='X' && p6=='X') || (p7=='X' && p8=='X' && p9=='X') || (p1=='X' && p4=='X' && p7=='X') || (p2=='X' && p5=='X' && p8=='X') || (p3=='X' && p6=='X' && p9=='X')  || (p1=='X' && p5=='X' && p9=='X') || (p3=='X' && p5=='X' && p7=='X')){
        printf("\n X VENCEU!");
        Sleep(5000);
        exit(1);
    }
    if((p1=='O' && p2=='O' && p3=='O') || (p4=='O' && p5=='O' && p6=='O') || (p7=='O' && p8=='O' && p9=='O') || (p1=='O' && p4=='O' && p7=='O') || (p2=='O' && p5=='O' && p8=='O') || (p3=='O' && p6=='O' && p9=='O')  || (p1=='O' && p5=='O' && p9=='O') || (p3=='O' && p5=='O' && p7=='O')){
        printf("\n O VENCEU!");
        Sleep(5000);
        exit(1);
    }
    printf("\n Escolha outro número: ");
    scanf("%d", &jogada7);
    if(jogada7==jogada1 || jogada7==jogada2 || jogada7==jogada3 || jogada7==jogada4 || jogada7==jogada5 || jogada7==jogada6){
        system("cls");
        printf("Esse número já foi escolhido, fim de jogo!");
        Sleep(5000);
        exit(1);
    }
    switch(jogada7){
        case 1: p1='X'; break;
        case 2: p2='X'; break;
        case 3: p3='X'; break;
        case 4: p4='X'; break;
        case 5: p5='X'; break;
        case 6: p6='X'; break;
        case 7: p7='X'; break;
        case 8: p8='X'; break;
        case 9: p9='X'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    if((p1=='X' && p2=='X' && p3=='X') || (p4=='X' && p5=='X' && p6=='X') || (p7=='X' && p8=='X' && p9=='X') || (p1=='X' && p4=='X' && p7=='X') || (p2=='X' && p5=='X' && p8=='X') || (p3=='X' && p6=='X' && p9=='X')  || (p1=='X' && p5=='X' && p9=='X') || (p3=='X' && p5=='X' && p7=='X')){
        printf("\n X VENCEU!");
        Sleep(5000);
        exit(1);
    }
    if((p1=='O' && p2=='O' && p3=='O') || (p4=='O' && p5=='O' && p6=='O') || (p7=='O' && p8=='O' && p9=='O') || (p1=='O' && p4=='O' && p7=='O') || (p2=='O' && p5=='O' && p8=='O') || (p3=='O' && p6=='O' && p9=='O')  || (p1=='O' && p5=='O' && p9=='O') || (p3=='O' && p5=='O' && p7=='O')){
        printf("\n O VENCEU!");
        Sleep(5000);
        exit(1);
    }
    printf("\n Escolha outro número: ");
    scanf("%d", &jogada8);
    if(jogada8==jogada1 || jogada8==jogada2 || jogada8==jogada3 || jogada8==jogada4 || jogada8==jogada5 || jogada8==jogada6 || jogada8==jogada7){
        system("cls");
        printf("Esse número já foi escolhido, fim de jogo!");
        Sleep(5000);
        exit(1);
    }
    switch(jogada8){
        case 1: p1='O'; break;
        case 2: p2='O'; break;
        case 3: p3='O'; break;
        case 4: p4='O'; break;
        case 5: p5='O'; break;
        case 6: p6='O'; break;
        case 7: p7='O'; break;
        case 8: p8='O'; break;
        case 9: p9='O'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    if((p1=='X' && p2=='X' && p3=='X') || (p4=='X' && p5=='X' && p6=='X') || (p7=='X' && p8=='X' && p9=='X') || (p1=='X' && p4=='X' && p7=='X') || (p2=='X' && p5=='X' && p8=='X') || (p3=='X' && p6=='X' && p9=='X')  || (p1=='X' && p5=='X' && p9=='X') || (p3=='X' && p5=='X' && p7=='X')){
        printf("\n X VENCEU!");
        Sleep(5000);
        exit(1);
    }
    if((p1=='O' && p2=='O' && p3=='O') || (p4=='O' && p5=='O' && p6=='O') || (p7=='O' && p8=='O' && p9=='O') || (p1=='O' && p4=='O' && p7=='O') || (p2=='O' && p5=='O' && p8=='O') || (p3=='O' && p6=='O' && p9=='O')  || (p1=='O' && p5=='O' && p9=='O') || (p3=='O' && p5=='O' && p7=='O')){
        printf("\n O VENCEU!");
        Sleep(5000);
        exit(1);
    }
    printf("\n Escolha outro número: ");
    scanf("%d", &jogada9);
    if(jogada9==jogada1 || jogada9==jogada2 || jogada9==jogada3 || jogada9==jogada4 || jogada9==jogada5 || jogada9==jogada6 || jogada9==jogada7){
        system("cls");
        printf("Esse número já foi escolhido, fim de jogo!");
        Sleep(5000);
        exit(1);
    }
    switch(jogada9){
        case 1: p1='X'; break;
        case 2: p2='X'; break;
        case 3: p3='X'; break;
        case 4: p4='X'; break;
        case 5: p5='X'; break;
        case 6: p6='X'; break;
        case 7: p7='X'; break;
        case 8: p8='X'; break;
        case 9: p9='X'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    if((p1=='X' && p2=='X' && p3=='X') || (p4=='X' && p5=='X' && p6=='X') || (p7=='X' && p8=='X' && p9=='X') || (p1=='X' && p4=='X' && p7=='X') || (p2=='X' && p5=='X' && p8=='X') || (p3=='X' && p6=='X' && p9=='X')  || (p1=='X' && p5=='X' && p9=='X') || (p3=='X' && p5=='X' && p7=='X')){
        printf("\n X VENCEU!");
        Sleep(5000);
        exit(1);
    }
    else{
        if((p1=='O' && p2=='O' && p3=='O') || (p4=='O' && p5=='O' && p6=='O') || (p7=='O' && p8=='O' && p9=='O') || (p1=='O' && p4=='O' && p7=='O') || (p2=='O' && p5=='O' && p8=='O') || (p3=='O' && p6=='O' && p9=='O')  || (p1=='O' && p5=='O' && p9=='O') || (p3=='O' && p5=='O' && p7=='O')){
            printf("\n O VENCEU!");
            Sleep(5000);
            exit(1);
        }
        else{
            printf("\n DEU VELHA!");
            Sleep(5000);
            exit(1);
        }
    }
    return 0;
}
*/

/*32*/
/*
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
*/

/*33*/
/*
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
*/

/*34*/
/*
#include <stdio.h>

int main(void){
	int dia=1, mes=1, ano=1900, diaMax[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, soma=0;
	do{
		printf("Informe um dia: ");
		scanf("%d", &dia);
		fflush(stdin);
		if(dia<1 || dia>31) printf("Digite um dia valido\n");
	}while(dia<1 || dia>31);
	do{
		printf("Informe um mes: ");
		scanf("%d", &mes);
		fflush(stdin);
		if(mes<1 || mes>12) printf("Digite um mes valido\n");
	}while(mes<1 || mes>12);
	do{
		printf("Informe um ano: ");
		scanf("%d", &ano);
		fflush(stdin);
		if(ano<1900 || ano>2100) printf("Digite um ano valido\n");
	}while(ano<1900 || ano>2100);
	if(((ano%4)==0 && (ano%100)!=0) || (ano%400)==0) diaMax[1]=29;
	if(dia>diaMax[mes-1]) printf("Data invalida");
	else{
		for(int i=0; i<mes-1; i++) soma+=diaMax[i];
		printf("%d/%d/%d e o dia %d deste ano", dia, mes, ano, soma+dia);
	}
}
*/

/*35*/
/*
#include <stdio.h>
#define N 5

int main(void){
	int mat[N][N], val, linha, coluna, count=0;
	float media=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			mat[i][j]=N*i+j;
			printf("\t%d [%d]", mat[i][j], (i+1)*10+(j+1));
		}
		printf("\n");
	}
	do{
		printf("\nInforme um elemento: ");
		scanf("%d", &val);
		if(val<11 || val>55) printf("Digite um elemento valido");
	}while(val<11 || val>55);
	linha=val/10;
	coluna=val-linha*10;
	for(int i=linha-2; i<=linha; i++)
		for(int j=coluna-2; j<=coluna; j++)
			if((i>=0 && j>=0 && i<=4 && j<=4) && (i!=linha-1 || j!=coluna-1)){
				media+=mat[i][j]; 
				//printf("%d j: %d i: %d\n", mat[j][i], j, i);
				count++;
			}
	printf("%f, %f", media/count, media);
}
*/

/*36*/
/*
#include <stdio.h>
#include <string.h>

int main(){
	char str1[100], str2[100], str3[100];
	int tam, log=0, l, k;
	printf("Digite uma frase em minusculo!: ");
	gets(str1);
	tam=strlen(str1);
	//for(int i=0; i<=tam; i++) 
	//	if(str1[i]<90) str1[i]=str1[i]+32;
	//puts(str1);
	//for(int i=0, k=tam-1; k>=0; i++, k--){
	//	while(str1[i]==' ') i++;
	//	while(str1[k]==' ') k--;
	//	if(str1[i]!=str1[k]) log=1;
	//}
	//if(log==1) printf("Nao e um palindromo");
	//else printf("E um palindromo");
	for(int i=0, j=0; i<=tam; i++)
		if(str1[i]!=' '){
			str2[j]=str1[i];
			j++;
		}
	tam=strlen(str2);
	for(l=0, k=tam-1; k>=0; l++, k--)
		str3[k]=str2[l];
	str3[l]='\0';
	puts(str2);
	puts(str3);
	if(strcmpi(str2, str3)==0) printf("E um palindromo");
	else printf("Nao e um palindromo");
}
*/

/*37*/
/*
#include <stdio.h>

int main(void){
	//Ordenacao por selecao direta
	int vet[20]={0, 5, 5, 6, 7, 9, 8, 8, 4, 1, 2, 3, 2, 4, 5, 6, 8, 9, 2, 8}, aux;
	for(int i=0; i<19; i++){
		for(int j=i+1; j<20; j++){
			if(vet[i]>vet[j]){
				aux=vet[i];
				vet[i]=vet[j];
				vet[j]=aux;
			}
		}
	}
	
	//Ordenacao por bubble sort
	for(int i=19; i>0; i--){
		for(int j=0; j<i; j++){
			if(vet[j]<vet[j+1]){
				aux=vet[j];
				vet[j]=vet[j+1];
				vet[j+1]=aux;
			}
		}
	}

    //Exibi o resultado
	for(int i=0; i<20; i++) printf("%d | ", vet[i]);
}
*/

/*38*/
/*
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
*/

/*39*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void mostra(float **matriz, int linhas, int colunas);

void trocaLinhas(float vetAux[], float **matriz, int linha1, int linha2, int colunas);

float **criaMatriz(int linhas, int colunas);

float *criaVetor(int tamanho);

void excluiMatriz(float **matriz, int linhas);

int posto(float **matriz, int linhas, int colunas);

int main(){
    float **matriz, **matrizInversa, *vetAux, escalar1, escalar2; 
    int flag, linhas, colunas, valorPosto, i, j, k, l, m, n, o;
    printf(" Digite o numero de linhas e colunas: ");
    scanf("%d %d", &linhas, &colunas);
    matriz=criaMatriz(linhas, colunas);
    matrizInversa=criaMatriz(linhas, colunas);
    vetAux=criaVetor(colunas);
    for(i=0; i<linhas; i++){
        for(j=0; j<colunas; j++){
            if(i==j){
                matrizInversa[i][j]=1;
            }
            else{
                matrizInversa[i][j]=0;
            }
        }
    }
    for(n=0; n<linhas; n++){
        for(o=0; o<colunas; o++){
            printf(" Digite o elemento da posicao %dx%d: ", n+1, o+1);
            scanf("%f", &matriz[n][o]);
        }
    }
    mostra(matriz, linhas, colunas);
    for(i=0, j=0; i<linhas; i++, j++){
        flag=1;
        POINT1:
        if(matriz[i][j]==0){
            for(m=i+1; m<linhas && flag!=0; m++){
                if(matriz[m][j]!=0){
                    trocaLinhas(vetAux, matriz, i, m, colunas);
                    trocaLinhas(vetAux, matrizInversa, i, m, colunas);
                    flag=0;
                    printf("\n Trocou as linhas %d e %d de posicao\n", i+1, m+1);
                    mostra(matriz, linhas, colunas);
                    printf("\n Trocou as linhas %d e %d de posicao da Matriz Inversa\n", i+1, m+1);
                    mostra(matrizInversa, linhas, colunas);
                }
            }
            if(flag==1){
                j++;
                goto POINT1;
            }
        }
        for(k=i+1; k<linhas; k++){
            if(matriz[k][j]!=0){
                escalar1=(-1)*(matriz[k][j]/matriz[i][j]);
                for(l=0; l<colunas; l++){
                    matriz[k][l]=matriz[k][l]+escalar1*matriz[i][l];
                    matrizInversa[k][l]=matrizInversa[k][l]+escalar1*matrizInversa[i][l];
                }    
                printf("\n Somou a linha %d com a linha %d vezes %.2f\n", k+1, i+1, escalar1);
                mostra(matriz, linhas, colunas);  
                printf("\n Somou a linha %d com a linha %d vezes %.2f da Matriz Inversa\n", k+1, i+1, escalar1);
                mostra(matrizInversa, linhas, colunas);  
            }
        }
    }
    printf("\n\n=========================MATRIZ ESCALONADA=========================\n\n");
    mostra(matriz, linhas, colunas);
    printf("\n\n===================================================================\n\n");
    valorPosto=posto(matriz, linhas, colunas);
    for(i=1, j=1; i<linhas; i++, j++){
        while(matriz[i][j]==0){
            j++;
        }
        for(k=i-1; k>=0; k--){
            if(matriz[k][j]!=0){
                escalar1=(-1)*(matriz[k][j]/matriz[i][j]);
                for(l=0; l<colunas; l++){
                    matriz[k][l]=matriz[k][l]+escalar1*matriz[i][l];
                    matrizInversa[k][l]=matrizInversa[k][l]+escalar1*matrizInversa[i][l];
                }
                printf("\n Somou a linha %d com a linha %d vezes %.2f\n", k+1, i+1, escalar1);
                mostra(matriz, linhas, colunas);
                printf("\n Somou a linha %d com a linha %d vezes %.2f da Matriz Inversa\n", k+1, i+1, escalar1);
                mostra(matrizInversa, linhas, colunas);      
            }
        }
    }
    for(i=0, j=0; i<linhas; i++, j++){
        POINT3:
        if(matriz[i][j]!=1){
            escalar2=1/matriz[i][j];
            for(k=0; k<colunas; k++){
                matriz[i][k]=matriz[i][k]*escalar2;
                matrizInversa[i][k]=matrizInversa[i][k]*escalar2;
            }
            printf("\n Multiplicou a linha %d por %.2f\n", i+1, escalar2);
            mostra(matriz, linhas, colunas);
            printf("\n Multiplicou a linha %d por %.2f da Matriz Inversa\n", i+1, escalar2);
        	mostra(matrizInversa, linhas, colunas);
        }
        if(matriz[i][j]==0){
            j++;
            goto POINT3;
        }
    }
	printf("\n\n==========================MATRIZ INVERSA==========================\n\n");
    mostra(matrizInversa, linhas, colunas);
    printf("\n\n==================================================================\n\n");
    printf("\n O posto da matriz e %d\n\n", valorPosto);
    if(vetAux!=0){
    	free(vetAux);
	}
	excluiMatriz(matriz, linhas);
    excluiMatriz(matrizInversa, linhas);
    system("Pause");
}

void mostra(float **matriz, int linhas, int colunas){
    int i, j;
	printf("\n");
	for(i=0; i<linhas; i++){
		printf(" |");
        for(j=0; j<colunas; j++){
            printf("%10.2f", matriz[i][j]);
        }
        printf(" |");
        printf("\n");
    }
}

void trocaLinhas(float vetAux[], float **matriz, int linha1, int linha2, int colunas){
    int j;
    for(j=0; j<colunas; j++){
        vetAux[j]=matriz[linha1][j];
        matriz[linha1][j]=matriz[linha2][j];
        matriz[linha2][j]=vetAux[j];
    }
}

float **criaMatriz(int linha, int coluna){
    float **p;
    int i;
    p=(float **) malloc(linha*sizeof(float *));
    if(p==NULL){
        return NULL;
    }
    for(i=0; i<linha; i++){
        p[i]=(float *) malloc(coluna*sizeof(float));
        if(p[i]==NULL){
            return NULL;
        }
	}
    return p;  
}

float *criaVetor(int tamanho){
    float *v;
    v=(float *)malloc(tamanho*sizeof(float));
    return v;      
}

void excluiMatriz(float **matriz, int linhas){
    int i;
    if(matriz!=NULL){
        for(i=0; i<linhas; i++){
    		if (matriz[i]!=NULL){
    			free(matriz[i]);
			}
		}
        free(matriz);                
    }
}

int posto(float **matriz, int linhas, int colunas){
    int count=0, i, j;
    for(i=0, j=0; i<linhas && j<colunas; i++, j++){
        POINT2:
    	if(i<linhas && j<colunas){
    		if(matriz[i][j]!=0){
            	count++;
        	}
        	else{
            	j++;
            	goto POINT2;
        	}
		}
    }
    return count;
}
*/

/*40*/
/*
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
*/

/*41*/
/*
#include <stdio.h>
#include <stdlib.h>

//Nao funciona com acentos e cedilha, conjunto de numeros e/ou caracters especiais nao conta como palavras

int main(int argc, char *argv[]){
	FILE *fpi; //, *fpo;
	char c;
	int key=0, countCaracters=0, countSpaces=0, countEnters=0, countTabs=0;
	if(argc!=2){
		printf("Quantidade de argumentos invalida");
		exit(-1);
	}
	fpi=fopen(argv[1], "r");
	fpi=fopen("C:\\Users\\Mateus\\Desktop\\teste.txt", "r");
	if(!fpi){
		printf("Erro ao abrir arquivo de entrada");
		exit(-2);
	}
	//fpo=fopen("C:\\Users\\Mateus\\Desktop\\temp.txt", "w");
	while(!feof(fpi)){
		c=fgetc(fpi);
		countCaracters++;
		if(c=='\n'){ //\n: quebra de linha
			countEnters++;
			c=' ';
		}
		if(c==9){ //9: TAB
			countTabs++;
			c=' ';
		}
		if(c==' ' && key==1){ //Casa haja varios ' ' apenas um sera contado
			//fputc(c, fpo);
			countSpaces++;
			key=0;
		}
		else if((c>=65 && c<=90) || (c>=97 && c<=122)){ //65: A, 90: Z. 97: a, 122: z
			key=1;
			//fputc(c, fpo);
		}
	}
	if(key==0){ //Se a variavel c terminal o programa com o caracter ' ', quantidades de espacos - 1. Obs.: (c==' ') nao funciona porque o ultimo caracter lido e o EOF
		countSpaces--;
	}
	printf("A frase tem %d caracteres, %d palavras e %d linhas", countCaracters-1-countEnters, //Quantididade de caracters - 1 (por causa do caracter EOF) - quantidade de \n
																 countSpaces+1, //Quantidades de espacos + 1 e igual a quantidade de palavras
																 countEnters+1); //Quantidade de \n + 1 (porque a ultima linha nao tem \n)
	fclose(fpi);	
}
*/

/*42*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crip(FILE *fpi, FILE *fpo, int control, char str[100]){
	char c;
	int aux;
	c=fgetc(fpi);
	while(!feof(fpi)){
	    aux=c;
	    c=aux+control;
	    fputc(c,fpo);
	    c=fgetc(fpi);
	}
	printf("%s", str);
}

int main(int argc, char *argv[]){
    FILE *fpi, *fpo;
	int val;
    if(argc!=3){
        printf("Erro na quantidade de argumento\n");
        exit(-1);
    }
    fpi=fopen(argv[1],"rb");
    if(!fpi){
        printf("Erro ao abrir arquivo de entrada\n");
        exit(-2);
    }
    fpo=fopen(argv[2],"wb");
    if(!fpo){
        printf("Erro no arquivo de saída\n");
        exit(-3);
    }
    POINT1:
	printf("1 - Criptografar arquivo\n2 - Descriptografar aquivo\n");
	scanf("%d", &val);
	switch(val){
		case 1: 
			crip(fpi, fpo, 1, "Arquivo criptografado"); 
			break;
		case 2: 
			crip(fpi,fpo, -1, "Arquivo descriptografado"); 
			break;
		default: 
			printf("Escolha o valor correto\n\n"); 
			goto POINT1;
	}
    fclose(fpi);
    fclose(fpo);
    return 0;
}
*/

/*43*/
/*
PROGRAMA 1:

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
-------------------------------------------------
PROGRAMA 2:

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
-------------------------------------------------
PROGRAMA 3:

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define CPF 12
#define NAME 50

typedef struct{
    char cpf[CPF];
    char nome[NAME];
    float salario;
    char sit;
} cad;

cad cadFun;
FILE *fp;

void mudarCor(int cor);
void gotoxy(int x, int y);

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

void principal(int option){
    fp=fileOpen("cadfun.dad", "ab"); //Cria caso nao exista um arquivo binario para escrita. Se existir apenas abre
    fclose(fp);
    fp=fileOpen("cadfun.dad", "r+b");
    switch(option){
        case 1: incluir(); break;
        case 2: alterar(); break;
        case 3: situacao(); break;
        case 4: consultar(); break;
        case 5: listar('0'); break;
        case 6: listar('1'); break;
        case 7: cleanTrash(); break;
        case 8: 
			gotoxy(0, 27); //Para o texto de final de execucao
			mudarCor(112);
			exit(0); 
			break;
    }
    fclose(fp);
}

void copiar(FILE *fpi, FILE *fpo){ //Copia todo o conteudo de fpi para fpo
    int tamArq;
    tamArq=filelen(fpi);
    fseek(fpi, 0, SEEK_SET); //Posiciona o cursor do arquivo no inicio, para poder ler todos os cadastros
    while(ftell(fpi)<tamArq){ //Le todos os cadastros ate chegar ao fim
    	fread(&cadFun, sizeof(cad), 1, fpi);
        if(cadFun.sit=='0'){ //Apenas ira escrever no arquivo temporario os cadastros ativos
            fwrite(&cadFun, sizeof(cad), 1, fpo);
        }
	}
}

FILE *fileOpen(char *arqName, char *mode){
	FILE *fpi;
    fpi=fopen(arqName, mode);
    if(!fpi){
        system("Color 70");
        system("cls");
        printf("Erro ao abrir ou criar arquivo de entrada");
        exit(-1);
    
	}
    return fpi;
}

void clear(char *str, int tamanho){ //Preenche todos os espacos de um vetor com ' '
    for(int i=0; i<tamanho; i++){
        *(str+i)=' ';
    }
}

int validaStr(char *str, int tamanho, int rangeMin, int rangeMax){ //Filtra um string com base no seu tamanho em um range se caracteres permitidos. Retorna -1 em caso de CPF invalido
    clear(str, tamanho); //Preenche a string com espacos vazios, para saber se tem menos caracteres que o parametro tamanho
    fgets(str, tamanho, stdin); //Range do parametro deve incluir o \0
    fflush(stdin);
    for(int i=0; i<(tamanho-1); i++){
        if(!(*(str+i)>=rangeMin && *(str+i)<=rangeMax)){
            return -1;
        }
    }
}

int filelen(FILE *fp){ //Retorna o tamanho do arquivo
	fseek(fp, 0, SEEK_END);
	return ftell(fp);
}

int busca(char *wtdCpf){ //Busca e le o CPF no arquivo. Caso encontre retorna 0, caso nao encontre retorna -1
	char curCpf[CPF];
	int tamArq;
    tamArq=filelen(fp);
    fseek(fp, 0, SEEK_SET); //Posiciona o cursor do arquivo no inicio
    do{
        fread(curCpf, sizeof(cadFun.cpf), 1, fp);
        if(strcmp(wtdCpf, curCpf)==0){ //Strcmp retorna 0 se forem iguais
            fseek(fp, ftell(fp)-sizeof(cadFun.cpf), SEEK_SET); //Seta o cursor do arquivo no inicio de um CPF
            fread(&cadFun, sizeof(cad), 1, fp);
            return ftell(fp)-sizeof(cad);
        }
        else{
            fseek(fp, 60, SEEK_CUR); //Avanca para o proximo CPF
        }
    } while(ftell(fp)<tamArq); //se a posicao atual do cursor do arquivo for maior ou igual ao seu tamanho entao ele encerra a busca
    return -1; //caso nao encontro o cpf procurado retorna -1
}

int incluir(void){ //Inclui os dados do funcionario no arquivo. Retorna -1 em caso de CPF invalido ou duplicado
    int i=4;
    mudarCor(113);
    gotoxy(50,1);
    printf("INCLUIR NOVO FUNCIONARIO");
    mudarCor(112);
    //Leitura do cpf
    gotoxy(50, 2);
    printf("Digite o CPF do novo funcionario: ");
    if(validaStr(cadFun.cpf, CPF, 48, 57)==-1){ //48: 0, 57: 9. Assim o CPF tera apenas numeros
        gotoxy(50, 3);
        printf("CPF invalido ");
        mudarCor(116);
    	gotoxy(50,4);
    	printf("FALHA AO INCLUIR NOVO FUNCIONARIO");
        return -1;
    }
    if(busca(cadFun.cpf)!=-1){
        gotoxy(50, 3);
        printf("CPF duplicado ");
        mudarCor(116);
    	gotoxy(50,4);
    	printf("FALHA AO INCLUIR NOVO FUNCIONARIO");
        return -1;
    }
    //Leitura do nome
    clear(cadFun.nome, NAME); //Preenhce todo o nome com espacos vazios, para evitar lixo
    gotoxy(50, 3);
    printf("Digite o nome do novo funcionario: ");
    scanf("%49[^\n]", cadFun.nome); //%50[^\n]: le no maximo 49 caracters, [^\n] para de ler quando encontrar o \n (deixa o \n no buffer) 
    fflush(stdin);
    //leitura do salario
    do{
        gotoxy(50,i);
        printf("Digite o salario do novo funcionario: ");
        scanf("%f", &cadFun.salario);
        fflush(stdin);
        i++;
    } while(cadFun.salario<0); //Caso a pessoa digite um valor negativo o processo repete
    cadFun.sit='0'; //Por padrao o cadastro do funcionario e ativo
    fseek(fp, 0, SEEK_END); //Posiciona o cursor do arquivo no fim
    fwrite(&cadFun, sizeof(cad), 1, fp);
    mudarCor(114);
	gotoxy(50,i);
    printf("NOVO FUNCIONARIO INCLUIDO COM SUCESSO");
}

int alterar(void){ //Altera os dados do funcionario. Retorna -1 em caso de CPF invalido
    char wtdCpf[CPF];
    int option, curPos, i=5;
    mudarCor(113);
    gotoxy(50,1);
    printf("ALTERAR DADOS DE UM FUNCIONARIO");
    mudarCor(112);
    //Leitura do CPF
    gotoxy(50, 2);
    printf("Digite o CPF do funcionario: ");
    if(validaStr(wtdCpf, CPF, 48, 57)==-1){
        gotoxy(50, 3);
        printf("CPF invalido");
        mudarCor(116);
    	gotoxy(50,4);
    	printf("FALHA AO ALTERAR DADOS DO FUNCIONARIO");
        return -1;
    }
    curPos=busca(wtdCpf);
    if(curPos==-1){
        gotoxy(50, 3);
        printf("CPF nao encontrado");
        mudarCor(116);
    	gotoxy(50,4);
    	printf("FALHA AO ALTERAR DADOS DO FUNCIONARIO");
        return -1;
    }
    else{
        if(cadFun.sit=='1'){ //Caso o cadastro esteja inativo nao sera possivel o alterar
            gotoxy(50, 3);
            printf("Cadastro inativo");
            mudarCor(116);
    		gotoxy(50,4);
    		printf("FALHA AO ALTERAR DADOS DO FUNCIONARIO");
    		return -1;
        }
        else{
            gotoxy(50, 3);
            printf("1 - CPF 2 - Nome 3 - Salario. O que deseja alterar: ");
            scanf("%d", &option);
            fflush(stdin);
            switch(option){
                case 1:
                    gotoxy(50,4);
                    printf("Digite o novo CPF: ");
                    if(validaStr(cadFun.cpf, CPF, 48, 57)==-1){
                        gotoxy(50,5);
                        printf("CPF invalido");
                        mudarCor(116);
    					gotoxy(50,6);
    					printf("FALHA AO ALTERAR DADOS DO FUNCIONARIO");
                        return -1;
                    }
                    if(busca(cadFun.cpf)!=-1){
        				gotoxy(50, 5);
				        printf("CPF duplicado ");
                        mudarCor(116);
    					gotoxy(50,6);
    					printf("FALHA AO ALTERAR DADOS DO FUNCIONARIO");
				        return -1;
    				}
                    break;
                case 2:
                    gotoxy(50,4);
                    printf("Digite o novo nome: ");
                    scanf("%49[^\n]", cadFun.nome);
                    fflush(stdin);
                    break;
                case 3:
                    do{
                        gotoxy(50,i-1);
                        printf("Digite o novo salario: ");
                        scanf("%f", &cadFun.salario);
                        fflush(stdin);
                        i++;
                    } while(cadFun.salario<0);
                    i--;
                    break;
                default: 
                    gotoxy(50,4);
                    printf("Escolha invalida");
                    mudarCor(116);
    				gotoxy(50,5);
    				printf("FALHA AO ALTERAR DADOS DO FUNCIONARIO");
                    return -1;
            }
            fseek(fp, curPos, SEEK_SET);
            fwrite(&cadFun, sizeof(cad), 1, fp); //Sobresscreve os dados, so funciona se for r+b
            mudarCor(114);
    		gotoxy(50,i);
    		printf("DADOS DO FUNCIONARIO ALTERADOS COM SUCESSO");
        }
    }
}

int situacao(void){ //Comuta a situacao do funcionario. Retorna -1 em caso de CPF invalido
    char wtdCpf[CPF];
    int curPos;
    mudarCor(113);
    gotoxy(50,1);
    printf("MUDAR SITUACAO DE UM FUNCIONARIO");
    mudarCor(112);
    gotoxy(50, 2);
    printf("Digite o CPF do funcionario: ");
    if(validaStr(wtdCpf, CPF, 48, 57)==-1){
        gotoxy(50,3);
        printf("CPF invalido");
        mudarCor(116);
    	gotoxy(50,4);
    	printf("FALHA AO MUDAR A SITUACAO DO FUNCIONARIO");
        return -1;
    }
    curPos=busca(wtdCpf);
    if(curPos==-1){
        gotoxy(50,3);
        printf("CPF nao encontrado");
        mudarCor(116);
    	gotoxy(50,4);
    	printf("FALHA AO MUDAR A SITUACAO DO FUNCIONARIO");
        return -1;
    }
    else{
        cadFun.sit=='0'?cadFun.sit='1':cadFun.sit='0'; //operador ternario: condicao?verdadeiro:falso
        fseek(fp, curPos, SEEK_SET);
        fwrite(&cadFun, sizeof(cad), 1, fp);
        gotoxy(50,3);
        printf("Agora a situacao de %s esta %s", cadFun.nome, cadFun.sit=='0'?"ATIVA":"INATIVA");
        mudarCor(114);
    	gotoxy(50,4);
    	printf("SITUACAO DO FUNCIONARIO ALTERADA COM SUCESSO");
    }
}

int consultar(void){ //Exibe os dados do funcionario. Nao exibe caso o funcionario esteja inativo. Retorna -1 em caso de CPF invalido
    char wtdCpf[CPF];
    mudarCor(113);
    gotoxy(50,1);
    printf("CONSULTAR DADOS DE UM FUNCIONARIO");
    mudarCor(112);
    gotoxy(50, 2);
    printf("Digite o CPF do funcionario: ");
    if(validaStr(wtdCpf, CPF, 48, 57)==-1){
        gotoxy(50, 3);
        printf("CPF invalido");
        mudarCor(116);
    	gotoxy(50,4);
    	printf("FALHA AO CONSULTAR DADOS DO FUNCIONARIO");
        return -1;
    }
    if(busca(wtdCpf)==-1){
        gotoxy(50, 3);
        printf("CPF nao encontrado");
        mudarCor(116);
    	gotoxy(50,4);
    	printf("FALHA AO CONSULTAR DADOS DO FUNCIONARIO");
        return -1;
    }
    else{
        if(cadFun.sit=='1'){
            gotoxy(50, 3);
            printf("Cadastro inativo");
	        mudarCor(116);
	    	gotoxy(50,4);
	    	printf("FALHA AO CONSULTAR DADOS DO FUNCIONARIO");
            return -1;
        }
        else{
            gotoxy(50, 4);
            printf("CPF: %s", cadFun.cpf);
            gotoxy(50, 5);
            printf("Nome: %s", cadFun.nome);
            gotoxy(50, 6);
            printf("Salario: %.2f", cadFun.salario);
            gotoxy(50, 7);
            printf("Situacao: %s", cadFun.sit=='0'?"Ativo":"Inativo");
        }
    }
}

void listar(char sit){ //Lista os cadastros ativos de sit for 1 ou os inativos se sit for 0
    int tamArq, i=2;
    mudarCor(113);
    gotoxy(50,1);
    printf("LISTA DE FUNCIONARIOS %s", sit=='0'?"ATIVOS":"INATIVOS");
    mudarCor(112);
    tamArq=filelen(fp);
    fseek(fp, 0, SEEK_SET);
    gotoxy(50, i);
    printf("|     CPF     |                        NOME                        | SALARIO |   SIT   |");
    gotoxy(50, ++i);
    printf("|-------------|----------------------------------------------------|---------|---------|");
    do{
        fread(&cadFun, sizeof(cad), 1, fp);
        if(cadFun.sit==sit){
            gotoxy(50, ++i);
            printf("| %s | %-50s | R$%5.0f | %-7s |", cadFun.cpf, cadFun.nome, cadFun.salario, cadFun.sit=='0'?" ATIVA ":"INATIVA"); 
        }
    } while(ftell(fp)<tamArq);
}

void cleanTrash(void){ //Apaga todos os cadastros inativos
    mudarCor(114);
    gotoxy(50,1);
    printf("CADASTROS INATIVOS EXCLUIDOS COM SUCESSO");
    FILE *fpt; //Cria um ponteiro para um arquivo temporario
    fpt=fileOpen("temp.dad", "a+b"); 
    copiar(fp, fpt); //Copia os cadastros ativos do arquivo para um temporario
    fclose(fp);
    fp=fileOpen("cadfun.dad", "w+b"); //Reabre o arquivo em branco (w+b)
    copiar(fpt, fp); //Copia o conteudo do arquivo temporario para o arquivo
    fclose(fpt);
    if(remove("temp.dad")==-1){ //Apaga o arquivo temporario
        system("Color 70");
        system("cls");
        printf("Erro ao apagar arquivo temporario");
        exit(-1);
    }
    fclose(fp); //Fecha fp para poder reabri com r+b
    fp=fileOpen("cadfun.dad", "r+b");
}
*/

/*44*/
/*
*/

/*45*/
/*
*/