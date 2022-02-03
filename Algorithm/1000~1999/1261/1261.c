#include<stdio.h>
int map[102][102],wall[102][102];
int n,m,mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
int head=0,tail=1,que[100002][2],x,y,nx,ny;
int main()
{
    scanf("%d %d",&n,&m);//n이 가로 m이 세로
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%1d",&map[i][j]);
            wall[i][j]=10002;
        }
    }
    wall[0][0]=0;
    que[0][0]=0;
    que[0][1]=0;
    while(head<tail){
        x=que[head][0];
        y=que[head][1];
        head++;
        for (int i = 0; i < 4; i++)
        {
            nx=x+mx[i];
            ny=y+my[i];
            if(0<=nx&&nx<m&&0<=ny&&ny<n){
                if(map[nx][ny]){
                    if(wall[nx][ny]>wall[x][y]+1){
                    wall[nx][ny]=wall[x][y]+1;
                    que[tail][0]=nx;
                    que[tail][1]=ny;
                    tail++;
                    }
                }
                else{
                    if(wall[nx][ny]>wall[x][y]){
                    wall[nx][ny]=wall[x][y];
                    que[tail][0]=nx;
                    que[tail][1]=ny;
                    tail++;
                    }
                }
            }
        }
    }
    printf("%d",wall[m-1][n-1]);
    return 0;
}