//Mostra o seu peso em outros planetas

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    float PesoTerra;
    int Planeta;
    printf("Informe seu peso em kilogramas: ");
    scanf("%f", &PesoTerra);
    printf("1: Mercurio\n2: Venus\n3: Marte\n4: Jupiter\n5: Saturno\n6: Urano\nEscolha um planeta digitando seu numero: ");
    scanf("%d", &Planeta);
    switch (Planeta){
        case 1: printf("Seu peso em Mercurio e %.2f kilogramas", PesoTerra*0.37); break;
        case 2: printf("Seu peso em Venus e %.2f kilogramas", PesoTerra*0.88); break;
        case 3: printf("Seu pesso em Marte e %.2f kilogramas", PesoTerra*0.38); break;
        case 4: printf("Seu peso em Jupiter e %.2f kilogramas", PesoTerra*2.64); break;
        case 5: printf("Seu peso em Saturno e %.2f kilogramas", PesoTerra*1.15); break;
        case 6: printf("Seu pesso em Urano e %.2f kilogramas", PesoTerra*1.17); break;
        default: printf("Voce digitou um numero que nao corresponde a um planeta"); break;
    }
    return 0;
}
