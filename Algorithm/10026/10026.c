#include<stdio.h>
int n,visit[102][102];
int nextx,nexty,mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
char map[102][103];
int nfind(int x,int y)
{
	visit[x][y]=1;
	for (int i = 0; i < 4; i++)
	{
		nextx=x+mx[i];
		nexty=y+my[i];
		if(0<=nextx&&0<=nexty&&nextx<n&&nexty<n&&map[x][y]==map[nextx][nexty]&&visit[nextx][nexty]==0)
			nfind(nextx,nexty);
	}
	if(map[x][y]=='G')
		map[x][y]='R';
	return 0;
}
int unfind(int x,int y)
{
	visit[x][y]=0;
	for (int i = 0; i < 4; i++)
	{
		nextx=x+mx[i];
		nexty=y+my[i];
		if(0<=nextx&&0<=nexty&&nextx<n&&nexty<n&&map[x][y]==map[nextx][nexty]&&visit[nextx][nexty]==1)
			unfind(nextx,nexty);
	}
	return 0;
}
int main()
{
	int normal=0,unnormal=0;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		scanf("%s",map[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if(visit[i][j]==0){
				normal++;
				nfind(i,j);
			}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if(visit[i][j]==1){
				unnormal++;
				unfind(i,j);
			}
	printf("%d %d",normal,unnormal);
	return 0;
}