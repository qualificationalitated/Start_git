#include <stdio.h>
#include <stdlib.h>
typedef struct grid
{
    int x, y;
} grid;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, map[103][103] = {0,};
        grid loc[103];
        scanf("%d", &n);
        for (int i = 0; i < n + 2; i++)
            scanf("%d %d", &loc[i].x, &loc[i].y);
        for (int i = 0; i < n + 2; i++)
        {
            for (int j = 0; j < n + 2; j++)
            {
                if(i==j)
                    map[i][j]=1;
                else
                {
                    int dist = abs(loc[j].x - loc[i].x) + abs(loc[j].y - loc[i].y);
                    if(dist>1000)
                        map[i][j]=0;
                    else
                        map[i][j] = 1;
                }
            }
        }
        for (int k = 0; k < n + 2; k++)
            for (int i = 0; i < n + 2; i++)
                for (int j = 0; j < n + 2; j++){
                    if (i == j || i == k || k == j)
                        continue;
                    else if(map[i][j]==1 || (map[i][k] == 1 && map[k][j] == 1))
                        map[i][j] = 1;
                }
        if (map[0][n+1])
            printf("happy\n");
        else
            printf("sad\n");
    }
    return 0;
}