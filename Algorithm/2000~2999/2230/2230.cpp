#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 2000000001
using namespace std;
int main(){
	int n,m; // 갯수, 차이
	int ans = MAX,temp;
	cin>>n>>m;
	vector<int> input(n);
	for(int i=0;i<n;i++)
		cin>>input[i];
	sort(input.begin(),input.end());
	int head = 0, tail = 0; // 앗! 같은 수 일수도 있다!!
	while(head<n && tail<n) {
		int diff = abs(input[tail]-input[head]);
		if(diff<m) tail++;
		else{
			if(ans>diff) ans = diff;
			head++;
		}
	}
	cout<<ans;
	return 0;
}