#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 10

char pilha[TAMANHO];

void zeraPilha();
char topo(void);
int push(char input);
int pop(void);
void imprimi(void);

int main(void){
    zeraPilha();
    int escolha=0;
    char c;
    do{
        system("cls");
        printf("1 - Inserir\n2 - Remover\n3 - Pegar\n4 - Exibir\n5 - Sair\n\nEscolha: ");
        scanf("%d", &escolha);
        fflush(stdin);
        switch (escolha){
            case 1:
                printf("Qual valor deseja inserir: ");
                scanf("%c", &c);
                fflush(stdin);
                push(c);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("\nVoce pegou: %c\n", topo());
                system("pause");
                break;
            case 4:
                imprimi();
                break;
            default:
                printf("Digite um valor valido");
                system("pause");
        }
    }while(escolha!=5);
    return 0;
}

void zeraPilha(){
    for(int i=0; i<TAMANHO; i++){
        pilha[i]=0;
    }
}

char topo(){
    int i;
    for(i=(TAMANHO-1); i>=0; i--){
        if(pilha[i]!=0){
            return pilha[i];
        }
    }
    return i;
}

int push(char input){
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
    int i=0;
    for(i=(TAMANHO-1); i>=0; i--){
        if(pilha[i]!=0){
            pilha[i]=0;
            return 0;
        }
    }
    return i;
}

void imprimi(){
    for(int i=(TAMANHO-1); i>=0; i--){
        printf("| %1c |\n", pilha[i]);
    }
    system("pause");
}
