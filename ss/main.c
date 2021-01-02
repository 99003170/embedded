#include<stdio.h>
int main()
{
int num;
int a,b;
int sum=0;
int mul=0;
int div=0;
printf("enter the choice");
scanf("%d",&num);
switch(num)
{
case 1:
sum=a+b;
printf("%d",sum);
break;
case 2:
mul=a*b;
printf("%d",mul);
break;
case 3:
div=a%b;
printf("%d",div);
break;
default:
printf("invalid");
break;
}
}