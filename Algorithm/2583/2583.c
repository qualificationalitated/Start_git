#include<stdio.h>
#include<stdlib.h>
int map[102][102],m,n,cnt;
int find(int x,int y)
{
	cnt++;
	map[x][y]=1;
	int nx,ny,mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
	for(int i=0;i<4;i++)
	{
		nx=x+mx[i];
		ny=y+my[i];
		if(0<=nx&&0<=ny&&nx<m&&ny<n&&map[nx][ny]==0)
			find(nx,ny);
	}
	return 0;
}
int cmp(const void *a, const void *b){
	return *(int*)a-*(int*)b;
}
int main(){
	int i,j,k,count=0;
	scanf("%d %d %d",&m,&n,&k);
	while(k--){
		int ax,ay,bx,by;
		scanf("%d%d%d%d",&ax,&ay,&bx,&by);
		for(i=ay;i<by;i++)
			for(j=ax;j<bx;j++)
				map[i][j]=1;
	}
	int size[n*m/2+1];
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			if(map[i][j]==0){
				cnt=0;
				find(i,j);
				size[count++]=cnt;
			}
	printf("%d\n",count);
	qsort(size,count,sizeof(int),cmp);
	for(i=0;i<count;i++)
		printf("%d ",size[i]);
	return 0;
}