#include<stdio.h>
#include<conio.h>
void fibonacci(int n)
{
  int n1=0,n2=1,n3,i;
  printf("%d%d",n1,n2);
  for(i=2;i<n;i++)
  {
    n3=n1+n2;
    printf("%d",n3);
    n1=n2;
    n2=n3;
  }
}
void factorial(int n)
{
  int i;
  for(i=1;i<n;i++)
  {
     fact*=i;
  }
}
int main()
{  int n;
   clrscr();
   printf("enter the elements:");
   scanf("%d",&n);
   fibonacci(n);
   getch();
   return 0;

}