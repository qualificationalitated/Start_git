#include<stdio.h>
#include<string.h>
#define MAX 10002
int pNode[MAX],visit[MAX];
int findRoot(int x){
    if(visit[x]||pNode[x]==0)
        return x;
    visit[x]=1;
    return findRoot(pNode[x]);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,p,c,x,y;
        scanf("%d",&n);
        memset(pNode,0,sizeof(int)*MAX);
        memset(visit,0,sizeof(int)*MAX);
        for(int i=1;i<n;i++){
            scanf("%d %d",&p,&c);
            pNode[c]=p;
        }
        scanf("%d %d",&x,&y);
        findRoot(x);
        printf("%d\n",findRoot(y));
    }
    return 0;
}