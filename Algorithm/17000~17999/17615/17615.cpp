#include<iostream>
#include<string>
#define MAX 500001
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n, movRCnt=0, movBCnt=0, ans = MAX;
	string balls;
	bool isB = false, isR = false;
	cin>>n>>balls;
	// 왼쪽으로 보낼때
	movRCnt=0; movBCnt=0; isB = false; isR = false;
	for(int i=0;i<n;i++){
		if(balls[i]=='R'){
			isR = true;
			movRCnt+=isB;
		} else{
			isB = true;
			movBCnt+=isR;
		}
	}
	if(movRCnt<ans) ans = movRCnt;
	if(movBCnt<ans) ans = movBCnt;
	// 오른쪽으로 보낼때
	movRCnt=0; movBCnt=0; isB = false; isR = false;
	for(int i=n-1;i>=0;i--){
		if(balls[i]=='R'){
			isR = true;
			movRCnt+=isB;
		} else{
			isB = true;
			movBCnt+=isR;
		}
	}
	if(movRCnt<ans) ans = movRCnt;
	if(movBCnt<ans) ans = movBCnt;
	
	cout<<ans;
	return 0;
}