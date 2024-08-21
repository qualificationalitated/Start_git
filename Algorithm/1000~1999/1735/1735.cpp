#include<iostream>
#include<numeric>
using namespace std;
int main(){
	int bza,bzb,bma,bmb,gcd_num;
	cin>>bza>>bma>>bzb>>bmb;
	bza *= bmb; bzb *= bma; bza+=bzb;
	bma *= bmb; bmb = bma;
	gcd_num = gcd(bza,bma);
	cout<<bza/gcd_num<<" "<<bma/gcd_num;
	return 0;
}