#include<stdio.h>
#define LIM 100000
int que[LIM+2],cases[LIM+2]={0,},visit[LIM+2];
int head=0,tail=1;
int possible(int x,int y){
    if(visit[x]>=visit[y]+1){
        if(!cases[x])
            que[tail++]=x;
        visit[x]=visit[y]+1;
        cases[x]+=cases[y];
    }
    return 0;
}
int main()
{
    int now,end;
    for (int i = 0; i < LIM*2+1; i++)
        visit[i]=LIM*2+1;
    scanf("%d %d",&que[0],&end);
    cases[que[0]]=1;
    visit[que[0]]=1;
    while(head<tail){
        now=que[head++];
        if(now>0)
            possible(now-1,now);
        if(now<LIM)
            possible(now+1,now);
        if(now*2<=LIM)
            possible(now*2,now);
    }
    printf("%d %d",visit[end]-1,cases[end]);
    return 0;
}