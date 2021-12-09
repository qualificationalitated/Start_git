#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,coins[21],money,map[10002]={0,};
        scanf("%d",&n);
        for (int i = 0; i < n; i++)//정렬된 상태
            scanf("%d",&coins[i]);
        scanf("%d",&money);
        for (int i = 0; i < n; i++)
        {
            if (coins[i]<=money){
                map[coins[i]]++;
                for (int j = coins[i]+1; j <= money; j++)
                {
                    map[j]+=map[j-coins[i]];
                }
            }
        }
        printf("%d\n",map[money]);
    }
    return 0;
}