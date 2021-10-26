#include<stdio.h>
int map[1002][1002],visit[1002],que[1002];
int main()
{
    int a,b,n,m,c,d,head=0,tail=1;
    scanf("%d %d %d %d",&a,&b,&n,&m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d",&c,&d);
        map[c][d]=1;
        map[d][c]=1;
    }
    visit[a]=1;
    while(head<tail)
    {
        if(a==b)
        {
            printf("%d",visit[b]-1);
            return 0;
        }
        for (int i = 0; i <= n; i++)
        {
            if(visit[i]==0&&map[a][i]==1)
            {
                que[tail++]=i;
                visit[i]=visit[a]+1;
            }
        }
        a=que[++head];
    }
    printf("%d",visit[b]-1);
    return 0;
}