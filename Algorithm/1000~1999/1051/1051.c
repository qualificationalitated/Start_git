#include<stdio.h>
int main()
{
    int n,m,r;
    char map[53][53];
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++)
        scanf("%s",map[i]);
    if(n<m) r=n;
    else r=m;
    while(r)
    {
        for (int i = 0; i <= n-r; i++)
        {
            for (int j = 0; j <= m-r; j++)
            {
                if(map[i][j]==map[i][j+r-1]&&map[i][j]==map[i+r-1][j]&&map[i][j]==map[i+r-1][j+r-1]){
                    printf("%d",r*r);
                    return 0;
                }
            }
        }
        r--;
    }
    return 0;
}