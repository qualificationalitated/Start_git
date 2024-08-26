#include<iostream>
using namespace std;
int main(){
	int n,s=0,i=1;
	cin>>n;
	while(s<n) s+=i++; i-=2;
	n-=(i*(i+1))/2;
	if(i%2)	cout<<n<<"/"<<i+2-n;
	else	cout<<i+2-n<<"/"<<n;
	return 0;
}