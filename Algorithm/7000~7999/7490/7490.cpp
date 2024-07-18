#include<iostream>
#include<vector>
using namespace std;
int func(int n, string op){
	if(op.length() == n-1){
		int result=0,num=0, ten=1;
		for(int i=op.length()-1;i>=0;i--){
			if(!num) num = i+2;
			if(op[i]=='+'){
				result+=num; num=0; ten=1;
			}
			else if(op[i]=='-'){
				result-=num; num=0; ten=1;
			}
			else if(op[i]==' '){
				ten*=10;
				num+=(i+1)*ten;
			}
		}
		if(num) result+=num;
		else 	result+=1;
		if(!result){
			for(int i=0;i<op.length();i++)
				cout<<i+1<<op[i];
			cout<<op.length()+1<<"\n";
		}
		return 0;
	}
	func(n,op+' ');
	func(n,op+'+');
	func(n,op+'-');
	return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		func(n,string(""));
		cout<<"\n";
	}
	return 0;
}