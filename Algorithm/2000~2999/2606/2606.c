#include<stdio.h>
int net[102][102]={0,};
int visited[102]={0,};
int n,count=0;
int find(int now)
{
	visited[now]=1;
	count++;
	for (int i = 1; i <= n; i++)
		if(net[now][i]&&visited[i]==0){
			find(i);
		}
	return 0;
}
int main()
{
	int m,a,b;
	scanf("%d %d",&n,&m);
	for (int i = 0; i < m; i++){
		scanf("%d %d",&a,&b);
		net[a][b]=1;
		net[b][a]=1;
	}
	find(1);
	printf("%d",count-1);
	return 0;
}