#include<stdio.h>
int visited[9]={0,};
int n,m;
int list[9]={0,};
int make(int length)
{
    if(length==m)
    {
        for (int i=0;i<m;i++)
        {
            printf("%d ",list[i]);
        }
        printf("\n");
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            visited[i]=1;
            list[length]=i;
            length++;
            make(length);
            length--;
            visited[i]=0;
        }
    }
    return 0;
}
int main()
{
    scanf("%d %d",&n,&m);
    make(0);
    return 0;
}