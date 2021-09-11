#include<stdio.h>
#include<stdlib.h>
int box[1002][1002],bfs[1000004][2];
int input[3]={0,};//0-> -1 갯수, 1-> 0갯수 1-> 2갯수
int head=0,tail=1,nowx,nowy,nextx,nexty,mx[4]={1,-1,0,0},my[4]={0,0,1,-1};
int main()
{
    int n,m,cnt=0,max=0;
    scanf("%d %d",&m,&n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            scanf("%d",&box[i][j]);
            input[box[i][j]+1]++;
            if(box[i][j]==1){
                bfs[tail][0]=i;
                bfs[tail][1]=j;
                tail++;
            }
        }
    if(input[0]+input[2]==n*m){
        printf("0");
        return 0;
    }
    if(input[0]+input[1]==n*m){
        printf("-1");
        return 0;
    }
    while(head<tail)
    {
        head++;
        nowx=bfs[head][0];
        nowy=bfs[head][1];
        for (int i = 0; i < 4; i++)
        {
            nextx=nowx+mx[i];
            nexty=nowy+my[i];
            if(box[nextx][nexty]==0&nextx>=0&&nextx<n&&nexty>=0&&nexty<m)
            {
                box[nextx][nexty]=box[nowx][nowy]+1;
                input[1]--;
                if(max<box[nowx][nowy]+1)
                    max=box[nowx][nowy]+1;
                bfs[tail][0]=nextx;
                bfs[tail][1]=nexty;
                tail++;
            }
        }
    }
    if(!input[1])
        printf("%d",max-1);
    else
        printf("-1");
    
    return 0;
}