#include<stdio.h>
int main()
{
    int n,m;
    int countList[40][2]={{1,0},{0,1}};
    for (int i=2;i<=40;i++)
    {
        countList[i][0]=countList[i-1][0]+countList[i-2][0];
        countList[i][1]=countList[i-1][1]+countList[i-2][1];
    }
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        printf("%d %d\n",countList[m][0],countList[m][1]);
    }
    return 0;
}