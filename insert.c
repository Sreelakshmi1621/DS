#include<stdio.h>
void main()
{
	int a[10],i,in,n,pos;
	printf("Enter the limit:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be inserted:");
	scanf("%d",&in);
	printf("Enter the position of the element to be inserted:");
	scanf("%d",&pos);
	for(i=n;i>=pos;i--)
	{
		a[i]=a[i-1];
	}
	a[pos-1]=in;
	for(i=0;i<n+1;i++)
	{
		printf("%d\t",a[i]);
	}
}
