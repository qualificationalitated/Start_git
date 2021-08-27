#include<stdio.h>
int count;
int check(int x)
{
	if(!x)
		count++;
	if(x>=1)
	{
		check(x-1);
		if(x>=2)
		{
			check(x-2);
			if(x>=3)
				check(x-3);
		}
	}
	return 0;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%d",&n);
		check(n);
		printf("%d\n",count);
	}
	return 0;
}