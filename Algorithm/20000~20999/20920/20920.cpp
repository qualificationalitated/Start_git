#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
unordered_map<string,int> wordCount;
bool compare(const string a, const string b){
	if(wordCount[a] == wordCount[b]){
		if(a.length() == b.length()){
			return a<b;
		}
		return a.length() > b.length();
	}
	return wordCount[a] > wordCount[b];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m;
	string words;
	vector<string> studyList;
	
	cin>>n>>m;
	while(n--){
		cin>>words;
		if(words.length()>=m && !wordCount[words]) studyList.push_back(words);
		wordCount[words]?wordCount[words]++ : wordCount[words] = 1;
	}
	sort(studyList.begin(),studyList.end(),compare);
	for(int i=0;i<studyList.size();i++){
		cout<<studyList[i]<<"\n";
	}
	return 0;
}