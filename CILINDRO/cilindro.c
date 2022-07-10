#include<stdio.h>
#include<math.h>
#include"cilindro.h"

//definição de dados
struct cilindro{
	float x;
	float y;
};
// cria um novo ponto
Cilindro* cld_cria(float x, float y){
	Cilindro* c = (Cilindro*) malloc(sizeof(Ponto));
	if (c != NULL){
		c->x = x;
		c->y = y;
	}
	return c;
}

// libera uma ponto
void cld_libera(Cilindro* c){
	free(c);
}

// acessa os valores
void cld_acessa(Cilindro* c, float* x, float* y){
	*x=c->x;
	*y=c->y;
}

//atribuir os valores de "x" e "y"
void cld_atribui(Cilindro *c, float x, float y){
	c->x=x;
	c->y=y;
}

// calcula distancia
float cld_volume(Cilindro* c){
		float volume= r->x * r->x*h->y*3.14;
		return volume;
}
