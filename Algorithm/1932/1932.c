#include<stdio.h>
int map[501][501];
int main()
{
    int n,max=0;
    scanf("%d",&n);
    scanf("%d",&map[0][0]);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            scanf("%d",&map[i][j]);
            if(!j)
                map[i][j]+=map[i-1][j];
            else if(j<i)
                if(map[i-1][j-1]<map[i-1][j])
                    map[i][j]+=map[i-1][j];
                else
                    map[i][j]+=map[i-1][j-1];
            else
                map[i][j]+=map[i-1][j-1];
        }
    }
    for (int i = 0; i < n; i++)
        if(max<map[n-1][i])
            max=map[n-1][i];
    printf("%d",max);
    return 0;
}