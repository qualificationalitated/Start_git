#include<stdio.h>
#define LIM 32
typedef struct grid
{
    int x,y,z;
}grid;
int main()
{
    while(1){
        char input[LIM];
        int map[LIM][LIM][LIM]={0,},visit[LIM][LIM][LIM]={0,},l,r,c,ans=0;
        int mx[6]={1,0,-1,0,0,0},my[6]={0,1,0,-1,0,0},mz[6]={0,0,0,0,1,-1};
        int head=0,tail=1;
        grid que[LIM*LIM*LIM],now,next;
        scanf("%d%d%d",&l,&r,&c);
        if((!l)&&(!r)&&(!c))
            return 0;
        for (int h = 0; h < l; h++)
        {
            for (int i = 0; i < r; i++)
            {
                scanf("%s",input);
                for (int j = 0; j < c; j++)
                {
                    map[h][i][j]=0;
                    visit[h][i][j]=0;
                    if(input[j]=='#')
                        map[h][i][j]=1;
                    else if(input[j]=='S'){
                        que[0].x=i;
                        que[0].y=j;
                        que[0].z=h;
                        visit[h][i][j]=1;
                    }
                    else if(input[j]=='E')
                        map[h][i][j]=-1;
                }
            }
        }
        while(head<tail){
            now=que[head++];
            if(map[now.z][now.x][now.y]==-1){
                ans=visit[now.z][now.x][now.y];
                break;
            }
            for (int i = 0; i < 6; i++)
            {
                next.z=now.z+mz[i];
                next.x=now.x+mx[i];
                next.y=now.y+my[i];
                if(next.z<0||next.x<0||next.y<0||next.z>=l||next.x>=r||next.y>=c)
                    continue;
                if(map[next.z][next.x][next.y]==1||visit[next.z][next.x][next.y])
                    continue;
                que[tail++]=next;
                visit[next.z][next.x][next.y]=visit[now.z][now.x][now.y]+1;
            }
        }
        ans?printf("Escaped in %d minute(s).\n",ans-1):printf("Trapped!\n");
    }
    return 0;
}