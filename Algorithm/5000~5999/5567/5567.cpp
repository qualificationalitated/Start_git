#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX 502
int n,m,x,y,cnt=0;
int invited[MAX]={0,};
int map[MAX][MAX]={0,};
int main(){
    int que[MAX],head=0,tail=1;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        map[x][y]=1;
        map[y][x]=1;
    }
    que[head]=1;
    invited[1]=1;
    while(head<tail){
        cnt++;
        int now=que[head++];
        if(invited[now]<3)
            for(int i=1;i<=n;i++){
                if(map[now][i] && invited[i]==0){
                    que[tail++]=i;
                    invited[i]=invited[now]+1;
                }
            }
    }
    printf("%d",cnt-1);
    return 0;
}