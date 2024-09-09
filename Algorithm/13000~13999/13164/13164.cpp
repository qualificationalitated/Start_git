#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n,k,ans=0;
	cin>>n>>k;
	vector<int> heis(n), cost(n-1);
	for(int i=0;i<n;i++) 
		cin>>heis[i];
	sort(heis.begin(), heis.end());
	for(int i=0;i<n-1;i++)
		cost[i] = heis[i+1]-heis[i];
	sort(cost.begin(), cost.end());
	for(int i=0;i<n-k;i++)
		ans+=cost[i];
	cout<<ans;
	return 0;
}