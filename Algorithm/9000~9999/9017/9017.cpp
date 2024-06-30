#include<iostream>
#include<vector>
#define RUNNER 1001
#define TEAM 201
using namespace std;
typedef struct{
	int team, score;
}runner;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t,n;
	cin>>t;
	while(t--){
		int score=1;
		int max = 200*200,ans = 0,fifth = RUNNER;
		runner list[RUNNER];
		int rankCount[TEAM] = {0,};
		vector<int> teamScoreOver6[TEAM];
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>list[i].team;
			rankCount[list[i].team]++;
		}
		for(int i=0;i<n;i++){
			runner currRunner = list[i];
			if(rankCount[currRunner.team]>=6){
				currRunner.score = score++;
				teamScoreOver6[currRunner.team].push_back(currRunner.score);
			}
		}
		for (int i = 1; i < TEAM; i++)
		{
			int sum = 0;
			if(teamScoreOver6[i].size()){
				for (int j = 0; j < 4; j++) sum += teamScoreOver6[i][j];
				if(sum < max || (sum == max && fifth > teamScoreOver6[i][4])){
					max = sum;
					ans = i;
					fifth = teamScoreOver6[i][4];
				}
			}
		}
		
		cout<<ans<<"\n";
	}
	return 0;
}