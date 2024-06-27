#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, ans=1, six=6;
	cin>>n;
	while(n>1){
		ans++;n-=six;six+=6;
	}
	cout<<ans;
}