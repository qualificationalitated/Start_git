#include<stdio.h>
int map[202][202],visit[202];
int plans[1002];
int que[100000];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=0;i<m;i++)
        scanf("%d",&plans[i]);
    visit[plans[0]]=1;
    que[0]=plans[0];
    int now,next,head=0,tail=1;
    while(head<tail){
        now=que[head++];
        for(int i=1;i<=n;i++){
            if(map[now][i]&&visit[i]==0){
                visit[i]=visit[now]+1;
                que[tail++]=i;
            }
        }
    }
    for(int i=0;i<m;i++)
        if(!visit[plans[i]]){
            printf("NO");
            return 0;
        }
    printf("YES");
    return 0;
}