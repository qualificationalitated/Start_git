#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct grid{
	int r,c;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,r,l,ans=0;
	grid move[4]={{0,1},{1,0},{0,-1},{-1,0}};
	cin>>n>>r>>l;
	vector<vector<int>> map(n);
	for(int i=0;i<n;i++){
		map[i].resize(n);
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	while(1){
		vector<vector<bool>> united(n);
		for(int i=0;i<n;i++)
			united[i].resize(n,false);
		bool isUnited = false;

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				queue<grid> q;
				vector<grid> uList;
				grid now, next;
				int sum=0,diff;
				if(!united[i][j]){
					q.push({i,j});
					while(!q.empty()){
						// bfs start point
						now = q.front(); q.pop();
						sum+=map[now.r][now.c];
						united[now.r][now.c] = true;

						// united city list
						uList.push_back(now);

						// find next city
						for(int i=0;i<4;i++){
							next.r = now.r+move[i].r;
							next.c = now.c+move[i].c;
							if(next.r<0 || next.r>=n || next.c<0 || next.c>=n)	continue;
							if(united[next.r][next.c])	continue;
							diff = abs(map[next.r][next.c] - map[now.r][now.c]);
							if(diff<r || diff>l)	continue;
							united[next.r][next.c] = true;
							q.push(next);
							isUnited=true;	
						}
						
					}
					for(int i=0;i<uList.size();i++)
						map[uList[i].r][uList[i].c] = sum/uList.size();
				}
			}
		}
		if(isUnited)ans++;
		else		break;
	}
	cout<<ans;
	return 0;
}