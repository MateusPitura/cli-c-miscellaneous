//CHICO TEM 1.5 METRO E CRESCE 2 CM AO ANO, JUCA TEM 1.1 METRO E CRESCE 3 CM AO ANO, DAQUI QUANTOS ANOS JUCA VAI SER MAIS QUE CHICO

#include <stdio.h>

int main(void){
	float c, j, i;
	for(c=1.5, j=1.1, i=0; c>j; c+=0.02, j+=0.03, i++);
	printf("Chico vai ser mais alto que Juca daqui a %.0f anos, Juca vai ter %.2f metros", i, j);
}
