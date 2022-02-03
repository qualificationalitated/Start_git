//요세푸스 문제
#include<stdio.h>
int main()
{
    int n,m,now=0,i;
    int que[1002]={0,};
    scanf("%d %d",&n,&m);
    for (i=1;i<=n;i++)
        que[i]=i;
    printf("<");
    while(n)
    {
        for(i=0;i<m;i++){//increase now to m, check that the range is not exceeded and now does not become zero
            now++;
            if(now>n)
                now=now%(n);
            if(!now)//when n became 1, now may becaem zero, so if now became zero, just plus one
                now++;
        }
        printf("%d",que[now]);
        if(n-1)
            printf(", ");
        for(i = now; i <n; i++)//make que shorter
            que[i]=que[i+1];
        n--;
        now--;
    }
    printf(">");
    return 0;
}