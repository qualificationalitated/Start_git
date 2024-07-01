#include<iostream>
#include<vector>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m,x,max,prevX;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>x;
		if(!i){ max = x; prevX = x;}
		else{
			int between = (x-prevX)%2 ? (x-prevX)/2 + 1 : (x-prevX)/2;
			max = max>between?max:between;
			prevX = x;
		}
	}
	max = max > n-x ? max : n-x;
	cout<<max;
	return 0;
}