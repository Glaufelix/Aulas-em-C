#include<stdio.h>
#include<math.h>
#include"esfera.h"

struct esfera{
	float a;
};

Esfera* sfr_cria (float a){
	Esfera* e = (Esfera*) malloc(sizeof(Esfera));
	if (e != NULL){
		e->a = a;
	}
	return e;
}

void sfr_libera(Esfera* e){
	free(e);
}

void sfr_acessa(Esfera* e, float* a){
	*a=e->a;
}

void sfr_atribui(Esfera *e, float a){
	e->a=a;
}

float sfr_volume(Esfera* e){
	float volume = 4 * 3.14 * e->a * e->a * e->a;
	return volume;
}

