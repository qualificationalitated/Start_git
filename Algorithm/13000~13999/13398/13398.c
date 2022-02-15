#include<stdio.h>
#define  LIM 100002
int dp[LIM][2]={0,}; //dp[-][0] - 거르기찬스 on(나부터 새로시작 or 계-속 거르기찬스 안쓰고 이어가기), dp[-][1] - 거르기찬스 off( 나를 걸렀거나, 이전에 거르기 찬스 off한것을 이어가거나 )
int main()
{
    int n,x,ans;
    scanf("%d",&n);
    scanf("%d",&dp[0][0]);
    ans=dp[0][0];
    for (int i = 1; i < n; i++)
    {
        int x,bigger;
        scanf("%d",&x);
        dp[i][0]=dp[i-1][0]+x>x?dp[i-1][0]+x:x;
        dp[i][1]=dp[i-1][0]>dp[i-1][1]+x?dp[i-1][0]:dp[i-1][1]+x;
        bigger=dp[i][0]>dp[i][1]?dp[i][0]:dp[i][1];
        ans=bigger>ans?bigger:ans;
    }
    printf("%d",ans);
    return 0;
}