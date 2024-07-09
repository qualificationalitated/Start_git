#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct pillar{
	int loc, hei;
};
bool cmpLoc(const pillar a, const pillar b){
	return a.loc<b.loc;
}
bool cmpAsc(const pillar a, const pillar b){
	return a.hei<b.hei;
}
bool cmpDesc(const pillar a, const pillar b){
	return a.hei>b.hei;
}
int main(){
	int n, ans = 0;
	pillar hst = {-1,-1};
	vector<pillar> list;
	cin>>n;
	list.resize(n);
	for(int i=0;i<n;i++)
		cin>>list[i].loc>>list[i].hei;
	sort(list.begin(),list.end(), cmpLoc);
	
	for(int i=0;i<n;i++)
		if(list[i].hei > hst.hei){
			hst.hei = list[i].hei;
			hst.loc = i; // index
		}
	sort(list.begin(),list.begin()+hst.loc, cmpAsc); // 앞은 오름차순 정렬
	sort(list.begin()+hst.loc+1,list.end(), cmpDesc); // 뒤는 내림차순 정렬
	int idx = hst.loc-1, mIdx = hst.loc;
	while(idx > -1){
		if(list[idx].loc < list[mIdx].loc){
			ans += (list[mIdx].loc - list[idx].loc) * list[idx].hei;
			mIdx = idx;
		}
		idx--;
	}
	idx = hst.loc+1, mIdx = hst.loc;
	while(idx < n){
		if(list[idx].loc > list[mIdx].loc){
			ans += (list[idx].loc - list[mIdx].loc) * list[idx].hei;
			mIdx = idx;
		}
		idx++;
	}
	cout<<ans + hst.hei<<"\n";
	return 0;
}