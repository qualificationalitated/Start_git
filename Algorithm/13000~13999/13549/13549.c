#include<stdio.h>
int que[400003],map[200003],head=0,tail=0,n,k;
int main(){
	for (int i = 0; i < 200003; i++)
		map[i]=__INT_MAX__;
    scanf("%d %d",&n,&k);
    que[tail++]=n;
	map[n]=0;
    while(head<=tail){
        int now=que[head++];
        if(now==k){
            printf("%d",map[k]);
            return 0;
        }
        if(now<k){
            if(map[now+1]>map[now]+1){
            	que[tail++]=now+1;
            	map[now+1]=map[now]+1;
            }
            if(map[now*2]>map[now]){
            	que[tail++]=now*2;
            	map[now*2]=map[now];
            }
        }
        if(now>0&&map[now-1]>map[now]+1){
            que[tail++]=now-1;
            map[now-1]=map[now]+1;
        }
    }
    return 0;
}