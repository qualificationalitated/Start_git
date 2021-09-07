#include<stdio.h>
int map[1002][1002]={0,};
int visited[1002]={0,};
int n,m;
int find(int now)
{
	visited[now]=1;
	for (int i = 1; i <= n; i++)
		if(map[now][i]==1&&!visited[i])
			find(i);
	return 0;
}
int main()
{
	int a,b,count=0;
	scanf("%d %d",&n,&m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d",&a,&b);
		map[a][b]=1;
		map[b][a]=1;
	}
	for (int i = 1; i <= n; i++){
		if(!visited[i]){
			count++;
			find(i);
		}
	}
	printf("%d",count);
	return 0;
}