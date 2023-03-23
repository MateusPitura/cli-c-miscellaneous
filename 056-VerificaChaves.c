#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 100

char pilha[TAMANHO];
char expressao[TAMANHO];
int topo=-1;

void push(int input);
void pop();
void topoPilha();
void imprimi();
void validaFechamento(char c);

int main(void){
    do{
        printf("Digite uma expressao: ");
        fgets(expressao, TAMANHO, stdin);
        printf("%s", expressao);
        fflush(stdin);
        int i;
        for(i=0; expressao[i]!='\0'; i++){
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
        }
        if(topo==-1){
            printf("Fechamento correto\n");
        }
        else{
            printf("Fechamento incorreto\n");
        }
    }while(1);
    return 0;
}

void push(int input){
    if(topo==TAMANHO-1){
        printf("Pilha cheia\n");
        return;
    }
    topo++;
    pilha[topo]=input;
}

void pop(){
    if(topo==-1){
        printf("Pilha vazia\n");
        return;
    }
    topo--;
}

void topoPilha(){
    if(topo==-1){
        printf("Pilha vazia\n");
        return;
    }
    printf("Topo: %c\n", pilha[topo]);
}

void validaFechamento(char c){
    if(topo==-1){
        system("cls");
        printf("Fechamento incorreto");
        exit(1);
    }
    else if(pilha[topo]==c){
        pop();
    }
}