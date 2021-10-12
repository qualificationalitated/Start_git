#include<stdio.h>
int n,m,map[502][502],visit[502][502],sum,max=0;
int mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
int find(int x,int y,int len)
{
	int nx,ny;
	if(len==4){
		if(max<sum)
			max=sum;
		return 0;
	}
	sum+=map[x][y];
	for(int i = 0; i < 4; i++){
		nx=x+mx[i];
		ny=y+my[i];
		if(0<=nx&&0<=ny&&nx<n&&ny<m&&visit[nx][ny]==0){
			visit[nx][ny]=1;
			find(nx,ny,len+1);
			visit[nx][ny]=0;
		}
	}
	sum-=map[x][y];
	return 0;
}
int main()
{
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%d",&map[i][j]);
	for(i=0;i<n;i++)
		for(j=0;j<m;j++){
			sum=0;
			visit[i][j]=1;
			find(i,j,0);
			visit[i][j]=0;
			if(i==0&&j>0&&j<m-1)//ㅜ
				sum=map[i][j]+map[i][j-1]+map[i][j+1]+map[i+1][j];
			else if(i==n-1&&j>0&&j<m-1)//ㅗ
				sum=map[i][j]+map[i][j-1]+map[i][j+1]+map[i-1][j];
			else if(j==0&&i>0&&i<n-1)//ㅏ
				sum=map[i][j]+map[i-1][j]+map[i+1][j]+map[i][j+1];
			else if(j==m-1&&i>0&&i<n-1)//ㅓ
				sum=map[i][j]+map[i-1][j]+map[i+1][j]+map[i][j-1];
			else if(i>0&&i<n-1&&j>0&&j<m-1) // ㅗㅜㅏㅓ
			{
				int min=__INT_MAX__;
				for (int k = 0; k < 4; k++){
					sum+=map[i+mx[k]][j+my[k]];
					if(min>map[i+mx[k]][j+my[k]])
						min=map[i+mx[k]][j+my[k]];
				}
				sum-=min;
				sum+=map[i][j];
			}
			if(max<sum)
				max=sum;
		}
	printf("%d",max);
	return 0;
}