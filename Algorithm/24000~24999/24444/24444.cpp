#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 100002
using namespace std;
vector<int> edge[MAX];
bool visited[MAX];
int answer[MAX];
int bfs(int start){
	queue<int> v_list;
	int order = 0;
	visited[start] = true;
	v_list.push(start);
	while(v_list.empty() == false){
		int now = v_list.front(); v_list.pop();
		answer[now] = ++order;
		for(int i=0;i<edge[now].size();i++)
			if(visited[edge[now][i]] == false){
				visited[edge[now][i]] = true;
				v_list.push(edge[now][i]);
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
		sort(edge[i].begin(),edge[i].end(),less<int>());
	bfs(r);
	for(int i=1;i<=n;i++)
		cout<<answer[i]<<"\n";
	return 0;
}