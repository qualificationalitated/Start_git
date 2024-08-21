#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	int n,m;
	string dp[101][101];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j==0 || i==j) dp[i][j] ="1";
			else{
				int sum=0;
				string n1 = dp[i-1][j];
				string n2 = dp[i-1][j-1];
				while(n1.size() || n2.size() || sum){
					if(n1.size()){
						sum+=n1.back()-'0';
						n1.pop_back();
					}
					if(n2.size()){
						sum+=n2.back()-'0';
						n2.pop_back();
					}
					dp[i][j].push_back((sum%10)+'0');
					sum/=10;
				}
				reverse(dp[i][j].begin(), dp[i][j].end());
			}
		}
	}
	cout<<dp[n][m];

	return 0;
}