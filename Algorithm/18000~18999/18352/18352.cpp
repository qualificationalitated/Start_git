#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m,k,x,a,b; // x로부터 출발해 도달할수 있는 도시 중, 최단거리가 k인 지점
	vector<int> visited,answer;
	queue<int> que;
	cin>>n>>m>>k>>x;
	vector<int> node[n+1];
	visited.resize(n+1,0);
	while(m--){
		cin>>a>>b;
		node[a].push_back(b); // 경로 길이는 1
	}
	que.push(x);
	visited[x] = 1;
	while(que.size()){
		int now = que.front(); que.pop();
		if(visited[now]<=k){
			for(auto next : node[now]){
				if(visited[next]) continue; // 이미 방문했다면 체크하지 않음
				if(visited[now]==k)
					answer.push_back(next);
				visited[next] = visited[now]+1;
				que.push(next);
			}
		}
	}
	if(!answer.size()) cout<<"-1";
	else{
		sort(answer.begin(),answer.end());
		for(auto node : answer)
			cout<<node<<"\n";
	}
	return 0;
}