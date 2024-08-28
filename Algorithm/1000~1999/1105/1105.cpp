#include<iostream>
#include<string>
using namespace std;
int main(){
	int ans=0;
	string a,b;
	cin>>a>>b;
	if(a.size()!=b.size())
		cout<<"0";
	else{
		for(int i=0;i<a.size();i++){
			if(a[i]!=b[i]) break;
			if(a[i]==b[i] && a[i]=='8')
				ans++;
		}
		cout<<ans;
	}
	return 0;
}