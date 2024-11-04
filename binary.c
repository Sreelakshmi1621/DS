#include<stdio.h>
void main()
{
	int arr[20],i,n,left,right,mid,num;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter the array elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be search:");
	scanf("%d",&num);
	left=0;
	right=n-1;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(arr[mid]==num)
		{
			printf("The elements is found at position %d:",mid); 
			break;
		}
		else if(arr[mid]>num)
			right=mid-1;
		else
			left=mid+1;
	}
	if(left>right)
		printf("Element not found in list");
}
		

