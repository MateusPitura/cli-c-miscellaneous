//Criptografa e descriptograda arquivos

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
