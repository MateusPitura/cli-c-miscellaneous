//Calcula o IMC

#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
    float PesoAtual, Altura, Imc, PesoIdeal, Kilos;
    printf("Informe seu peso em kilogramas: ");
    setlocale(LC_ALL, "Portuguese");
    scanf("%f", &PesoAtual);
    printf("Informe sua altura em metros: ");
    scanf("%f", &Altura);
    Imc=PesoAtual/pow(Altura,2);
    printf("Seu IMC e %.2f \n", Imc);
    if(Imc<20){
        printf("Abaixo do peso\n");
        PesoIdeal=20*pow(Altura,2);
        Kilos=PesoIdeal-PesoAtual;
        printf("E necessario ganhar %.2f kilogramas, seu peso ideal e %.2f", Kilos, PesoIdeal);
    }
        else if(Imc<25) printf("Peso normal\nMantenha seu peso");
            else if(Imc<30){
                printf("Sobrepeso\n");
                PesoIdeal=25*pow(Altura,2);
                Kilos=PesoAtual-PesoIdeal;
                printf("E necessario perder %.2f kilogramas, seu peso ideal e %.2f", Kilos, PesoIdeal);
            }
                else if(Imc<40){
                    printf("Obeso\n");
                    PesoIdeal=25*pow(Altura,2);
                    Kilos=PesoAtual-PesoIdeal;
                    printf("E necessario perder %.2f kilogramas, seu peso ideal e %.2f", Kilos, PesoIdeal);
                }
                    else{
                        printf("Obeso morbido\n");
                        PesoIdeal=25*pow(Altura,2);
                        Kilos=PesoAtual-PesoIdeal;
                        printf("E necessario perder %.2f kilogramas, seu peso ideal e %.2f", Kilos, PesoIdeal);
                    }
    return 0;
}
