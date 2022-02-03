#include<stdio.h>
typedef struct status{
    int x,y,wall;
}st;
int map[1002][1002],visit[1002][1002][2];
int n,m,head,tail,mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
char s[1002];
st que[2000002];
int main()
{
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++){
        scanf("%s",s);
        for (int j = 0; j < m; j++)
            map[i][j]=s[j]-'0';
    }
    for (int i = 0; i < 1002; i++)
        for (int j = 0; j < 1002; j++){
            visit[i][j][0]=__INT_MAX__;
            visit[i][j][1]=__INT_MAX__;
        }
    
    visit[0][0][0]=1;
    visit[0][0][1]=1;
    que[tail].x=0;
    que[tail].y=0;
    que[tail].wall=0;
    tail++;
    while(head<tail){
        int x=que[head].x,y=que[head].y,b=que[head].wall;
        head++;
        for (int i = 0; i < 4; i++)
        {
            int nx=x+mx[i],ny=y+my[i];
            if(0<=nx&&nx<n&&0<=ny&&ny<m){
                //움직일 칸이 방문하지 않은곳이며 벽이 있으면서 아직 벽을 부수지 않았다면
                if(map[nx][ny]==1&&b==0&&visit[nx][ny][1]>visit[x][y][0]+1){
                    visit[nx][ny][1]=visit[x][y][0]+1;
                    que[tail].x=nx;
                    que[tail].y=ny;
                    que[tail].wall=1;
                    tail++;
                }
                //움직일 칸이 방문하지 않은 벽이 없는 곳이라면
                if(map[nx][ny]==0&&visit[nx][ny][b]>visit[x][y][b]+1){
                    visit[nx][ny][b]=visit[x][y][b]+1;
                    que[tail].x=nx;
                    que[tail].y=ny;
                    que[tail].wall=b;
                    tail++;
                }
            }
        }
    }
    if(visit[n-1][m-1][0]==__INT_MAX__&&visit[n-1][m-1][1]==__INT_MAX__)
        printf("-1");
    else{
        if(visit[n-1][m-1][0]<visit[n-1][m-1][1])
            printf("%d",visit[n-1][m-1][0]);
        else
            printf("%d",visit[n-1][m-1][1]);
    }
    return 0;
}