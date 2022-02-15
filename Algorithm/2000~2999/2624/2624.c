#include<stdio.h>
int dp[10002]={0,};
int main()
{
    int t,k,p,n;
    scanf("%d %d",&t,&k);
    for (int i = 0; i < k; i++){
        int arr[10002]={0,};
        scanf("%d %d",&p,&n);
        for (int j = 1; j <= n; j++)
        {
            int money=p*j;
            if(money<=t){
                arr[money]+=1;
                for (int l = money; l <= t; l++)
                    arr[l]+=dp[l-money];
            }
        }
        for (int j = 1; j <= t; j++)
            dp[j]+=arr[j];
    }
    printf("%d",dp[t]);
    return 0;
}