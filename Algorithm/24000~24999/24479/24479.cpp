#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 100002
using namespace std;
bool visited[MAX];
int answer[MAX],order;
vector<int> edge[MAX];

int dfs(int curr){
	visited[curr] = true;
	answer[curr] = ++order;
	for(int i=0;i<edge[curr].size();i++)
		if(!visited[edge[curr][i]])
			dfs(edge[curr][i]);
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,r,u,v;
	
	cin>>n>>m>>r;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		sort(edge[i].begin(),edge[i].end(),less<int>());
	
	dfs(r);
	
	for(int i=1;i<=n;i++)
		cout<<answer[i]<<"\n";
	return 0;
}