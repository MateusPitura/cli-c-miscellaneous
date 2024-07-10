//1 de 3 arquivos. Contem a logica da manutencao de cadastros em arquivos

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define CPF 12
#define NAME 50

typedef struct{
    char cpf[CPF];
    char nome[NAME];
    float salario;
    char sit;
} cad;

cad cadFun;
FILE *fp;

void mudarCor(int cor);
void gotoxy(int x, int y);

void principal(int option);
void copiar(FILE *fpi, FILE *fpo);
FILE *fileOpen(char *arqName, char *mode);
void clear(char *str, int tamanho);
int validaStr(char *str, int tamanho, int rangeMin, int rangeMax);
int filelen(FILE *fp);
int busca(char *wtdCpf);
int incluir(void);
int alterar(void);
int situacao(void);
int consultar(void);
void listar(char sit);
void cleanTrash(void);

void principal(int option){
    fp=fileOpen("cadfun.dad", "ab"); //Cria caso nao exista um arquivo binario para escrita. Se existir apenas abre
    fclose(fp);
    fp=fileOpen("cadfun.dad", "r+b");
    switch(option){
        case 1: incluir(); break;
        case 2: alterar(); break;
        case 3: situacao(); break;
        case 4: consultar(); break;
        case 5: listar('0'); break;
        case 6: listar('1'); break;
        case 7: cleanTrash(); break;
        case 8: 
			gotoxy(0, 27); //Para o texto de final de execucao
			mudarCor(112);
			exit(0); 
			break;
    }
    fclose(fp);
}

void copiar(FILE *fpi, FILE *fpo){ //Copia todo o conteudo de fpi para fpo
    int tamArq;
    tamArq=filelen(fpi);
    fseek(fpi, 0, SEEK_SET); //Posiciona o cursor do arquivo no inicio, para poder ler todos os cadastros
    while(ftell(fpi)<tamArq){ //Le todos os cadastros ate chegar ao fim
    	fread(&cadFun, sizeof(cad), 1, fpi);
        if(cadFun.sit=='0'){ //Apenas ira escrever no arquivo temporario os cadastros ativos
            fwrite(&cadFun, sizeof(cad), 1, fpo);
        }
	}
}

FILE *fileOpen(char *arqName, char *mode){
	FILE *fpi;
    fpi=fopen(arqName, mode);
    if(!fpi){
        system("Color 70");
        system("cls");
        printf("Erro ao abrir ou criar arquivo de entrada");
        exit(-1);
    
	}
    return fpi;
}

void clear(char *str, int tamanho){ //Preenche todos os espacos de um vetor com ' '
    for(int i=0; i<tamanho; i++){
        *(str+i)=' ';
    }
}

int validaStr(char *str, int tamanho, int rangeMin, int rangeMax){ //Filtra um string com base no seu tamanho em um range se caracteres permitidos. Retorna -1 em caso de CPF invalido
    clear(str, tamanho); //Preenche a string com espacos vazios, para saber se tem menos caracteres que o parametro tamanho
    fgets(str, tamanho, stdin); //Range do parametro deve incluir o \0
    fflush(stdin);
    for(int i=0; i<(tamanho-1); i++){
        if(!(*(str+i)>=rangeMin && *(str+i)<=rangeMax)){
            return -1;
        }
    }
}

int filelen(FILE *fp){ //Retorna o tamanho do arquivo
	fseek(fp, 0, SEEK_END);
	return ftell(fp);
}

int busca(char *wtdCpf){ //Busca e le o CPF no arquivo. Caso encontre retorna 0, caso nao encontre retorna -1
	char curCpf[CPF];
	int tamArq;
    tamArq=filelen(fp);
    fseek(fp, 0, SEEK_SET); //Posiciona o cursor do arquivo no inicio
    do{
        fread(curCpf, sizeof(cadFun.cpf), 1, fp);
        if(strcmp(wtdCpf, curCpf)==0){ //Strcmp retorna 0 se forem iguais
            fseek(fp, ftell(fp)-sizeof(cadFun.cpf), SEEK_SET); //Seta o cursor do arquivo no inicio de um CPF
            fread(&cadFun, sizeof(cad), 1, fp);
            return ftell(fp)-sizeof(cad);
        }
        else{
            fseek(fp, 60, SEEK_CUR); //Avanca para o proximo CPF
        }
    } while(ftell(fp)<tamArq); //se a posicao atual do cursor do arquivo for maior ou igual ao seu tamanho entao ele encerra a busca
    return -1; //caso nao encontro o cpf procurado retorna -1
}

int incluir(void){ //Inclui os dados do funcionario no arquivo. Retorna -1 em caso de CPF invalido ou duplicado
    int i=4;
    mudarCor(113);
    gotoxy(50,1);
    printf("INCLUIR NOVO FUNCIONARIO");
    mudarCor(112);
    //Leitura do cpf
    gotoxy(50, 2);
    printf("Digite o CPF do novo funcionario: ");
    if(validaStr(cadFun.cpf, CPF, 48, 57)==-1){ //48: 0, 57: 9. Assim o CPF tera apenas numeros
        gotoxy(50, 3);
        printf("CPF invalido ");
        mudarCor(116);
    	gotoxy(50,4);
    	printf("FALHA AO INCLUIR NOVO FUNCIONARIO");
        return -1;
    }
    if(busca(cadFun.cpf)!=-1){
        gotoxy(50, 3);
        printf("CPF duplicado ");
        mudarCor(116);
    	gotoxy(50,4);
    	printf("FALHA AO INCLUIR NOVO FUNCIONARIO");
        return -1;
    }
    //Leitura do nome
    clear(cadFun.nome, NAME); //Preenhce todo o nome com espacos vazios, para evitar lixo
    gotoxy(50, 3);
    printf("Digite o nome do novo funcionario: ");
    scanf("%49[^\n]", cadFun.nome); //%50[^\n]: le no maximo 49 caracters, [^\n] para de ler quando encontrar o \n (deixa o \n no buffer) 
    fflush(stdin);
    //leitura do salario
    do{
        gotoxy(50,i);
        printf("Digite o salario do novo funcionario: ");
        scanf("%f", &cadFun.salario);
        fflush(stdin);
        i++;
    } while(cadFun.salario<0); //Caso a pessoa digite um valor negativo o processo repete
    cadFun.sit='0'; //Por padrao o cadastro do funcionario e ativo
    fseek(fp, 0, SEEK_END); //Posiciona o cursor do arquivo no fim
    fwrite(&cadFun, sizeof(cad), 1, fp);
    mudarCor(114);
	gotoxy(50,i);
    printf("NOVO FUNCIONARIO INCLUIDO COM SUCESSO");
}

int alterar(void){ //Altera os dados do funcionario. Retorna -1 em caso de CPF invalido
    char wtdCpf[CPF];
    int option, curPos, i=5;
    mudarCor(113);
    gotoxy(50,1);
    printf("ALTERAR DADOS DE UM FUNCIONARIO");
    mudarCor(112);
    //Leitura do CPF
    gotoxy(50, 2);
    printf("Digite o CPF do funcionario: ");
    if(validaStr(wtdCpf, CPF, 48, 57)==-1){
        gotoxy(50, 3);
        printf("CPF invalido");
        mudarCor(116);
    	gotoxy(50,4);
    	printf("FALHA AO ALTERAR DADOS DO FUNCIONARIO");
        return -1;
    }
    curPos=busca(wtdCpf);
    if(curPos==-1){
        gotoxy(50, 3);
        printf("CPF nao encontrado");
        mudarCor(116);
    	gotoxy(50,4);
    	printf("FALHA AO ALTERAR DADOS DO FUNCIONARIO");
        return -1;
    }
    else{
        if(cadFun.sit=='1'){ //Caso o cadastro esteja inativo nao sera possivel o alterar
            gotoxy(50, 3);
            printf("Cadastro inativo");
            mudarCor(116);
    		gotoxy(50,4);
    		printf("FALHA AO ALTERAR DADOS DO FUNCIONARIO");
    		return -1;
        }
        else{
            gotoxy(50, 3);
            printf("1 - CPF 2 - Nome 3 - Salario. O que deseja alterar: ");
            scanf("%d", &option);
            fflush(stdin);
            switch(option){
                case 1:
                    gotoxy(50,4);
                    printf("Digite o novo CPF: ");
                    if(validaStr(cadFun.cpf, CPF, 48, 57)==-1){
                        gotoxy(50,5);
                        printf("CPF invalido");
                        mudarCor(116);
    					gotoxy(50,6);
    					printf("FALHA AO ALTERAR DADOS DO FUNCIONARIO");
                        return -1;
                    }
                    if(busca(cadFun.cpf)!=-1){
        				gotoxy(50, 5);
				        printf("CPF duplicado ");
                        mudarCor(116);
    					gotoxy(50,6);
    					printf("FALHA AO ALTERAR DADOS DO FUNCIONARIO");
				        return -1;
    				}
                    break;
                case 2:
                    gotoxy(50,4);
                    printf("Digite o novo nome: ");
                    scanf("%49[^\n]", cadFun.nome);
                    fflush(stdin);
                    break;
                case 3:
                    do{
                        gotoxy(50,i-1);
                        printf("Digite o novo salario: ");
                        scanf("%f", &cadFun.salario);
                        fflush(stdin);
                        i++;
                    } while(cadFun.salario<0);
                    i--;
                    break;
                default: 
                    gotoxy(50,4);
                    printf("Escolha invalida");
                    mudarCor(116);
    				gotoxy(50,5);
    				printf("FALHA AO ALTERAR DADOS DO FUNCIONARIO");
                    return -1;
            }
            fseek(fp, curPos, SEEK_SET);
            fwrite(&cadFun, sizeof(cad), 1, fp); //Sobresscreve os dados, so funciona se for r+b
            mudarCor(114);
    		gotoxy(50,i);
    		printf("DADOS DO FUNCIONARIO ALTERADOS COM SUCESSO");
        }
    }
}

int situacao(void){ //Comuta a situacao do funcionario. Retorna -1 em caso de CPF invalido
    char wtdCpf[CPF];
    int curPos;
    mudarCor(113);
    gotoxy(50,1);
    printf("MUDAR SITUACAO DE UM FUNCIONARIO");
    mudarCor(112);
    gotoxy(50, 2);
    printf("Digite o CPF do funcionario: ");
    if(validaStr(wtdCpf, CPF, 48, 57)==-1){
        gotoxy(50,3);
        printf("CPF invalido");
        mudarCor(116);
    	gotoxy(50,4);
    	printf("FALHA AO MUDAR A SITUACAO DO FUNCIONARIO");
        return -1;
    }
    curPos=busca(wtdCpf);
    if(curPos==-1){
        gotoxy(50,3);
        printf("CPF nao encontrado");
        mudarCor(116);
    	gotoxy(50,4);
    	printf("FALHA AO MUDAR A SITUACAO DO FUNCIONARIO");
        return -1;
    }
    else{
        if(cadFun.sit == '0'){
            cadFun.sit='1';
        } else {
            cadFun.sit = '0';
        }
        fseek(fp, curPos, SEEK_SET);
        fwrite(&cadFun, sizeof(cad), 1, fp);
        gotoxy(50,3);
        printf("Agora a situacao de %s esta %s", cadFun.nome, cadFun.sit=='0'?"ATIVA":"INATIVA");
        mudarCor(114);
    	gotoxy(50,4);
    	printf("SITUACAO DO FUNCIONARIO ALTERADA COM SUCESSO");
    }
}

int consultar(void){ //Exibe os dados do funcionario. Nao exibe caso o funcionario esteja inativo. Retorna -1 em caso de CPF invalido
    char wtdCpf[CPF];
    mudarCor(113);
    gotoxy(50,1);
    printf("CONSULTAR DADOS DE UM FUNCIONARIO");
    mudarCor(112);
    gotoxy(50, 2);
    printf("Digite o CPF do funcionario: ");
    if(validaStr(wtdCpf, CPF, 48, 57)==-1){
        gotoxy(50, 3);
        printf("CPF invalido");
        mudarCor(116);
    	gotoxy(50,4);
    	printf("FALHA AO CONSULTAR DADOS DO FUNCIONARIO");
        return -1;
    }
    if(busca(wtdCpf)==-1){
        gotoxy(50, 3);
        printf("CPF nao encontrado");
        mudarCor(116);
    	gotoxy(50,4);
    	printf("FALHA AO CONSULTAR DADOS DO FUNCIONARIO");
        return -1;
    }
    else{
        if(cadFun.sit=='1'){
            gotoxy(50, 3);
            printf("Cadastro inativo");
	        mudarCor(116);
	    	gotoxy(50,4);
	    	printf("FALHA AO CONSULTAR DADOS DO FUNCIONARIO");
            return -1;
        }
        else{
            gotoxy(50, 4);
            printf("CPF: %s", cadFun.cpf);
            gotoxy(50, 5);
            printf("Nome: %s", cadFun.nome);
            gotoxy(50, 6);
            printf("Salario: %.2f", cadFun.salario);
            gotoxy(50, 7);
            printf("Situacao: %s", cadFun.sit=='0'?"Ativo":"Inativo");
        }
    }
}

void listar(char sit){ //Lista os cadastros ativos de sit for 1 ou os inativos se sit for 0
    int tamArq, i=2;
    mudarCor(113);
    gotoxy(50,1);
    printf("LISTA DE FUNCIONARIOS %s", sit=='0'?"ATIVOS":"INATIVOS");
    mudarCor(112);
    tamArq=filelen(fp);
    fseek(fp, 0, SEEK_SET);
    gotoxy(50, i);
    printf("|     CPF     |                        NOME                        | SALARIO |   SIT   |");
    gotoxy(50, ++i);
    printf("|-------------|----------------------------------------------------|---------|---------|");
    do{
        fread(&cadFun, sizeof(cad), 1, fp);
        if(cadFun.sit==sit){
            gotoxy(50, ++i);
            printf("| %s | %-50s | R$%5.0f | %-7s |", cadFun.cpf, cadFun.nome, cadFun.salario, cadFun.sit=='0'?" ATIVA ":"INATIVA"); 
        }
    } while(ftell(fp)<tamArq);
}

void cleanTrash(void){ //Apaga todos os cadastros inativos
    mudarCor(114);
    gotoxy(50,1);
    printf("CADASTROS INATIVOS EXCLUIDOS COM SUCESSO");
    FILE *fpt; //Cria um ponteiro para um arquivo temporario
    fpt=fileOpen("temp.dad", "a+b"); 
    copiar(fp, fpt); //Copia os cadastros ativos do arquivo para um temporario
    fclose(fp);
    fp=fileOpen("cadfun.dad", "w+b"); //Reabre o arquivo em branco (w+b)
    copiar(fpt, fp); //Copia o conteudo do arquivo temporario para o arquivo
    fclose(fpt);
    if(remove("temp.dad")==-1){ //Apaga o arquivo temporario
        system("Color 70");
        system("cls");
        printf("Erro ao apagar arquivo temporario");
        exit(-1);
    }
    fclose(fp); //Fecha fp para poder reabri com r+b
    fp=fileOpen("cadfun.dad", "r+b");
}
