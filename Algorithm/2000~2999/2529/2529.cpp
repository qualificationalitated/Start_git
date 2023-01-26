#include<iostream>
using namespace std;
char buho[10];
bool nCheck[10]{0,};
string minAns, maxAns;
// 부호 비교함수, 부호에 맞는 결과인지 판단한다.
bool seqCheck(char x, char y, char buho){
	if(buho=='<') return x<y;
	else if(buho=='>') return x>y;
	else return true;
}
int make(int k,int loc, string ans){
	// 문자열 완성시 점검
	// 처음 만들어진 문자열은 최소, 마지막에 만들어진 문자열은 최대다.
	if(loc==k+1)
		if(!minAns.size()) minAns=ans;
		else maxAns=ans;
	else
		// 자리 수 대입하기
		for(int i=0;i<10;i++){
			// 사용한 숫자면 건너뛰기
			if(nCheck[i]) continue; 
			// 처음이거나, 이전 부호와 비교해 맞는 문자열이라면
			if(loc==0 || seqCheck( ans[loc-1] , i+'0' , buho[loc-1])){
				nCheck[i]=1;
				// 문자열 연장하기
				make(k,loc+1, ans+to_string(i));
				nCheck[i]=0;
			}
		}
	return 0;
}
int main(){
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
		cin>>buho[i];
	make(k,0,"");
	cout<<maxAns<<"\n"<<minAns;
	return 0;
}