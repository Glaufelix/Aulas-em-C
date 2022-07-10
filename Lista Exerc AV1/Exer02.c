#include <stdio.h>
void Zera(int *a, int *b)
{
*a=*b=0;
}
void main()
{
int a, b;
printf("Digite dois numeros inteiros \nUse apenas um espaco entre eles: \n");
scanf("%d %d", &a, &b);
printf("Numeros digitados: %d, %d\n",a,b);
Zera(&a,&b); 
printf("Os numeros agora valem %d e %d\n",a,b);
}
