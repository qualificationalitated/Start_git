#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string S;
	unordered_set<string> substr_list;
	cin>>S;
	for(int i=0;i<S.length();i++){
		for(int j=i+1; j<=S.length();j++){
			substr_list.insert(S.substr(i,j-i));
		}
	}
	cout<<substr_list.size();
	return 0;
}