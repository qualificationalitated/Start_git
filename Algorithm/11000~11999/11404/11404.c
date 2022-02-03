#include<stdio.h>
#define MIN(x,y) ((x)>(y)?(y):(x))
#define INF 100000002
int map[102][102]={0,},n,m;
int main()
{
    int a,b,c;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < 102; i++)
        for (int j = 0; j < 102; j++){
            map[i][j]=INF;
            if(i==j)
                map[i][j]=0;
        }
    for (int i = 0; i < m; i++){
        scanf("%d%d%d",&a,&b,&c);
        map[a][b]=MIN(map[a][b],c);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                map[i][j]=MIN(map[i][j],map[i][k]+map[k][j]);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if(map[i][j]==INF)
                map[i][j]=0;
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
    return 0;
}