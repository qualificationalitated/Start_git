#include<stdio.h>
int map[302][302],mx[4]={0,1,0,-1},my[4]={1,0,-1,0},visit[302][302];
int n,m,ans=0;
int fourSquareCheck(int x,int y){
    int zcount=0;
    for (int i = 0; i < 4; i++){
        int X=x+mx[i],Y=y+my[i];
        if(0<=X&&X<n&&0<=Y&&Y<m&&visit[X][Y]==0&&map[X][Y]==0)
            zcount++;
    }
    return zcount;
}
int find(int x,int y){
    visit[x][y]=1;
    map[x][y]-=fourSquareCheck(x,y);
    map[x][y]=map[x][y]>0?map[x][y]:0;
    for (int i = 0; i < 4; i++){
        int nx=x+mx[i],ny=y+my[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<m&&visit[nx][ny]==0&&map[nx][ny])
            find(nx,ny);
    }
    return 0;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d",&map[i][j]);
    while(1){
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                visit[i][j]=0;
        int cnt=0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if(map[i][j]&&visit[i][j]==0){
                    cnt++;
                    find(i,j);
                }
        if(cnt!=1){
            printf("%d",cnt>1?ans:0);
            break;
        }
        ans++;
    }
    return 0;
}