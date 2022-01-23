#include<stdio.h>
#define LIM 100000
int visit[LIM+2][2]={0,};//[][0] - time to arrive / [][1] - where are you from
int que[LIM+2],now,head=0,tail=0;
int checkNmakenextstep(int moveto,int now){
    if(visit[moveto][0])
        return 0;
    visit[moveto][0]=visit[now][0]+1;
    visit[moveto][1]=now;
    que[tail++]=moveto;
    return 0;
}
int findroot(int x){
    if(visit[x][1]==-1) return x;
    printf("%d ",findroot(visit[x][1]));
    return x;
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    visit[n][0]=1;
    visit[n][1]=-1;
    que[tail++]=n;
    while(head<tail){
        now=que[head++];
        if(now==k)
            break;
        if(now>0)
            checkNmakenextstep(now-1,now);
        if(now<LIM)
            checkNmakenextstep(now+1,now);
        if(now<LIM/2+1)
            checkNmakenextstep(now*2,now);
    }
    printf("%d\n",visit[k][0]-1);
    printf("%d ",findroot(k));
    return 0;
}