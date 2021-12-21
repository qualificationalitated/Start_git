#include<stdio.h>
int map[102][102]={0,},visit[102]={0,};
int n,a,b,m;
int find(int x){
	for (int i = 1; i <= n; i++)
		if (map[x][i]&&visit[i]==0){
			visit[i]=visit[x]+1;
			find(i);
		}
	return 0;
}
int main()
{
	scanf("%d %d %d %d",&n,&a,&b,&m);
	for (int i = 0; i < m; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		map[x][y]=1;
		map[y][x]=1;
	}
	visit[a]=1;
	find(a);
	if(visit[b])
		printf("%d",visit[b]-1);
	else
		printf("-1");
	return 0;
}