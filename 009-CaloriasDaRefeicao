//Calcula quantas calorias tera a refeicao

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
