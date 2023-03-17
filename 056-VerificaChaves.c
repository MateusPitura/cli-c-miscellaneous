#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 100

char pilha[TAMANHO];
char expressao[TAMANHO];

void zeraVetor(char *vet);
int push(int input);
int pop();
int topo();
void imprimi(char *vet);
void validaFechamento(char c);

int main(void){
    do{
        zeraVetor(pilha);
        zeraVetor(expressao);
        printf("Digite uma expressao: ");
        scanf("%s", expressao);
        fflush(stdin);
        for(int i=0; i<TAMANHO; i++){
            switch(expressao[i]){
                case '{':
                    push(expressao[i]);
                    break;
                case '[':
                    push(expressao[i]);
                    break;
                case '(':
                    push(expressao[i]);
                    break;
                case ')':
                    validaFechamento('(');
                    break;
                case ']':
                    validaFechamento('[');
                    break;
                case '}':
                    validaFechamento('{');
                    break;
                default: break;
            }
            // imprimi(pilha);
            // system("pause");
            // system("cls");
        }
        if(topo()==1){
            printf("Fechamento correto\n");
        }
        else{
            printf("Fechamento incorreto\n");
        }
    }while(1);
    return 0;
}

void zeraVetor(char *vet){
    for(int i=0; i<TAMANHO; i++){
        vet[i]=0;
    }
}

int push(int input){
    int i;
    for(i=0; i<TAMANHO; i++){
        if(pilha[i]==0){
            pilha[i]=input;
            return 0;
        }
    }
    return i;
}

int pop(){
    int i;
    for(i=(TAMANHO-1); i>=0; i--){
        if(pilha[i]!=0){
            pilha[i]=0;
            return 0;
        }
    }
    return i;
}

int topo(){
    int i=0;
    for(i=(TAMANHO-1); i>=0; i--){
        if(pilha[i]!=0){
            return pilha[i];
        }
    }
    return 1; //Pilha vazia
}

void imprimi(char *vet){
    for(int i=(TAMANHO-1); i>=0; i--){
        printf("| %c |\n", vet[i]);
    }
}

void validaFechamento(char c){
    int temp=topo();
    if(temp==c && temp!=1){
        pop();
    }
    else{
        system("cls");
        // printf("topo: %c, Char: %c\n", temp, c);
        printf("Fechamento incorreto");
        exit(1);
    }
}