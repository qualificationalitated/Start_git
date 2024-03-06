#include<iostream>
#include<algorithm>
#define MAX 100001
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int n,arr[MAX]={0,},tg;
	cin>>n;
	int front=0, back=n-1, ans=0;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	cin>>tg;
	while(front<back){
		int t_sum = arr[front]+arr[back];
		if(t_sum == tg){ ans++; front++; back--;}
		else if(t_sum<tg) front++;
		else back--;
	}
	cout<<ans;
	return 0;
}