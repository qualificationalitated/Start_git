#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define LIM 301
using namespace std;
struct player{
	int l;
	string n;
};
bool compare(const player a, const player b){
	return a.n < b.n;
}
int main(){
	int p,m,rCnt=0;
	player nP;
	vector<player> rooms[LIM];
	cin>>p>>m; // 플레이어 수, 방 정원
	for(int i=0;i<p;i++){
		cin>>nP.l>>nP.n;
		if(!rCnt)
			rooms[rCnt++].push_back(nP);
		else{
			int j;
			for(j=0;j<rCnt;j++){
				if(rooms[j].size() < m && abs(rooms[j][0].l - nP.l)<=10){
					rooms[j].push_back(nP);
					break;
				}
			}
			if(j == rCnt)
				rooms[rCnt++].push_back(nP);
		}
	}
	for(int i=0;i<rCnt;i++){
		rooms[i].size() == m ? cout<<"Started!\n" : cout<<"Waiting!\n";
		sort(rooms[i].begin(),rooms[i].end(),compare);
		for(int j=0;j<rooms[i].size();j++)
			cout<<rooms[i][j].l<<" "<<rooms[i][j].n<<"\n";
	}
	return 0;
}