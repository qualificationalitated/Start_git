#include<stdio.h>
int map[101][101],visit[101][101],que[10000],baconIsGood[101];
int main()
{
	int n,m,head,tail,min=__INT_MAX__,minloc;
	scanf("%d %d",&n,&m);
	for (int i = 0; i < m; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		map[a][b]=1;
		map[b][a]=1;
	}
	for (int i = 1; i <= n; i++){
		head=0;
		tail=1;
		int now=i;
		while(head<tail){
			for (int j = 1; j <= n; j++)
				if(map[now][j]==1&&visit[i][j]==0){
					visit[i][j]=visit[i][now]+1;
					que[tail++]=j;
				}
			now=que[++head];
		}
		for (int k = 1; k <= n; k++)
			baconIsGood[i]+=visit[i][k];
		baconIsGood[i]-=visit[i][i];
		if(min>baconIsGood[i]){
			min=baconIsGood[i];
			minloc=i;
		}
	}
	printf("%d",minloc);
	return 0;
}