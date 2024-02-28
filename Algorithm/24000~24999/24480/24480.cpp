#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100002
using namespace std;
vector<int> edge[MAX];
bool visited[MAX];
int answer[MAX],order;
int dfs(int curr){
	visited[curr] = true;
	answer[curr] = ++order;
	for(int i=0;i<edge[curr].size();i++){
		if(visited[edge[curr][i]] == false){
			dfs(edge[curr][i]);
		}
	}
	return 0;
}
int main(){
	int n,m,r,u,v;
	cin>>n>>m>>r;
	while(m--){
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		sort(edge[i].begin(),edge[i].end(),greater<int>());
	dfs(r);
	for(int i=1;i<=n;i++)
		cout<<answer[i]<<"\n";
	return 0;
}