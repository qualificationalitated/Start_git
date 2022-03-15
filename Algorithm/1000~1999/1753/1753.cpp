#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000
#define vMAX 20001
#define eMAX 300001

using namespace std;
int minValue[vMAX];
vector<pair<int, int> > edge[eMAX];
int dijkstra(int start){
    minValue[start] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    while(!pq.empty()){
        int now = pq.top().second;
        int nowValue = pq.top().first*-1;
        pq.pop();
        if (minValue[now] < nowValue)
            continue;

        for (int i=0; i<edge[now].size(); i++){
            int next = edge[now][i].second;
            int nextValue = nowValue + edge[now][i].first;
            if (minValue[next] > nextValue){
                minValue[next] = nextValue;
                pq.push(make_pair(-nextValue, next));
            }
        }
    }
    return 0;
}

int main(){
    int v,e,k;
    int start,end,cost;
    scanf("%d %d %d",&v,&e,&k);
    for (int i=1; i<=v; i++)
        minValue[i] = INF;
    while(e--){
        scanf("%d %d %d",&start,&end,&cost);
        edge[start].push_back(make_pair(cost, end));
    }
    dijkstra(k);
    for (int i=1; i<=v; i++)
        if (minValue[i] == INF)
            printf("INF\n");
        else
            printf("%d\n",minValue[i]);
    return 0;
}