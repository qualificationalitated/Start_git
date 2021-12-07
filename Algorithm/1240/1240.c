#include<stdio.h>
int map[1001][1001];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n-1; i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        map[a][b]=c;
        map[b][a]=c;
    }
    for (int i = 0; i < m; i++)
    {
        int a,b,que[100000],visit[1002],head=0,tail=1;
        for (int i = 0; i < 1002; i++)
            visit[i]=__INT_MAX__;
        scanf("%d %d",&a,&b);
        visit[a]=0;
        while(head<tail){
            for(int i = 1; i <= n; i++)
            {
                if(map[a][i]&&visit[i]>visit[a]+map[a][i]){
                    que[tail++]=i;
                    visit[i]=visit[a]+map[a][i];
                }
            }
            a=que[++head];
        }
        printf("%d\n",visit[b]);
    }
    return 0;
}