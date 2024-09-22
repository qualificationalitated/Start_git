// 2차원 DP 정석 풀이
/*

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int list[n+1][2], dp[k+1]; // 0->wei, 1->value
	for(int i=0;i<n;i++)
		cin>>list[i][0]>>list[i][1];
	for(int i=0;i<=k;i++) dp[i] = 0;

	for(int i=0;i<n;i++){
		for(int j=k;j>0;j--){
			if(j>=list[i][0])
				if(dp[j]<dp[j-list[i][0]]+list[i][1])
					dp[j] = dp[j-list[i][0]]+list[i][1];
		}
	}
	cout<<dp[k];
	return 0;
}

*/

// 냅색 변형 1차원 dp 풀이
#include<iostream>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	int w,v,dp[k+1];
	for(int i=0;i<=k;i++) dp[i] = 0;
	for(int i=0;i<n;i++){
		cin>>w>>v;
		for(int j=k;j>=w;j--)
			dp[j] = dp[j-w]+v>dp[j]?dp[j-w]+v:dp[j];
	}
	cout<<dp[k];
	return 0;
}