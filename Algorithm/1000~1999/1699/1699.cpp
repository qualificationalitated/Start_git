#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int dp[100002]={0,};
int main(){
    int n;
    cin>>n;
    dp[0]=0; dp[1]=1;
    for(int i=0;i<=n;i++)  dp[i]=i; // 전부 초기화 해주고
    for(int i=1;i<=n;i++){ // 1부터 n까지 돌면서 dp 테이블을 채울겁니다
        // 1부터 sqrt(i)까지 돌면서, 갱신하고자 하는 값을 갱신해줍니다
        // x 값을 만들고자 할 때, 기존의 값과, dp[x-(sqrt(x)보다 작은 정수의 제곱값)] + 1을 비교
        // 이때 왜 1을 더하냐? - sqrt(x)보다 작은 정수의 제곱값을 사용해서 1 더해주는거
        for(int j=1;j*j<=i;j++){
            dp[i] = min(dp[i] , dp[i-j*j] + 1);
        }
    }
    cout<<dp[n];
    return 0;
}