#include<iostream>
#include<numeric>
using namespace std;
int main(){
	long long a,b,ans=1;
	cin>>a>>b;
	cout<<a*b/gcd(a,b);
	return 0;
}