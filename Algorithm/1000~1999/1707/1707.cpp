#include<iostream>
#include<vector>
using namespace std;
vector<int> visited;
int dfs(int now,vector<int> edges[]){
	if(!visited[now]) visited[now] = 1;
	for(int i=0;i<edges[now].size();i++){
		int next = edges[now][i];
		if(!visited[next]){
			visited[next] = visited[now]*-1;
			dfs(next, edges);
		}
	}
	return 0;
}
bool is_bipartite(int V, vector<int> edges[]){
	for(int i=1;i<=V;i++){
		for(int j=0;j<edges[i].size();j++){
			int connected = edges[i][j];
			if(visited[i]==visited[connected])
				return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int K,V,E,u,v;
	cin>>K;
	while(K--){
		cin>>V>>E;
		vector<int> edges[V+1];
		visited.resize(V+1);
		fill(visited.begin(),visited.end(),0);
		while(E--){
			cin>>u>>v;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		for(int i=1;i<=V;i++)
			if(!visited[i])	dfs(i,edges);
		is_bipartite(V,edges)?cout<<"YES\n":cout<<"NO\n";
	}
	return 0;
}