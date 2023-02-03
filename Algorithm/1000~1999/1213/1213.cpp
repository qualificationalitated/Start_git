#include<iostream>
#include<algorithm>
using namespace std;
string make_palindrome(int *alpha,char oddChar){
	string ans="", revAns="";
	int half;
	for(int i=0;i<26;i++){
		half=alpha[i]/2;
		for(int j=0;j<half;j++)
			ans+=char(i+'A');
	}
	revAns=ans;
	reverse(revAns.begin(),revAns.end());
	if(oddChar!=' ')	ans+=oddChar; // 홀수 문자가 있으면 중간에 끼워주기
	return ans+revAns;
}
int main(){
	// 펠린드롬 - 회문, 거꾸로 읽어도 제대로 읽을수 있는 문자열
	string name;
	char oddChar=' ';
	int alpha[27]={0,},oddCheck=0;
	cin>>name;
	for(int i=0;i<name.size();i++)	alpha[name[i]-'A']++;
	for(int i=0;i<26;i++){
		int tmp=alpha[i]%2;
		if(tmp){
			oddCheck+=tmp;
			oddChar=i+'A'; // 홀수 알파벳 기억하기
		}
	}
	if(oddCheck>1)	cout<<"I'm Sorry Hansoo\n";
	else			cout<<make_palindrome(alpha,oddChar);
	return 0;
}