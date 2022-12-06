//Verifica se 3 medidas informadas formam um triangulo e o classifica

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
