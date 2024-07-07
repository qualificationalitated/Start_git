#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, totCount = 0;
	string kwd,input;
	unordered_map<string,bool> kwdDict;
	cin>>n>>m;
	totCount = n;
	while(n--){
		cin>>kwd;
		kwdDict[kwd] = true;
	}
	while(m--){
		cin>>input;
		input.append(",");
		while(input.length()){
			string iKeyword = input.substr(0,input.find(","));
			if(kwdDict[iKeyword]){
				kwdDict[iKeyword] = false;
				totCount--;
			}
			input.erase(0,input.find(",")+1);
		}
		cout<<totCount<<"\n";
	}
	return 0;
}