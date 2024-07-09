#include<iostream>
#include<queue>
#define LIM 100001
using namespace std;
int main(){
	int n,k,num,nCnt[LIM]={0,},mLen=0;
	queue<int> q;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>num;
		q.push(num);
		nCnt[num]++;
		if(nCnt[num] > k){
			while(q.size() && nCnt[num]>k){
				nCnt[q.front()]--;
				q.pop();
			}
		}
		if(mLen < q.size()) mLen = q.size();
	}
	cout<<mLen;
	return 0;
}