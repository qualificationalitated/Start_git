#include<stdio.h>
int map[52][52],n,m,cnt,my[4]={0,1,0,-1},mx[4]={-1,0,1,0};
typedef struct status{
    int x,y,dir;
}status;
status now,next;
int main()
{
    scanf("%d%d%d%d%d",&n,&m,&next.x,&next.y,&next.dir);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            scanf("%d",&map[i][j]);
    while(1){ //움직일수 없을 때 까지 무한으로 탐색
        int check=0;
        now=next;
        map[now.x][now.y]=2; //현 위치를 청소 함
        for (int i=0;i<4;i++){ //주위 4 방향 둘러보기
            if (--next.dir<0) next.dir=3;
            next.x=now.x+mx[next.dir];
            next.y=now.y+my[next.dir];
            if(0<=next.x&&next.x<n&&0<=next.y&&next.y<m&&map[next.x][next.y]==0){
                // 왼쪽으로 돌면서 움직일 수 있는 지점을 찾으면 체크하고 멈추기
                cnt++;
                check=1;
                break;
            }
        }
        if(!check){ // 4방향중 어디로도 움직일 수 없다면
            next.x=now.x-mx[now.dir];
            next.y=now.y-my[now.dir];
            if(map[next.x][next.y]==1){ //심지어 뒤에 벽이라면, 멈춘다.
                printf("%d",cnt+1);
                return 0;
            }
        }
        // 안 멈췄으면 next를 탐색한다.
    }
    return 0;
}