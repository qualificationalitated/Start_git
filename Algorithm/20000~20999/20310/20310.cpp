#include<iostream>
#include<string>
using namespace std;
int main(){
	int cnt[2]={0,};
	string input;
	cin>>input;
	for(int i=0;i<input.length();i++) cnt[input[i]-'0']++;
	cnt[0]/=2; cnt[1]/=2;
	for(int i=0;i<input.length();i++){
		if(input[i]=='0' && cnt[0])		cout<<"0";
		if(input[i]=='1' && (!cnt[1]))	cout<<"1";
		cnt[input[i]-'0'] = 0 > cnt[input[i]-'0']-1 ? 0 : cnt[input[i]-'0']-1;
	}
	return 0;
}