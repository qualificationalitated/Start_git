#include<stdio.h>
int n,map[102][102],flood[102][102],visit[102][102];
int minH=__INT_MAX__,maxH=0,safe=1;
int find(int x,int y,int h)
{
	int nextx,nexty,mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
	visit[x][y]=h;
	for (int i = 0; i < 4; i++)
	{
		nextx=x+mx[i];
		nexty=y+my[i];
		if(0<=nextx&&0<=nexty&&nextx<n&&nexty<n&& flood[nextx][nexty]==0 && visit[nextx][nexty]<h){
			find(nextx,nexty,h);
		}
	}
	return 0;
	
}
int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d",&map[i][j]);
			if(map[i][j]<minH)
				minH=map[i][j];
			if(maxH<map[i][j])
				maxH=map[i][j];
		}
	}
	for (int h = minH; h < maxH; h++)
	{
		int land=0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if(map[i][j]<=h)
					flood[i][j]=1;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if(flood[i][j]==0&&visit[i][j]<h){
					land++;
					find(i,j,h);
				}
			}
		}
		if(safe<land)
			safe=land;
	}
	printf("%d",safe);
	return 0;
}