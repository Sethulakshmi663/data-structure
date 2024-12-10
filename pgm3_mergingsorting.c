#include<stdio.h>
int a[10],b[10],d[20],m,n,i,j;
void sort(int c[],int size)
{
	int temp;
	for(i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(c[i]>c[j])
			{
				temp=c[i];
				c[i]=c[j];
				c[j]=temp;
			}
		}
	}
}
void merge(int a[],int b[],int size1,int size2)
{
	for(i=0;i<size1;i++)
	{
		d[i]=a[i];
	}
	for(i=0;i<size2;i++)
	{
		d[m+i]=b[i];
	}
}
void display(int c[],int size)
{
	for(i=0;i<size;i++)
	{
		printf("%d\n",c[i]);
	}
}
int main()
{
	printf("enter the number of elements in the first array:");
	scanf("%d",&m);
	printf("enter the elements in the first array:");
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i]);
	}	
	printf("\nenter the  number elements in the second array:");
	scanf("%d",&n);
	printf("\nenter the elements in the second array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	printf("\nenter the unsorted first array:");
	display(a,m);
	printf(" \nenter the unsorted second array:");
	display(b,n);
	sort(a,m);
        sort(b,n);
	printf("\nenter the sorted first array:");
	display(a,m);
	printf(" \nenter the sorted second array:");
	display(b,n);
	int merged_size= m+n;
	printf("\nmerged array:");
	merge(a,b,m,n);
	display(d,merged_size);
	sort(d,merged_size);
	printf("\n merged array and sorted array:");
	display(d,merged_size);
return(0);
}


