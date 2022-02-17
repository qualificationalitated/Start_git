#include<stdio.h>
int num[102],check[102],visit[102],visitlist[102];
int cicle[102]={0,};
int find(int x,int cnt){
    //싸이클 생김
    if(visit[x]){
        int c=1;
        for (int i = 0; i < cnt; i++)
            if(!check[visitlist[i]])
                c=0;
        if(c)
            for (int i = 0; i < cnt; i++)
                cicle[visitlist[i]]=1;
        return 0;
    }
    visit[x]=1;
    check[num[x]]=1;
    visitlist[cnt]=x;
    find(num[x],cnt+1);
    visit[x]=0;
    check[num[x]]=0;
    return 0;
}
int main()
{
    int n,ans=0,ansArr[102]={0,};
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",&num[i]);
    for (int i = 1; i <= n; i++)
        find(i,0);
    for (int i = 1; i <= n; i++)
        if(cicle[i])
            ansArr[ans++]=i;
    printf("%d\n",ans);
    for (int i = 0; i < ans; i++)
        printf("%d\n",ansArr[i]);
    return 0;
}