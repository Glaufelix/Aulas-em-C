#include <stdio.h>
#include <stdlib.h>

int fibonnaci (int);

int main()
{
  int n,i,fib;
   printf("Entre com um numero: ");
   scanf("%d", &n);
	fib=fibonacci(n);  
    printf("%d ", fib);
   getch();
} 

int fibonacci(int num)
{
   if(num==1 || num==2)
       return 1;
   else
       return fibonacci(num-1) + fibonacci(num-2); 
}

