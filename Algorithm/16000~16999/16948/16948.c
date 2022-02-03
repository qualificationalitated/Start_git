#include<stdio.h>
typedef struct grid{
    int x,y;
}grid;
grid que[40002],now,next;
int map[202][202]={0,},mx[6]={-2,-2,0,0,2,2},my[6]={-1,1,-2,2,-1,1};
int n,dx,dy,h=0,t=1;
int main()
{
    scanf("%d%d%d%d%d",&n,&que[0].x,&que[0].y,&dx,&dy);
    while(h<t){
        now=que[h++];
        if(now.x==dx&&now.y==dy){
            printf("%d\n",map[now.x][now.y]);
            return 0;
        }
        for (int i = 0; i < 6; i++){
            next.x=now.x+mx[i];
            next.y=now.y+my[i];
            if(0<=next.x&&next.x<n&&0<=next.y&&next.y<n&&map[next.x][next.y]==0){
                que[t++]=next;
                map[next.x][next.y]=map[now.x][now.y]+1;
            }
        }
    }
    printf("-1");
    return 0;
}