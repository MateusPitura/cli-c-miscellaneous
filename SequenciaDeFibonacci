//Mostra a sequencia de Fibonacci

#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int termo, ultimo=1, penultimo=1, antepenultimo=1;
    printf("Qual termo da sequencia de Fibonacci voce deseja ver? ");
    scanf("%d", &termo);
    if(termo>0){
        while(termo>2){
            ultimo=ultimo+antepenultimo;
            antepenultimo=penultimo;
            penultimo=ultimo;
            termo=termo-1;
        }
        printf("%d", ultimo);
    }
}
