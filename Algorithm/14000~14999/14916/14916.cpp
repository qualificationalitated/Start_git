#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n,ans;
	cin>>n;
	ans = n/5;
	if(ans == 0 && (n%5==1 || n%5==3))	cout<<-1;
	else{
		switch (n%5){
		case 1: ans+=2; break;
		case 2: ans+=1; break;
		case 3: ans+=3; break;
		case 4: ans+=2; break;
		default: break; 
		}
		cout<<ans;
	}
	return 0;
}