#include<stdio.h>
#define LIM 102
typedef struct grid{
    int x,y;
}grid;
int map[LIM][LIM],island[LIM][LIM],landCnt=0;
int mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
grid lands[LIM*LIM];
// 섬 찾기 함수
int findIsland(int x,int y,int n,int cnt){
    if(x<0||x>=n||y<0||y>=n||!map[x][y]||island[x][y])
        return 0;
    island[x][y]=cnt;
    lands[landCnt].x=x;
    lands[landCnt].y=y;
    landCnt++;
    for (int i = 0; i < 4; i++)
        findIsland(x+mx[i],y+my[i],n,cnt);
    return 0;
}
int main()
{
    int n;
    // 섬 입력
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d",&map[i][j]);
    // 섬 구분하기
    int cntIsland=1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(map[i][j]&&island[i][j]==0)
                findIsland(i,j,n,cntIsland++);
    int ans=__INT_MAX__;
    for (int i = 0; i < landCnt; i++){
        int head=0,tail=1,startIsland,visit[LIM][LIM]={0,};
        grid now,next,que[LIM*LIM];
        que[0]=lands[i];
        startIsland=island[que[0].x][que[0].y];
        while(head<tail){
            now=que[head++];
            if(map[now.x][now.y]&&island[now.x][now.y]!=startIsland){
                int dist=visit[now.x][now.y];
                ans=ans>dist?dist:ans;
                break;
            }
            for (int j = 0; j < 4; j++){
                next.x=now.x+mx[j];
                next.y=now.y+my[j];
                if(next.x<0||next.y<0||next.x>=n||next.y>=n||visit[next.x][next.y])
                    continue;
                if(map[next.x][next.y]==startIsland)
                    continue;
                visit[next.x][next.y]=visit[now.x][now.y]+1;
                que[tail++]=next;
            }
            
        }
    }
    printf("%d",ans-1);
    return 0;
}