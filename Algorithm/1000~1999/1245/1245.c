#include<stdio.h>
typedef struct{
    int x,y;
}grid;
int map[102][72]={0,};
int visit[102][72]={0,};
grid que[7002]={0,};
int mx[8]={1,1,0,-1,-1,-1,0,1},my[8]={0,1,1,1,0,-1,-1,-1};
int main(){
    int n,m,ans=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&map[i][j]);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]&&visit[i][j]==0){
                grid now,next;
                int head=0,tail=1,top=1,bottom=0,aa,bb,aaa,bbb;
                visit[i][j]=1;
                que[0].x=i;
                que[0].y=j;
                while(head<tail){
                    now=que[head++];
                    for(int k=0;k<8;k++){
                        next.x=now.x+mx[k];
                        next.y=now.y+my[k];
                        if(next.x<0||next.y<0||next.x>=n||next.y>=m)
                            continue;
                        if(map[next.x][next.y]>map[now.x][now.y])
                            top=0;
                        if(map[next.x][next.y]<map[now.x][now.y])
                            bottom=1;
                        if(map[next.x][next.y]==map[now.x][now.y]&&visit[next.x][next.y]==0){
                            visit[next.x][next.y]=1;
                            que[tail++]=next;
                        }
                    }
                }
                if(top&&bottom)
                    ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}