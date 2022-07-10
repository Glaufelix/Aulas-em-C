#include<stdio.h>
#include<stdlib.h>
#include "cubo.h"

int main(){
	float area, volume;
	Cubo* c;
	c=cubo_cria(10);
	area=cubo_area(c);
	volume=cubo_volume(c);
	printf("A área do cubo é: %f\n", area);
	printf("O volume do cubo é: %f\n", volume);
	
	return 0;
}
