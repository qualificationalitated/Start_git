#include<stdio.h>
#define X 52
int pnode[X],cnode[X][X],cnodecnt[X]={0,},del[X]={0,};
int find(int x)
{
    del[x]=1;
    for (int i = 0; i < cnodecnt[x]; i++)
        find(cnode[x][i]);
    return 0;
}
int main()
{
    int n,p,x,ans=0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        scanf("%d",&p);
        pnode[i]=p;
        if(p!=-1)
            cnode[p][cnodecnt[p]++]=i;
    }
    scanf("%d",&x);
    cnodecnt[pnode[x]]--;
    find(x);
    for (int i = 0; i < n; i++)
        if((!del[i])&&(!cnodecnt[i]))
            ans++;
    printf("%d",ans);
    return 0;
}