#include<stdio.h>
int main()
{
    int t;
    int k,n;
    int apartment[15][15]={0,};
    for(int i=0;i<15;i++)
    {
        apartment[0][i]=i;
        apartment[i][1]=1;  
    }
    for(int i=1;i<15;i++)
    {
        for(int j=2;j<15;j++)
        {
            apartment[i][j]=apartment[i-1][j]+apartment[i][j-1];
        }
    }
    scanf("%d",&t);
    for (int i=0;i<t;i++)
    {
        scanf("%d %d",&k,&n);
        {
            printf("%d",apartment[k][n]);
        }
    }
    return 0;
}