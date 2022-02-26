#include<stdio.h>
#define MAX 52
typedef struct grid{
    int x,y;
}grid;
char map[MAX][MAX];
int dp[MAX][MAX],visit[MAX][MAX],mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
grid que[MAX*MAX*4],now,next;
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%s",map[i]);
        for (int j = 0; j < n; j++)
            dp[i][j]=MAX*MAX;
    }
    que[0].x=0;
    que[0].y=0;
    dp[0][0]=0;
    int head=0,tail=1;
    while(head<tail){
        now=que[head++];
        for (int i = 0; i < 4; i++)
        {
            int blackToWhite=0;
            next.x=now.x+mx[i];
            next.y=now.y+my[i];
            if(next.x<0||next.x>=n||next.y<0||next.y>=n)
                continue;
            if(map[next.x][next.y]=='0')
                blackToWhite=1;
            if(dp[next.x][next.y]>dp[now.x][now.y]+blackToWhite){
                que[tail++]=next;
                dp[next.x][next.y]=dp[now.x][now.y]+blackToWhite;
            }
        }
    }
    printf("%d",dp[n-1][n-1]);
    return 0;
}