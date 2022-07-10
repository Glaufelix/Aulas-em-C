#include <stdio.h>
#include <string.h>
struct Produto{
	char nome[30];
	int codigo;
	double preco;
};

int main(){
	//int i;
	struct Produto prod[10];
	strcpy(prod[0].nome,"Pe de Moleque");	
	prod[0].codigo = 13205;
	prod[0].preco = 0.20;
	strcpy(prod[1].nome,"Cocada Baiana");
	prod[1].codigo = 15202;
	prod[1].preco = 0.50;
	//for(i=0; i <= 1; i++){
	//	printf("\n\nProd %d: %s",i+1, prod[i].nome);
	//	printf("\nCodigo: %d",prod[i].codigo);
	//	printf("\nPreco : R$ %.2f", prod[i].preco);
	//}

	return 0;
}
