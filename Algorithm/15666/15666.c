#include<stdio.h>
int num,exist[10002],ans[10],list[10],cnt=0,n,m;
int find(int x,int len)
{
    if(x==m){
        for (int i = 0; i < m; i++)
            printf("%d ",ans[i]);
        printf("\n");
    }
    else
        for (int i = len; i < cnt; i++)
        {
            ans[x]=list[i];
            find(x+1,i);
        }
    return 0;
}
int main()
{
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++){
        scanf("%d",&num);
        exist[num]=1;
    }
    for (int i = 0; i < 10002; i++)
        if(exist[i])
            list[cnt++]=i;
    find(0,0);
    return 0;
}