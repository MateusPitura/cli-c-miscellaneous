/*
Faca um programa que possua uma funcao para
- Ler 2 notas e retorna-las por parametro (chamar uma funcao dedicada a ler 2 notas
validas e que devolver os 2 numeros lidos);
- Calcular a media simples e a media ponderada e retorna-las por parametro, onde a
segunda nota tem peso 2 media ponderada = (n1 + n2 ∗ 2)/3;
*/

#include <stdio.h>

void leitura(float *var, char *text);
void mediaSim(float *nota1, float *nota2, float *media);
void mediaPon(float *nota1, int peso1, float *nota2, int peso2, float *media);

int main(){
    float nota1, nota2, mediaSimples, mediaPonderada;
    leitura(&nota1, "Digite a primeira nota: ");
    leitura(&nota2, "Digite a segunda nota: ");
    mediaSim(&nota1, &nota2, &mediaSimples);
    mediaPon(&nota1, 1, &nota2, 2, &mediaPonderada);
    printf("Meida simpeles: %-6.2f Media ponderada: %-6.2f", mediaSimples, mediaPonderada);
}

void leitura(float *var, char *text){
    printf(text);
    scanf("%f", var);
}

void mediaSim(float *nota1, float *nota2, float *media){
    *media=(*nota1+*nota2)/2;
}

void mediaPon(float *nota1, int peso1, float *nota2, int peso2, float *media){
    *media=((*nota1*peso1)+(*nota2*peso2))/(peso1+peso2);
}