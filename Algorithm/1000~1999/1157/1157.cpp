#include<iostream>
#include<string>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string input;
	int ans,cnt[26]={0,},max=-1;
	bool duplicated = false;
	cin>>input;
	for(int i=0;i<input.length();i++){
		input[i]>='a'? cnt[input[i]-'a']++ : cnt[input[i]-'A']++;
	}
	for(int i=0;i<26;i++){
		if(cnt[i]>=max){
			cnt[i] == max ? duplicated = true : duplicated = false;
			max = cnt[i];
			ans = i;
		}
	}
	duplicated? cout<<"?" : cout<<char(ans+'A');
	return 0;
}