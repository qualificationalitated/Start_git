#include<iostream>
#define MAX 1000002 // 최대, 1000*1000+2
using namespace std;
int dp[1002][3]={0,}, rgb[1002][3];
int main(){
    int n,ans=MAX;
    cin>>n;
    for(int i=0;i<n;i++) // 입력
        for(int j=0;j<3;j++)
            cin>>rgb[i][j];

    for(int st_point=0 ; st_point<3 ; st_point++){ // 시작집을 각각 0, 1, 2 선택
        // 시작집에 따라 dp 시작점 설정
        for(int i=0;i<3;i++){
			if(i==st_point)    dp[0][i]=rgb[0][i];   // 시작점 잡고
			else               dp[0][i]=MAX;         // 선택 안한집은 MAX
		}
        for(int i=1;i<n;i++){
            dp[i][0]=rgb[i][0]+min(dp[i-1][1],dp[i-1][2]);
            dp[i][1]=rgb[i][1]+min(dp[i-1][0],dp[i-1][2]);
            dp[i][2]=rgb[i][2]+min(dp[i-1][0],dp[i-1][1]);
        }
        for (int i=0;i<3;i++){
            if(i==st_point) continue;
            ans = min(ans,dp[n-1][i]);
		}
    }
    cout<<ans;
    return 0;
}