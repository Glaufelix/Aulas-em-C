#include<stdio.h>
#include<stdlib.h>
#include "ciindro.h"

int main(){
	float volume;
	Ponto *p, *q;
	r=cld_cria(4);
	h=cld_cria(10);
	v=cld_volume(r,h);
	printf("O volume do cilindro é: %f", v);
	pto_libera(r);
	pto_libera(h);
	return 0;
