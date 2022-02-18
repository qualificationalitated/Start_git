#include<stdio.h>
int dp[100002]={0,},n,k,x,y;
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d %d",&x,&y);
        for(int j=k;j>=x;j--)
            dp[j]=dp[j]>dp[j-x]+y?dp[j]:dp[j-x]+y;
    }
    printf("%d",dp[k]);
    return 0;
}