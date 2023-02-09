#include<iostream>
#include<algorithm>
using namespace std;
int dp[1002][31]={0,};
int main(){
    int t,w,fall,ans=-1;
    cin>>t>>w;
    for(int i=1;i<=t;i++){
        cin>>fall;
        dp[i][0] = dp[i-1][0] + (fall == 1);
        for(int j=1;j<=w;j++)
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + (fall==1+(j%2));
    }
    for(int j=0;j<=w;j++)
        ans=max(ans,dp[t][j]);
    cout<<ans;
    return 0;
}