#include<stdio.h>
int num[21],cnt=0,n,s;
int find(int loc,int sum)
{
	if(n<=loc)
		return 0;
	if(sum+num[loc]==s)
		cnt++;
	find(loc+1,sum+num[loc]);
	find(loc+1,sum);
	return 0;
}
int main()
{
	scanf("%d %d",&n,&s);
	for (int i = 0; i < n; i++)
		scanf("%d",&num[i]);
	find(0,0);
	printf("%d",cnt);
	return 0;
}