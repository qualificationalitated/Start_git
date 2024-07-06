#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m,bound,power;
	int head, tail, mid;
	string title;
	vector<pair<string,int>> lwPower;
	cin>>n>>m;
	while(n--){
		cin>>title>>bound;
		lwPower.push_back(make_pair(title,bound));
	}
	while(m--){
		head = 0; tail = lwPower.size()-1;
		cin>>power;
		while(head<=tail){
			mid = (head+tail)/2;
			power > lwPower[mid].second ? head = mid + 1 : tail = mid - 1;
		}
		if(power > lwPower[mid].second) mid++;
		cout<<lwPower[mid].first<<"\n";
	}
	return 0;
}