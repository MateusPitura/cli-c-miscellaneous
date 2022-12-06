//Conta a quantidade de palavras, linhas e caracteres de uma arquivo

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
