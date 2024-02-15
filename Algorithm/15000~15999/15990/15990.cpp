#include <iostream>
#define MAX 100002
#define DIV 1000000009
using namespace std;
typedef unsigned int ui;
ui ansCnt[MAX][4]={0,};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t,n;
	ui answer=0;
	for(int i=1;i<=3;i++)
		ansCnt[i][i]=1;
	for(int i=1;i<=MAX;i++){
		// 규칙
		// 마지막 수가 1로 끝나는 경우 -> +2, +3 함으로써 다음 수의 경우에 누적 가능
		// 마지막 수가 2로 끝나는 경우 -> +1, +3 함으로써 다음 수의 경우에 누적 가능
		// 마지막 수가 3로 끝나는 경우 -> +1, +2 함으로써 다음 수의 경우에 누적 가능
		if(i+1<MAX){
			ansCnt[i+1][1] = (ansCnt[i+1][1] + ansCnt[i][2])%DIV;
			ansCnt[i+1][1] = (ansCnt[i+1][1] + ansCnt[i][3])%DIV;
		}
		if(i+2<MAX){
			ansCnt[i+2][2] = (ansCnt[i+2][2] + ansCnt[i][1])%DIV;
			ansCnt[i+2][2] = (ansCnt[i+2][2] + ansCnt[i][3])%DIV;
		}
		if(i+3<MAX){
			ansCnt[i+3][3] = (ansCnt[i+3][3] + ansCnt[i][1])%DIV;
			ansCnt[i+3][3] = (ansCnt[i+3][3] + ansCnt[i][2])%DIV;
		}
	}
	cin>>t;
	while(t--){
		answer = 0;
		cin>>n;
		for(int i=1;i<=3;i++)
			answer = (answer + ansCnt[n][i])%DIV;
		cout<<answer<<"\n";
	}
	return 0;
}