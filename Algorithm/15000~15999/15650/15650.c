#include<stdio.h>
int visited[9]={0,},list[9]={0,};
int make(int n,int m,int now,int length)
{
    if(length==m)
    {
        for (int i=0;i<m;i++)
            printf("%d ",list[i]);
        printf("\n");
        return 0;
    }
    for (int i=now;i<=n;i++)
        if(visited[i]==0)
        {
            visited[i]=1;
            list[length++]=i;
            make(n,m,i+1,length);
            length--;
            visited[i]=0;
        }
    return 0;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    make(n,m,1,0);
    return 0;
}