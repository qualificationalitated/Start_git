#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int move(int block, int stPoint, int midPoint, int endPoint){
	if(block==1)
		cout<<stPoint<<" "<<endPoint<<"\n";
	else{
		move(block-1, stPoint,endPoint,midPoint);
		cout<<stPoint<<" "<<endPoint<<"\n";
		move(block-1, midPoint,stPoint,endPoint);
	}
	return 0;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	string ans=to_string(pow(2,n));

	int loc=ans.find('.');
	ans=ans.substr(0,loc);
	ans[ans.length()-1]-=1;

	cout<<ans<<"\n";
	
	if(n<21)
		move(n,1,2,3);
	return 0;
}