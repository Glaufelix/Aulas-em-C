#include<stdio.h>
#include<math.h>
#include"cubo.h"

//definição de dados
struct cubo{
	float a;
};
// cria um novo ponto
Cubo* cubo_cria (float a){
	Cubo* c = (Cubo*) malloc(sizeof(Cubo));
	if (c != NULL){
		c->a = a;
	}
	return c;
}

// libera uma ponto
void Cubo_libera(Cubo* c){
	free(c);
}

// acessa os valores
void cubo_acessa(Cubo* c, float* a){
	*a=c->a;
}

//atribuir os valores de "x" e "y"
void cubo_atribui(Cubo *c, float a){
	c->a=a;
}

// calcula distancia
float cubo_area(Cubo* c){
	float area = 6 * c->a * c->a	;
	return area;
}
float cubo_volume(Cubo* c){
	float volume = c->a * c->a * c->a;
	return volume;
}
