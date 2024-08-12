#include<stdio.h>
void main()
{
	int i,row1,row2,deg,A[50],B[50],sum[50];
	printf("Enter the degree of polynomial 1:");
	scanf("%d",&row1);
	printf("Enter the degree of polynomial 2:");
	scanf("%d",&row2);
	for(i=row1;i>=0;i--)
	{
		printf("Enter the coefficient of X^%d of polynomial 1:",i);
		scanf("%d",&A[i]);
	}
	for(i=row2;i>=0;i--)
	{
		printf("Enter the coefficient of X^%d of polynonmial 2:",i);
		scanf("%d",&B[i]);
	}
	deg=(row1>row2)?row1:row2;
	for(i=deg;i>=0;i--)
	{
		sum[i]=A[i]+B[i];
	}
	printf("The sum of polynomial is:");
 	for(i=deg;i>=0;i--)
	{
		printf("%dX^%d+",sum[i],i);
	}
}

