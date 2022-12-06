//Verifica se uma palavra e um palindromo

#include <stdio.h>
#include <string.h>

int main(){
	char str1[100], str2[100], str3[100];
	int tam, log=0, l, k;
	printf("Digite uma frase em minusculo!: ");
	gets(str1);
	tam=strlen(str1);
	//for(int i=0; i<=tam; i++) 
	//	if(str1[i]<90) str1[i]=str1[i]+32;
	//puts(str1);
	//for(int i=0, k=tam-1; k>=0; i++, k--){
	//	while(str1[i]==' ') i++;
	//	while(str1[k]==' ') k--;
	//	if(str1[i]!=str1[k]) log=1;
	//}
	//if(log==1) printf("Nao e um palindromo");
	//else printf("E um palindromo");
	for(int i=0, j=0; i<=tam; i++)
		if(str1[i]!=' '){
			str2[j]=str1[i];
			j++;
		}
	tam=strlen(str2);
	for(l=0, k=tam-1; k>=0; l++, k--)
		str3[k]=str2[l];
	str3[l]='\0';
	puts(str2);
	puts(str3);
	if(strcmpi(str2, str3)==0) printf("E um palindromo");
	else printf("Nao e um palindromo");
}
