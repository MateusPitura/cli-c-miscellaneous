//Divide dois valores (com casa decimal) usando apenas operacoes basicas

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
