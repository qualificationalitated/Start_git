#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
struct range{
	int s,e;
	range(int S,int E):s(S),e(E){}
};
int main(){
	int k,last_idx,new_line=1;
	vector<int> input, answer;
	queue<range> devide;
	cin>>k;
	input.resize(pow(2,k)-1);
	for(int i=0;i<pow(2,k)-1;i++)
		cin>>input[i];
	last_idx = input.size()-1;
	devide.push({0,last_idx});
	
	while(!devide.empty()){
		range now = devide.front(); devide.pop();
		if(now.s == now.e)
			answer.push_back(input[now.s]);
		else if(abs(now.e-now.s) == 1){
			answer.push_back(input[now.s]);
			answer.push_back(input[now.e]);
		}			
		else{
			int mid = (now.s+now.e)/2;
			answer.push_back(input[mid]);
			devide.push({now.s,mid-1});
			devide.push({mid+1,now.e});
		}
	}
	for(int i=0;i<answer.size();i++){
		cout<<answer[i]<<" ";
		if((i+1) == pow(2,new_line)-1){
			cout<<"\n";
			new_line*=2;
		}
	}
	return 0;
}