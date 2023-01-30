#include<iostream>
#include<string>
#define MAX 100002
using namespace std;
string input,stk;
int top=0;
bool tag=false;
int main(){
	getline(cin,input);
	for(int i=0;i<input.size();i++){
		if(input[i]=='<'){
			while(!stk.empty()){
				cout<<stk.back();
				stk.pop_back();
			}
			tag=true;
			cout<<"<";
		}
		else if(input[i]=='>'){
			tag=false;
			cout<<">";
		}
		else if(input[i]==' '){
			while(!stk.empty()){
				cout<<stk.back();
				stk.pop_back();
			}
			cout<<" ";
		}
		else{
			if(tag) cout<<input[i];
			else stk.push_back(input[i]);
		}
	}
	while(!stk.empty()){
		cout<<stk.back();
		stk.pop_back();
	}
	return 0;
}