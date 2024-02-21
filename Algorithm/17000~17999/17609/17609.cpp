#include<iostream>
#include<string>
using namespace std;
int palCheck(string std,int head, int tail,int temp){
	while(head <= tail){
		if(std[head]!=std[tail]){
			if(!temp){
				int hChk = palCheck(std,head+1,tail,1);
				int tChk = palCheck(std,head,tail-1,1);
				return hChk<tChk?hChk:tChk;
			}
			else
				return 2;
		}
		head++; tail--;
	}
	return temp;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int t;
	string pal;
	cin>>t;
	while(t--){
		cin>>pal;
		cout<<palCheck(pal,0,pal.size()-1,0)<<"\n";
	}
	return 0;
}