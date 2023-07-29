#include<iostream>
#include<queue>
#include<vector>
#define LOC 100002
#define INF 9223372036854775800
#define plli pair<long long,int>
using namespace std;
bool visible[LOC]; // 시야 여부
long long int minTime[LOC]; // 최소 시간
vector<plli> node[LOC];
int dijkstra(int start){
    long long nowTime,nextTime;
    int nowNode,nextNode;
    // 우선순위 큐 오름차순 선언
    priority_queue<plli,vector<plli>,greater<plli>> pq;
    pq.push(make_pair(0,start));
    minTime[start]=0;
    while(!pq.empty()){
        nowTime = pq.top().first;
        nowNode = pq.top().second;
        pq.pop();
        if (nowTime > minTime[nowNode])
            continue;
        for (int i = 0; i < node[nowNode].size(); i++){   
            nextNode = node[nowNode][i].second;
            nextTime = node[nowNode][i].first + minTime[nowNode];
            if(nextTime<minTime[nextNode] && !visible[nextNode]){
                minTime[nextNode] = nextTime;
                pq.push(make_pair(nextTime,nextNode));
            }
        }
    }
    return 0;
}
int main(){
    int n,m;
    int s,e,t;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
        cin>>visible[i];
    visible[n-1]=0; // 넥서스는 접근 가능하게
    fill(minTime,minTime+n,INF);
    while(m--){
        cin>>s>>e>>t;
        node[s].push_back(make_pair(t,e));
        node[e].push_back(make_pair(t,s));
    }
    dijkstra(0);
    if(minTime[n-1] == INF)
        cout<<"-1";
    else
        cout<<minTime[n-1];
    return 0;
}