#include<stdio.h>
int main()
{
    int n,k,head=0,tail=1;
    int que[200003],map[200003]={0,};
    scanf("%d %d",&n,&k);
    que[tail]=n;
    while(head<=tail)
    {
        int now;
        head++;
        now=que[head];
        if(now==k){
            printf("%d",map[k]);
            return 0;
        }
        if(now<k){
            if(!map[now+1]){
                tail++;
                que[tail]=now+1;
                map[now+1]=map[now]+1;
            }
            if(!map[now*2]){
                tail++;
                que[tail]=now*2;
                map[now*2]=map[now]+1;
            }
        }
        if(now>0&&!map[now-1]){
            tail++;
            que[tail]=now-1;
            map[now-1]=map[now]+1;
        }
    }
    return 0;
}