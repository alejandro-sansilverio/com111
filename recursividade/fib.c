#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
  if(n==1||n==2) return 1;
  else return fib(n-1) + fib(n-2);
}

int main()
{
  int n, i;
  do
  {
    printf("Digite a sequencia:");
    scanf("%d", &n);
  }while(n<3);
    printf("Serie Fibonaci com %d termos\n", n);
  for(i=1;i<=n;i++)
  {
     printf(" %d\n", fib(i));
  }
}
