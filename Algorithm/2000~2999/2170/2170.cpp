#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct line{
	int st, ed;
};
bool cmp(const line a, const line b){
	return a.st<b.st;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,x,y;
	cin>>n;
	vector<line> inputs(n);
	for(int i=0;i<n;i++)
		cin>>inputs[i].st>>inputs[i].ed;
	sort(inputs.begin(), inputs.end(), cmp);

	int tot_len=0, curr_st = inputs[0].st,curr_ed = inputs[0].ed;
	for(int i=1;i<n;i++){
		if(inputs[i].st <= curr_ed){
			if(inputs[i].ed < curr_ed) continue;
			else curr_ed = inputs[i].ed;
		}
		else{
			tot_len += curr_ed - curr_st;
			curr_st = inputs[i].st;
			curr_ed = inputs[i].ed;
		}
	}
	cout<<tot_len + curr_ed - curr_st;
}