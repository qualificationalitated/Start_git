#include<stdio.h>
int max(int x,int y){
    return x>y? x:y;
}
int main()
{
    int n,p,dp[1002]={0,};
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        scanf("%d",&p);
        for (int j = i; j <= n; j++)
            dp[j]=max(dp[j],p+dp[j-i]);
    }
    printf("%d",dp[n]);
    return 0;
}