#include<stdio.h>
int map[10][10];
int n,m,v=0,min=__INT_MAX__,safe=0;
typedef struct grid{
	int x,y;
}grid;
grid virus[10],que[102];
int find(){
	int head=0,tail=v,count=0;
	for (int i = 0; i < v; i++){
		que[i]=virus[i];
	}
	int x,y,mx[4]={1,0,-1,0},my[4]={0,1,0,-1},nx,ny;
	while(head<tail){
		x=que[head].x;
		y=que[head].y;
		head++;
		for (int i = 0; i < 4; i++)
		{
			nx=x+mx[i];
			ny=y+my[i];
			if(0<=nx&&nx<n&&0<=ny&&ny<m&&map[nx][ny]==0){
				map[nx][ny]=2;
				count++;
				que[tail].x=nx;
				que[tail].y=ny;
				tail++;
			}
		}
	}
	for (int i = v; i < tail; i++)
		map[que[i].x][que[i].y]=0;
	return count;
}
int makewall(int w){
	
	if(w==3){
		int r=find();
		if(min>r){
			min=r;
		}
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if(map[i][j]==0){
				map[i][j]=1;
				makewall(w+1);
				map[i][j]=0;
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d %d",&n,&m);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]==0)
				safe++;
			if(map[i][j]==2){
				virus[v].x=i;
				virus[v].y=j;
				v++;
			}
		}
	}
	makewall(0);
	printf("%d",safe-min-3);
	return 0;
}