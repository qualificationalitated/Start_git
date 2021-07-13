#include<stdio.h>
int list[8]={0,};
int make(int n,int m,int now,int length)
{
    if(length==m)
    {
        for (int i=0;i<m;i++)
            printf("%d ",list[i]);
        printf("\n");
        return 0;
    }
    else
        for (int i=now;i<=n;i++)
        {
            list[length++]=i;
            make(n,m,i,length);
            length--;
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