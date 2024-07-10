//Jogo da forca

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
