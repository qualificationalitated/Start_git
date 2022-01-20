#include<stdio.h>
#define ARR 10003
int num[ARR]={0,1,},que[ARR],used[ARR]={0,};
int head,tail,now,t;
int next(int x){
    if((!num[x])&&(!used[x])){
        used[x]=used[now]+1;
        que[tail++]=x;
    }
    return 0;
}
int main(){
    for (int i = 2; i <= 100; i++)
        for (int j = 2; j <= 10000/i; j++)
            num[i*j]=1;
    scanf("%d",&t);
    while(t--){
        int f=0,a,b;
        head=0;
        tail=0;
        for (int i = 0; i < ARR; i++){
            que[i]=0;
            used[i]=0;
        }
        scanf("%d%d",&a,&b);
        que[tail++]=a;
        used[a]=1;
        while(head<tail){
            now=que[head++];
            if(now==b){
                f=printf("%d\n",used[now]-1);
                break;
            }
            int th=now%1000,hn=(now/1000)*1000+now%100,tn=(now/100)*100+now%10,on=(now/10)*10;
            next(hn);
            next(tn);
            next(on);
            for (int i = 1; i <= 9; i++){
                next(th+i*1000);
                next(hn+i*100);
                next(tn+i*10);
                next(on+i);
            }
        }
        if(!f) printf("Impossible\n");
    }
    return 0;
}