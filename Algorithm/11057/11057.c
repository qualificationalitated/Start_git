#include<stdio.h>
int list[1002][10];
int find(int x,int n)//x-시작 값, n 자리 수
{
	long long int sum=0;
	if(list[n][x])
		return list[n][x];
	if(n==1)
		return 10-x;
	else
	{
		for (int i = x; i < 10; i++)
			sum+=find(i,n-1);
		list[n][x]=sum%10007;
	}
	return list[n][x];
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",find(0,n));
	return 0;
}