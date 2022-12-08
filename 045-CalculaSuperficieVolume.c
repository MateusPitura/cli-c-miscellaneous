#include <stdio.h>
#include <math.h>

#define PI 3.14

void calc_esfera(float R, float *area, float *volume);

int main(void){
    float raio, area, volume;
    printf("Digite o raio da esfera: ");
    scanf("%f", &raio);
    calc_esfera(raio, &area, &volume);
    printf("Superficie: %.2f\nVolume: %.2f", area, volume);
}

void calc_esfera(float R, float *area, float *volume){
    *area=4*PI*pow(R,2);
    *volume=((float)4/3)*PI*pow(R,3);
}