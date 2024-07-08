#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
	int t, n, m;
	cin>>t;
	while(t--){
		ll ans = 0;
		vector<int> ppd;
		cin>>n;
		ppd.resize(n);
		for(int i=0;i<n;i++) cin>>ppd[i];
		int maxLoc = n-1;
		for(int i=n-2;i>=0;i--){
			if(ppd[i] < ppd[maxLoc]) ans+=ppd[maxLoc] - ppd[i];
			else maxLoc = i;
		}
		cout<<ans<<"\n";
	}	
	return 0;
}