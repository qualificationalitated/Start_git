#include<stdio.h>
int map[1025][1025],sum[1025];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d",&sum[j]);
            sum[j]+=sum[j-1];
            map[i][j]=sum[j]+map[i-1][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        int ax,ay,bx,by;
        scanf("%d%d%d%d",&ax,&ay,&bx,&by);
        printf("%d\n",map[bx][by]+map[ax-1][ay-1]-map[bx][ay-1]-map[ax-1][by]);
    }
    return 0;
}