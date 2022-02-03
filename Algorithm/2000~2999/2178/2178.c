#include<stdio.h>
int n,m,head=0,tail=1,move[2][4]={{0,0,1,-1},{1,-1,0,0}};
char map[103][103];
int nowx=0,nowy=0,nextx,nexty,numberMap[103][103],que[250000][2];
int bfs()
{
    while(head<=tail)
    {
        for (int i = 0; i < 4; i++)
        {
            nextx=nowx+move[0][i];
            nexty=nowy+move[1][i];
            if(map[nextx][nexty]=='1'&&nextx>=0&&nextx<n&&nexty>=0&&nexty<m)
                if(numberMap[nextx][nexty]==0||numberMap[nextx][nexty]>numberMap[nowx][nowy]+1)
                {
                    numberMap[nextx][nexty]=numberMap[nowx][nowy]+1;
                    que[tail][0]=nextx;
                    que[tail][1]=nexty;
                    tail++;
                }
        }
        head++;
        nowx=que[head][0];
        nowy=que[head][1];
    }
    return 0;
}
int main()
{
    numberMap[0][0]=1;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++)
        scanf("%s",map[i]);
    bfs();
    printf("%d",numberMap[n-1][m-1]);
    return 0;
}