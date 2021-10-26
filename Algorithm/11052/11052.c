#include<stdio.h>
int costs[1002];
int main()
{
    int n,p[1002];
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    costs[1]=p[1];
    for (int i = 2; i <= n; i++)
    {
        costs[i]=p[i];
        for (int j = i; j >= 1; j--)
        {
            int sum=p[j]+costs[i-j];
            if(costs[i]<sum)
                costs[i]=sum;
        }
    }
    printf("%d",costs[n]);
    return 0;
}