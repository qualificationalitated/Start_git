#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string input;
	int cnt[2]={0,}; /** cnt[0] = a count, cnt[1] = b count */
	int wSize, inSize, ans; 
	int wCnt[2]={0,}; /** wCnt[0] = a count in window, wCnt[1] = b count in window */
	bool flag = 0;
	cin>>input; inSize = input.size();
	// 윈도우 크기 설정
	for(int i=0;i<inSize;i++)
		cnt[input[i]-'a']++;
	if(cnt[0]>cnt[1])	flag = 0;
	else 				flag = 1;
	wSize = min(cnt[0],cnt[1]);

	// 초기 윈도우 및 바꿔야 할 갯수 설정
	for(int i=0;i<wSize;i++)
		wCnt[input[i]-'a']++; // 윈도우 내 a,b 갯수 카운트
	ans = wCnt[flag];

	// 윈도우 사이즈 잡고 슬라이딩
	for(int i=0;i<inSize;i++){
		wCnt[input[i]-'a']--;
		wCnt[input[(i+wSize)%inSize]-'a']++;
		ans = min(ans, wCnt[flag]);
	}
	cout<<ans;
	return 0;
}