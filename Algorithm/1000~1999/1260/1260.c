#include<stdio.h>
int n,m,v;
int map[1002][1002];
int visited[1002]={0,};
int worklist[1002]={0,},top=0,workloc=0;
int dfs(int now){
	printf("%d ",now);
	visited[now]=1;
	for (int i = 1; i <= n; i++)
		if(map[now][i]&&!visited[i])
			dfs(i);
	return 0;
}
int bfs(int now){
	printf("%d ",now);
	visited[now]=1;
	for (int i = 1; i <= n; i++)
		if(map[now][i]&&!visited[i]){
			visited[i]=1;
			worklist[++top]=i;
		}
	if (top<=workloc)
		return 0;
	bfs(worklist[++workloc]);
	return 0;
}
int main()
{
	int a,b;
	scanf("%d%d%d",&n,&m,&v);
	for (int i = 0; i < m; i++){
		scanf("%d%d",&a,&b);
		map[a][b]=1;
		map[b][a]=1;
	}
	dfs(v);
	printf("\n");
	for (int i = 0; i < 1002; i++)
		visited[i]=0;
	bfs(v);
	return 0;
}