#include<stdio.h>
#include<conio.h>
int factorial(int n){
  if(n==0){
    return 1;
  }
  else{
    return n * factorial(n-1);
  }
}
int fibonacci(int n)
{
  if(n==0)
  {
    return 0;
  }
  else if(n==1)
  {
   return 1;
  }
  else
  {
    return (fibonacci(n-1) + fibonacci(n-2));
  }
}
int main()
{
  int n,i;
  clrscr();
  printf("Enter the number of elements:");
  scanf("%d",&n);
  printf("Factorial is:");
  printf("%d",factorial(n));
  printf("\n");
  printf("Fibonacci is:");
  fibonacci(n);
  for(i=0;i<n;i++)
  {
    printf(" %d ",fibonacci(i)) ;

  }
  getch();
  return 0;
}