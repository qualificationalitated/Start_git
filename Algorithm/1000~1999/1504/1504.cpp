#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#define NODE 802
#define MAX 200000000
using namespace std;

vector<pair<int,int>> list[NODE];
int minDist[NODE];
int dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    fill(minDist,minDist+NODE,MAX);
    minDist[start]=0;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        int nowNode=pq.top().second;
        int nowDist=pq.top().first*-1;
        pq.pop();
        if(minDist[nowNode]<nowDist)
            continue;
        for(int i=0;i<list[nowNode].size();i++){
            int nextNode=list[nowNode][i].first;
            int nextDist=nowDist+list[nowNode][i].second;
            if(minDist[nextNode]>nextDist){
                minDist[nextNode]=nextDist;
                pq.push(make_pair(nextDist*-1,nextNode));
            }
        }
    }
    return 0;
}
int solve(int va,int vb,int n){
    int min=MAX;
    int distA,distB;

    // 1부터 va,vb로의 최단거리 찾기
    dijkstra(1);
    distA=minDist[va]; // 1 to va
    distB=minDist[vb]; // 1 to vb
    
    // va-vb
    dijkstra(va);
    distA+=minDist[vb];
    distB+=minDist[vb];
    
    // va에서 도착점까지
    dijkstra(va);
    distB+=minDist[n];

    // vb에서 도착점까지
    dijkstra(vb);
    distA+=minDist[n];

    min=min>distA?distA:min;
    min=min>distB?distB:min;
    return min==MAX?-1:min;
}
int main(){
    int n,e;
    int a,b,c;
    int va,vb;
    scanf("%d %d",&n,&e);
    while(e--){
        scanf("%d %d %d",&a,&b,&c);
        list[a].push_back(make_pair(b,c));
        list[b].push_back(make_pair(a,c));
    }
    scanf("%d %d",&va,&vb);
    printf("%d",solve(va,vb,n));
    return 0;
}