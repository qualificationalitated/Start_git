#include<iostream>
#include<algorithm>
using namespace std;
struct hist{
	int score, count, lCommitTime;
};
struct tRank{
	int tID,tScore, tCount, tLCommitTime;
};
bool cmp(const tRank a, const tRank b){
	if(a.tScore == b.tScore){
		if(a.tCount == b.tCount){
			return a.tLCommitTime < b.tLCommitTime;
		}
		return a.tCount < b.tCount;
	}
	return a.tScore > b.tScore;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T,n,k,t,m; // 팀 수 n, 문제 수 k, 목표 팀 아이디 t, 로그 엔트리 수 m
	cin>>T;
	while(T--){
		cin>>n>>k>>t>>m;
		hist board[n+1][k+1];
		tRank team[n+1];
		int i,j,s;
		for(int idxA = 1; idxA<=n;idxA++){ 
			team[idxA] = {0,0,0,0};
			for(int idxB = 1; idxB <= k; idxB++)
				board[idxA][idxB] = {0,0,0};
		}
		for(int r=1;r<=m;r++){
			cin>>i>>j>>s;
			// 팀 아이디
			team[i].tID = i;
			// 제출 횟수
			team[i].tCount++;
			board[i][j].count++;
			// 커밋 시간
			team[i].tLCommitTime = r;
			board[i][j].lCommitTime = r;
			// 점수 갱신
			if(board[i][j].score < s){
				team[i].tScore = team[i].tScore - board[i][j].score + s;
				board[i][j].score = s;
			}
		}
		sort(team+1, team+n+1, cmp);
		int idx=1;
		while(team[idx].tID != t) idx++;
		cout<<idx<<"\n";
	}
	return 0;
}