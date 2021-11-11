#include<stdio.h>
int map[103][103],visit[103][103];
int n,m,rmch=0,time=0;
int findcheese(int x,int y)
{
    int mx[4]={1,0,-1,0},my[4]={0,1,0,-1},nx,ny;
    visit[x][y]=time;
    for (int i = 0; i < 4; i++)
    {
        nx=x+mx[i];
        ny=y+my[i];
        if(0<=nx&&nx<=n+1&&0<=ny&&ny<=m+1&&visit[nx][ny]<time)
        {
            if(map[nx][ny]==0) // 빈공간
                findcheese(nx,ny);
            else{ // 공기 옆에 치즈 발견!
                rmch++;
                map[nx][ny]=0;
                visit[nx][ny]=time;
            }
        }
    }
    return 0;
}
int main()
{
    int ans;
    scanf("%d %d",&n,&m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d",&map[i][j]);
    while(1)
    {
        time++;
        ans=rmch;
        rmch=0;
        findcheese(0,0);
        if (!rmch)
            break;
    }
    printf("%d\n%d",time-1,ans);
    return 0;
}