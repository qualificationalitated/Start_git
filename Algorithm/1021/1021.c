#include<stdio.h>
int que[52]={0,},head=1,tail,cnt=0;
int moveLeft(int n)
{
    cnt+=n;
    for (int j = 0; j < n; j++)
    {
        int temp=que[head];
        for (int i = head; i < tail; i++)
            que[i]=que[i+1];
        que[tail]=temp;
    }
    return 0;
}
int moveRight(int n)
{
    cnt+=n;
    for (int j = 0; j < n; j++)
    {
        int temp=que[tail];
        for (int i = tail; i > head ; i--)
            que[i]=que[i-1];
        que[head]=temp;
    }
    return 0;
}
int main()
{
    int n,m,popit;
    scanf("%d %d",&n,&m);
    tail=n;
    for (int i=1;i<=n;i++)
        que[i]=i;
    while(m--)
    {
        scanf("%d",&popit);
        if(popit==que[head])
            head++;
        else
        {
            for (int i = head; i <= tail; i++)
            {
                if(que[i]==popit)
                {
                    if(i-head<tail+1-i)
                        moveLeft(i-head);
                    else
                        moveRight(tail+1-i);
                    break;
                }
            }
            head++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}