#include<stdio.h>
int que[90002][2],map[302][302];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int size,sx,sy,ex,ey,head=0,tail=1;
        scanf("%d %d %d %d %d",&size,&sx,&sy,&ex,&ey);
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                map[i][j]=0;
        que[tail][0]=sx;
        que[tail][1]=sy;
        map[sx][sy]=1;
        int nowx,nowy,nextx,nexty,mx[8]={1,2,2,1,-1,-2,-2,-1},my[8]={2,1,-1,-2,-2,-1,1,2};
        while(head<=tail)
        {
            head++;
            nowx=que[head][0];
            nowy=que[head][1];   
            if(nowx==ex&&nowy==ey)
            {
                printf("%d\n",map[nowx][nowy]-1);
                break;
            }
            for (int i = 0; i < 8; i++)
            {
                nextx=nowx+mx[i];
                nexty=nowy+my[i];
                if(nextx>=0&&nexty>=0&&nextx<size&&nexty<size&&map[nextx][nexty]==0)
                {
                    tail++;
                    map[nextx][nexty]=map[nowx][nowy]+1;
                    que[tail][0]=nextx;
                    que[tail][1]=nexty;
                }
            }
        }
    }
    return 0;
}