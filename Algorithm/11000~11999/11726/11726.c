#include<stdio.h>
int main()
{
	int n,div=10007,arr[1002]={0,1,2,},i;
	scanf("%d",&n);
	for (i=3;i<=1000;i++)
	{
		arr[i]=arr[i-1]+arr[i-2];
		arr[i]%=div;
	}
	printf("%d",arr[n]);
	
	return 0;
}