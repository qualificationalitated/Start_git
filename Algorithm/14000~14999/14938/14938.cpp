#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> dijkstra(int start, int n, vector<vector<pair<int,int>>> edge){
    priority_queue<pair<int,int>> pq;
    vector<int> minDist(n+1,__INT_MAX__);
    pq.push({0,start});
    while(!pq.empty()){
        pair<int,int> now = pq.top(); pq.pop();
        int nowArea = now.second;
        int nowDist = now.first*-1; // greater
        if(minDist[nowArea] < nowDist)  continue;
        
        minDist[nowArea] = nowDist;
        for(int i=0;i<edge[nowArea].size();i++){
            int nextArea = edge[nowArea][i].second;
            int nextDist = nowDist + edge[nowArea][i].first;
            // update minDist
            if(nextDist < minDist[nextArea]){
                minDist[nextArea] = nextDist;
                pq.push({nextDist*-1, nextArea});
            }
        }
    }
    return minDist;
}
int main(){
    int n,m,r;
    int a,b,l;
    int ans=-1;
    cin>>n>>m>>r;
    vector<int> items(n+1);
    vector<vector<pair<int,int>>> edge(n+1);
    for(int i=1;i<=n;i++)   cin>>items[i];
    while(r--){
        cin>>a>>b>>l;
        edge[a].push_back({l,b});
        edge[b].push_back({l,a});
    }
    for(int i=1;i<=n;i++){
        int totItem=0;
        vector<int> minDist = dijkstra(i,n,edge);
        for(int j=1;j<=n;j++)
            if(minDist[j]<=m)
                totItem = totItem+items[j];
        if(totItem>ans) ans=totItem;
    }
    cout<<ans;
    return 0;
}