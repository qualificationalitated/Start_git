#include<stdio.h>
int map[502][502],n,m,dp[502][502]={0,},mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
int find(int x,int y){
    if(x==n-1&&y==m-1)
        return 1;
    if(dp[x][y]!=-1)
        return dp[x][y];
    dp[x][y]=0;
    for (int i = 0; i < 4; i++)
    {
        int nx=x+mx[i],ny=y+my[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<m&&map[nx][ny]<map[x][y])
            dp[x][y]+=find(nx,ny);
    }
    return dp[x][y];
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            dp[i][j]=-1;
            scanf("%d",&map[i][j]);
        }
    printf("%d",find(0,0));
    return 0;
}