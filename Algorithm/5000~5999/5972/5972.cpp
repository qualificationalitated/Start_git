#include<iostream>
#include<vector>
#include<queue>
#define HUTS 50002
#define LINE 50002
#define LIM 2147483647
using namespace std;
vector<pair<int,int>> map[LINE];
int minCost[HUTS]={0,};
int dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    minCost[start]=0;
    pq.push({0,start}); // 시작 위치의 거리 & 지점 설정하고
    while(!pq.empty()){ // 큐가 빌때까지 돕니다
        // 지금 지점 선정하고
        int nowHut=pq.top().second;  
        int nowCost=pq.top().first*-1; // 최소값 선정은 -1을 곱해주자, 애초에 음수로 들어간걸 양수로 바꾸는 과정
        pq.pop();
        if(minCost[nowHut]<nowCost) // 이미 최대값이 갱신된경우 처리하지 않음
            continue;
        // 지금 지점에서 연결된 모든 지점 탐색, 가중치 갱신
        for (int i = 0; i < map[nowHut].size(); i++)
        {
            int nextHut = map[nowHut][i].first;
            int nextCost = map[nowHut][i].second + nowCost;
            if(nextCost<minCost[nextHut]){
                minCost[nextHut] = nextCost;
                pq.push(make_pair(nextCost*-1, map[nowHut][i].first)); // 다익스트라에서 최소 비용 선정시 -1 곱해서, 음으로 넣어주기
                // 주의! 큐에는 음으로 넣고, 처리할때는 -1 곱해서 양으로 뽑는거다.
            }
        }
        
    }
    return 0;
}
int main(){
    int n,m;
    int A,B,C;
    cin>>n>>m;
    fill(minCost,minCost+HUTS,LIM); // 모든값을 최대값으로 갱신
    while(m--){
        cin>>A>>B>>C;
        map[A].push_back({B,C});
        map[B].push_back({A,C});
    }
    //1번 헛간부터 출발해, N번 헛간으로 가자
    dijkstra(1);
    cout<<minCost[n];
    return 0;
}