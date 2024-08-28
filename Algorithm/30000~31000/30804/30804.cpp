#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
	int N,cnt=0,head=0,ans=-1;
	unordered_map<int,int> hulu;
	cin>>N;
	int fruits[N+1];
	for(int i=0;i<N;i++){
		cin>>fruits[i];
		hulu[fruits[i]]++;

		if(hulu.size()>2){
			while(hulu.size()>2){
				int head_fruits = fruits[head];
				if(hulu[head_fruits]>1) hulu[head_fruits]--;
				else if(hulu[head_fruits] == 1){ 
					hulu.erase(head_fruits);
				}
				head++;
			}
		}
		int length = i-head+1;
		if(length>ans) ans = length;
	}
	cout<<ans;
	return 0;
}