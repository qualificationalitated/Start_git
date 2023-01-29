#include<iostream>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unsigned long long int a,b,temp;
	cin>>a>>b;
	while(b){
		temp=a%b; a=b; b=temp;}
	while(a--) cout<<"1";
	return 0;
}