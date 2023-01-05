#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,taesu,p,ans=-1;
    int rank[2][52]={0,};//[0][x]-score [1][x]-rank
    rank[1][0]=1;
    scanf("%d %d %d",&n,&taesu,&p);
    for(int i=1;i<=n;i++){
        scanf("%d",&rank[0][i]);
        if(rank[0][i-1]==rank[0][i])
            rank[1][i]=rank[1][i-1];
        else
            rank[1][i]=i;
    }
    for(int i=1;i<=n;i++)
        if(taesu>rank[0][i]&&ans==-1){
            if(taesu==rank[0][i-1])
                ans=rank[1][i-1];
            else
                ans=rank[1][i];
        }
    if(ans==-1&&n<p){
        if(taesu==rank[0][n])
            ans=rank[1][n];
        else
            ans=n+1;
    }
    // for(int i=1;i<=n;i++)
    //     printf("%d %d\n",rank[0][i],rank[1][i]);
    printf("%d",ans);
    return 0;
}