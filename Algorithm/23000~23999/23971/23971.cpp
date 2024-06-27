#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int h,w,n,m;
	cin>>h>>w>>n>>m;
	h = h%(n+1)? h/(n+1)+1 : h/(n+1);
	w = w%(m+1)? w/(m+1)+1 : w/(m+1);
	cout<<h*w;
	return 0;
}