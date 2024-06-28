#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int p,t;
	cin>>p;
	while(p--){
		int arr[21]={0,},ans=0;
		cin>>t;
		for (int i = 0; i < 20; i++) cin>>arr[i];
		for (int i = 0; i < 20; i++)
			for (int j = i; j < 20; j++)
				if(arr[i]>arr[j]) ans++;
		cout<<t<<" "<<ans<<"\n";
	}
	return 0;
}