#include<stdio.h>
int map[102][102],n;
int possible[102][102];
int find(int root,int now)
{
	for (int i = 0; i < n; i++)
	{
		if(map[now][i]==1&&possible[root][i]==0)
		{
			possible[root][i]=1;
			find(root,i);
		}
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d",&map[i][j]);
	for (int i = 0; i < n; i++)
	{
		find(i,i);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ",possible[i][j]);
		}
		printf("\n");
	}
	return 0;
}