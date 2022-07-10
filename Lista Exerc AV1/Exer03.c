#include <stdio.h>
#include <string.h>
#define STRMAX 50

void troca(char *str1, char *str2){
	char straux[STRMAX];
	strcpy(straux,str1);
	strcpy(str1,str2);
	strcpy(str2,straux);
}

int main(){
	char palavra1[STRMAX], palavra2[STRMAX];
	printf("Digite a primeira palavra: \n");
	gets(palavra1);
	printf("Digite a segunda palavra: \n");
	gets(palavra2);
	
	troca(palavra1,palavra2);
	printf("\nagora a primeira palavra eh: %s\ne a segunda palavra eh: %s", palavra1, palavra2);
	return 0;
}

