#include<stdio.h>
void main()
{
	int a[20],n,i,k;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter the array elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("The array elements are:");
	{
		for(i=0;i<n;i++)
		{
			printf("%d\t",a[i]);
		}
	}
	printf("\nEnter the element to be searched:");
	scanf("%d",&k);
	for(i=0;i<n;i++)
	{
		if(a[i]==k)
		{
			printf("Element found at %d index",i);
			break;
		}
	}
	if(i==n)
	{
		printf("Element not found in the array");
	}
}
