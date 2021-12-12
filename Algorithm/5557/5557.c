#include<stdio.h>
int main()
{
    long long int map[102][21]={0,};
    int list[102]={0,},n;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d",&list[i]);
    map[1][list[1]]++;
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            if(map[i-1][j]){
                if(list[i]+j<=20)
                    map[i][j+list[i]]+=map[i-1][j];
                if(j-list[i]>=0)
                    map[i][j-list[i]]+=map[i-1][j];
            }
        }
    }
    printf("%lld",map[n-1][list[n]]);
    return 0;
}