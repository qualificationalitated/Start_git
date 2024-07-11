#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool answer(string s, string t){
	bool p = false;
	if(s.length() == t.length())    return s==t;
	else{
		if(p == false && t[t.length()-1]=='A'){
			t.pop_back();
			if(answer(s,t)) p = true;
			t.push_back('A');
		}
		if(p == false && t[0]=='B'){
			reverse(t.begin(),t.end());
			t.pop_back();
			if(answer(s,t)) p = true;
			t.push_back('B');
			reverse(t.begin(),t.end());
		}
	}
	return p;
}
int main(){
	string s,t;
	cin>>s>>t;
	cout<<answer(s,t);
	return 0;
}