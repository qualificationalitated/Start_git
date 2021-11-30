#include<stdio.h>
int n,m,map[52][52]={0,},dist=0;
int main()
{
    char s[52];
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++){
        scanf("%s",s);
        for (int j = 0; j < m; j++)
            if(s[j]=='L')
                map[i][j]=1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++){
            if(map[i][j])
            {
                int nowx=i,nowy=j,nextx,nexty,mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
                int visit[52][52]={0,},head=0,tail=1,que[2500][2];
                visit[i][j]=1;
                while(head<tail){
                    for (int k = 0; k < 4; k++)
                    {
                        nextx=nowx+mx[k];
                        nexty=nowy+my[k];
                        if(0<=nextx&&nextx<n&&0<=nexty&&nexty<m&&map[nextx][nexty]==1&&visit[nextx][nexty]==0)
                        {
                            visit[nextx][nexty]=visit[nowx][nowy]+1;
                            if(dist<visit[nextx][nexty])
                                dist=visit[nextx][nexty];
                            que[tail][0]=nextx;
                            que[tail][1]=nexty;
                            tail++;
                        }
                    }
                    head++;
                    nowx=que[head][0];
                    nowy=que[head][1];
                }
            }
        }
    }
    printf("%d",dist-1);
    return 0;
}