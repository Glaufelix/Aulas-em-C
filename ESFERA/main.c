#include<stdio.h>
#include<stdlib.h>
#include "esfera.h"

int main(){
	float volume;
	Esfera* e;
	e=sfr_cria(10);
	volume=sfr_volume(e);
	printf("O volume do cubo é: %f\n", volume);
	
	return 0;
}
