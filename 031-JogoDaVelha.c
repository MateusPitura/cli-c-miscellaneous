//Jogo da velha

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int main(){
    setlocale(LC_ALL, "Portuguese");
    int jogada1, jogada2, jogada3, jogada4, jogada5, jogada6, jogada7, jogada8, jogada9, parar;
    char p1, p2, p3, p4, p5, p6, p7, p8, p9;
    p1=' ';
    p2=' ';
    p3=' ';
    p4=' ';
    p5=' ';
    p6=' ';
    p7=' ';
    p8=' ';
    p9=' ';
    printf("\n      |     |     \n   1  |  2  |  3  \n _____|_____|_____\n      |     |     \n   4  |  5  |  6  \n _____|_____|_____\n      |     |     \n   7  |  8  |  9  \n      |     |     \n");
    printf("\n Escolha um número: ");
    scanf("%d", &jogada1);
    switch(jogada1){
        case 1: p1='X'; break;
        case 2: p2='X'; break;
        case 3: p3='X'; break;
        case 4: p4='X'; break;
        case 5: p5='X'; break;
        case 6: p6='X'; break;
        case 7: p7='X'; break;
        case 8: p8='X'; break;
        case 9: p9='X'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    printf("\n Escolha outro número: ");
    scanf("%d", &jogada2);
    if(jogada2==jogada1){ 
        system("cls");
        printf("Esse número já foi escolhido, fim de jogo!");
        Sleep(5000);
        exit(1);
    }
    switch(jogada2){
        case 1: p1='O'; break;
        case 2: p2='O'; break;
        case 3: p3='O'; break;
        case 4: p4='O'; break;
        case 5: p5='O'; break;
        case 6: p6='O'; break;
        case 7: p7='O'; break;
        case 8: p8='O'; break;
        case 9: p9='O'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    printf("\n Escolha outro número: ");
    scanf("%d", &jogada3);
    if(jogada3==jogada1 || jogada3==jogada2){
        system("cls");
        printf("Esse número já foi escolhido, fim de jogo!");
        Sleep(5000);
        exit(1);
    }
    switch(jogada3){
        case 1: p1='X'; break;
        case 2: p2='X'; break;
        case 3: p3='X'; break;
        case 4: p4='X'; break;
        case 5: p5='X'; break;
        case 6: p6='X'; break;
        case 7: p7='X'; break;
        case 8: p8='X'; break;
        case 9: p9='X'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    printf("\n Escolha outro número: ");
    scanf("%d", &jogada4);
    if(jogada4==jogada1 || jogada4==jogada2 || jogada4==jogada3){
        system("cls");
        printf("Esse número já foi escolhido, fim de jogo!");
        Sleep(5000);
        exit(1);
    }
    switch(jogada4){
        case 1: p1='O'; break;
        case 2: p2='O'; break;
        case 3: p3='O'; break;
        case 4: p4='O'; break;
        case 5: p5='O'; break;
        case 6: p6='O'; break;
        case 7: p7='O'; break;
        case 8: p8='O'; break;
        case 9: p9='O'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    printf("\n Escolha outro número: ");
    scanf("%d", &jogada5);
    if(jogada5==jogada1 || jogada5==jogada2 || jogada5==jogada3 || jogada5==jogada4){
        system("cls");
        printf("Esse número já foi escolhido, fim de jogo!");
        Sleep(5000);
        exit(1);
    }
    switch(jogada5){
        case 1: p1='X'; break;
        case 2: p2='X'; break;
        case 3: p3='X'; break;
        case 4: p4='X'; break;
        case 5: p5='X'; break;
        case 6: p6='X'; break;
        case 7: p7='X'; break;
        case 8: p8='X'; break;
        case 9: p9='X'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    if((p1=='X' && p2=='X' && p3=='X') || (p4=='X' && p5=='X' && p6=='X') || (p7=='X' && p8=='X' && p9=='X') || (p1=='X' && p4=='X' && p7=='X') || (p2=='X' && p5=='X' && p8=='X') || (p3=='X' && p6=='X' && p9=='X')  || (p1=='X' && p5=='X' && p9=='X') || (p3=='X' && p5=='X' && p7=='X')){
        printf("\n X VENCEU!");
        Sleep(5000);
        exit(1);
    }
    printf("\n Escolha outro número: ");
    scanf("%d", &jogada6);
    if(jogada6==jogada1 || jogada6==jogada2 || jogada6==jogada3 || jogada6==jogada4 || jogada6==jogada5){
        system("cls");
        printf("Esse número já foi escolhido, fim de jogo!");
        Sleep(5000);
        exit(1);
    }
    switch(jogada6){
        case 1: p1='O'; break;
        case 2: p2='O'; break;
        case 3: p3='O'; break;
        case 4: p4='O'; break;
        case 5: p5='O'; break;
        case 6: p6='O'; break;
        case 7: p7='O'; break;
        case 8: p8='O'; break;
        case 9: p9='O'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    if((p1=='X' && p2=='X' && p3=='X') || (p4=='X' && p5=='X' && p6=='X') || (p7=='X' && p8=='X' && p9=='X') || (p1=='X' && p4=='X' && p7=='X') || (p2=='X' && p5=='X' && p8=='X') || (p3=='X' && p6=='X' && p9=='X')  || (p1=='X' && p5=='X' && p9=='X') || (p3=='X' && p5=='X' && p7=='X')){
        printf("\n X VENCEU!");
        Sleep(5000);
        exit(1);
    }
    if((p1=='O' && p2=='O' && p3=='O') || (p4=='O' && p5=='O' && p6=='O') || (p7=='O' && p8=='O' && p9=='O') || (p1=='O' && p4=='O' && p7=='O') || (p2=='O' && p5=='O' && p8=='O') || (p3=='O' && p6=='O' && p9=='O')  || (p1=='O' && p5=='O' && p9=='O') || (p3=='O' && p5=='O' && p7=='O')){
        printf("\n O VENCEU!");
        Sleep(5000);
        exit(1);
    }
    printf("\n Escolha outro número: ");
    scanf("%d", &jogada7);
    if(jogada7==jogada1 || jogada7==jogada2 || jogada7==jogada3 || jogada7==jogada4 || jogada7==jogada5 || jogada7==jogada6){
        system("cls");
        printf("Esse número já foi escolhido, fim de jogo!");
        Sleep(5000);
        exit(1);
    }
    switch(jogada7){
        case 1: p1='X'; break;
        case 2: p2='X'; break;
        case 3: p3='X'; break;
        case 4: p4='X'; break;
        case 5: p5='X'; break;
        case 6: p6='X'; break;
        case 7: p7='X'; break;
        case 8: p8='X'; break;
        case 9: p9='X'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    if((p1=='X' && p2=='X' && p3=='X') || (p4=='X' && p5=='X' && p6=='X') || (p7=='X' && p8=='X' && p9=='X') || (p1=='X' && p4=='X' && p7=='X') || (p2=='X' && p5=='X' && p8=='X') || (p3=='X' && p6=='X' && p9=='X')  || (p1=='X' && p5=='X' && p9=='X') || (p3=='X' && p5=='X' && p7=='X')){
        printf("\n X VENCEU!");
        Sleep(5000);
        exit(1);
    }
    if((p1=='O' && p2=='O' && p3=='O') || (p4=='O' && p5=='O' && p6=='O') || (p7=='O' && p8=='O' && p9=='O') || (p1=='O' && p4=='O' && p7=='O') || (p2=='O' && p5=='O' && p8=='O') || (p3=='O' && p6=='O' && p9=='O')  || (p1=='O' && p5=='O' && p9=='O') || (p3=='O' && p5=='O' && p7=='O')){
        printf("\n O VENCEU!");
        Sleep(5000);
        exit(1);
    }
    printf("\n Escolha outro número: ");
    scanf("%d", &jogada8);
    if(jogada8==jogada1 || jogada8==jogada2 || jogada8==jogada3 || jogada8==jogada4 || jogada8==jogada5 || jogada8==jogada6 || jogada8==jogada7){
        system("cls");
        printf("Esse número já foi escolhido, fim de jogo!");
        Sleep(5000);
        exit(1);
    }
    switch(jogada8){
        case 1: p1='O'; break;
        case 2: p2='O'; break;
        case 3: p3='O'; break;
        case 4: p4='O'; break;
        case 5: p5='O'; break;
        case 6: p6='O'; break;
        case 7: p7='O'; break;
        case 8: p8='O'; break;
        case 9: p9='O'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    if((p1=='X' && p2=='X' && p3=='X') || (p4=='X' && p5=='X' && p6=='X') || (p7=='X' && p8=='X' && p9=='X') || (p1=='X' && p4=='X' && p7=='X') || (p2=='X' && p5=='X' && p8=='X') || (p3=='X' && p6=='X' && p9=='X')  || (p1=='X' && p5=='X' && p9=='X') || (p3=='X' && p5=='X' && p7=='X')){
        printf("\n X VENCEU!");
        Sleep(5000);
        exit(1);
    }
    if((p1=='O' && p2=='O' && p3=='O') || (p4=='O' && p5=='O' && p6=='O') || (p7=='O' && p8=='O' && p9=='O') || (p1=='O' && p4=='O' && p7=='O') || (p2=='O' && p5=='O' && p8=='O') || (p3=='O' && p6=='O' && p9=='O')  || (p1=='O' && p5=='O' && p9=='O') || (p3=='O' && p5=='O' && p7=='O')){
        printf("\n O VENCEU!");
        Sleep(5000);
        exit(1);
    }
    printf("\n Escolha outro número: ");
    scanf("%d", &jogada9);
    if(jogada9==jogada1 || jogada9==jogada2 || jogada9==jogada3 || jogada9==jogada4 || jogada9==jogada5 || jogada9==jogada6 || jogada9==jogada7){
        system("cls");
        printf("Esse número já foi escolhido, fim de jogo!");
        Sleep(5000);
        exit(1);
    }
    switch(jogada9){
        case 1: p1='X'; break;
        case 2: p2='X'; break;
        case 3: p3='X'; break;
        case 4: p4='X'; break;
        case 5: p5='X'; break;
        case 6: p6='X'; break;
        case 7: p7='X'; break;
        case 8: p8='X'; break;
        case 9: p9='X'; break;
        default: system("cls"); printf("Esse número não está disponível, fim de jogo!"); Sleep(5000); exit(1);
    }
    system("cls");
    printf("\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n _____|_____|_____\n      |     |     \n   %c  |  %c  |  %c  \n      |     |     \n", p1, p2, p3, p4, p5, p6, p7, p8, p9);
    if((p1=='X' && p2=='X' && p3=='X') || (p4=='X' && p5=='X' && p6=='X') || (p7=='X' && p8=='X' && p9=='X') || (p1=='X' && p4=='X' && p7=='X') || (p2=='X' && p5=='X' && p8=='X') || (p3=='X' && p6=='X' && p9=='X')  || (p1=='X' && p5=='X' && p9=='X') || (p3=='X' && p5=='X' && p7=='X')){
        printf("\n X VENCEU!");
        Sleep(5000);
        exit(1);
    }
    else{
        if((p1=='O' && p2=='O' && p3=='O') || (p4=='O' && p5=='O' && p6=='O') || (p7=='O' && p8=='O' && p9=='O') || (p1=='O' && p4=='O' && p7=='O') || (p2=='O' && p5=='O' && p8=='O') || (p3=='O' && p6=='O' && p9=='O')  || (p1=='O' && p5=='O' && p9=='O') || (p3=='O' && p5=='O' && p7=='O')){
            printf("\n O VENCEU!");
            Sleep(5000);
            exit(1);
        }
        else{
            printf("\n DEU VELHA!");
            Sleep(5000);
            exit(1);
        }
    }
    return 0;
}
