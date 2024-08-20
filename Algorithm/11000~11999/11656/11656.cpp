#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int str_len;
	string input;
	vector<string> zupmi;
	cin>>input;
	str_len = input.length();
	for(int i=0;i<str_len;i++)
		zupmi.push_back(input.substr(i,str_len - i));
	sort(zupmi.begin(), zupmi.end());
	for(auto str : zupmi)
		cout<<str<<"\n";
	return 0;
}