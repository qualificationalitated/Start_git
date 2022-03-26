#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#define MAX 100002
#define BUS 1002
using namespace std;
vector<pair<int,int>> map[MAX]; // 노선 인접리스트 구현
int minCost[BUS]={0,};//최단경로 저장용 배열
int dijkstra(int start){
    priority_queue<pair<int,int>> pque;
    //출발점 정하기..?
    pque.push({0,start});
    minCost[start]=0;

    while(!pque.empty()){//모든 정점을 다 탐색할 때 까지
        // 정점 정하기
        int nowBus=pque.top().second;
        int nowCost=pque.top().first*-1;
        pque.pop();
        if(minCost[nowBus]<nowCost)
            continue;
        // 연결된 버스들 찾기
        for(int i=0;i<map[nowBus].size();i++){
            int nextBus=map[nowBus][i].first;
            int nextCost=nowCost+map[nowBus][i].second;
            // 연결된 버스의 최단거리를 확정하고 다음 이동지로 정하기
            if(nextCost<minCost[nextBus]){
                    minCost[nextBus]=nextCost;
                    pque.push(make_pair(nextCost*-1,map[nowBus][i].first));
            }
        }

    }
    return 0;
}
int main(){
    int s,e;
    int n,m,x,y,cost;
    //버스 초기화
    for(int i=0;i<BUS;i++)
        minCost[i]=__INT_MAX__;
    // 버스의 갯수, 노선의 수 입력
    scanf("%d %d",&n,&m);
    while(m--){
        // 출발점, 도착점, 비용 순으로 입력
        scanf("%d %d %d",&x,&y,&cost);
        // 인접 리스트 구현하기
        map[x].push_back({y,cost});
    }
    // 출발지, 도착지 입력받고, 다익스트라 돌리기
    scanf("%d %d",&s,&e);
    dijkstra(s);
    printf("%d",minCost[e]);
    return 0;
}