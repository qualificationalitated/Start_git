#include<stdio.h>
int dp[32][2]={0,},d,k;
int main(){
    scanf("%d%d",&d,&k);
    dp[1][0]=1;
    dp[2][1]=1;
    for (int i = 3; i < 31; i++){
        dp[i][0]=dp[i-1][1];
        dp[i][1]=dp[i-1][0]+dp[i-1][1];
    }
    for (int i = 1; i <= k/dp[d][0]+1; i++){
        int A=dp[d][0],B=dp[d][1];
        if((k-i*A)%B==0){
            printf("%d\n%d",i,(k-i*A)/B);
            return 0;
        }
    }
    return 0;
}