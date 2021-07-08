#include<stdio.h>
int main()
{
    int n,m,max=0;
    int list[10001]={0,};
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&m);
        if(max<m)
            max=m;
        list[m]++;
    }
    for (int i=0;i<=max;i++)
    {
        if(list[i])
        {
            for (int j=0;j<list[i];j++)
            {
                printf("%d\n",i);
            }
        }
    }
    return 0;
}