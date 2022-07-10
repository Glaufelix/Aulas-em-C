#include<stdio.h>
#include<stdlib.h>
#include "cilindro.h"

int main(){
	float volume;
	Cilindro* c;
	volume = cld_volume(4,10);
	printf("O volume do cilindro é: %f", volume);

	return 0;
}
