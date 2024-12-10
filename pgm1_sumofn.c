#include<stdio.h>
int main()
{
	int i,n,sum=0;
	printf("enter the no of elements:");
	scanf("%d",&n);
	printf("sum of n numbers:");
	for(i=1;i<=n;i++)
	{
		sum=sum+i;
	}
		printf("%d",sum);
		return(0);
}
