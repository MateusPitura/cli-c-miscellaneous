//Conta quantidade de palavras, letras e vogais

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
