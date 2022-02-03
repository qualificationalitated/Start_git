#include<stdio.h>
int map[255][255],n,m,count=0;
int mx[8]={1,1,1,0,-1,-1,-1,0},my[8]={1,0,-1,-1,-1,0,1,1};
int find(int x,int y)
{
    map[x][y]=0;
    for (int i = 0; i < 8; i++)
    {
        int nx=x+mx[i];
        int ny=y+my[i];
        if(0<=nx&&0<=ny&&nx<n&&ny<m&&map[nx][ny]==1)
        {
            find(nx,ny);
        }
    }
    return 0;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d",&map[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if(map[i][j]==1){
                count++;
                find(i,j);
            }
        }
    printf("%d",count);
    return 0;
}