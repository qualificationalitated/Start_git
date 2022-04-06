#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define CITY 1002
#define MAX 100000002
using namespace std;

typedef struct{
    int pBus;
    int length;
}parent;
vector<pair<int,int>> cityMap[CITY];
priority_queue<pair<int,int>> pq;
int minCost[CITY];
parent bus[CITY];

int findRoot(int x){
    if(bus[x].pBus==x){
        return printf("%d ",x);
    }
    findRoot(bus[x].pBus);
    return printf("%d ",x);
}

void dijkstra(int start){
    minCost[start]=0;
    pq.push(make_pair(0,start));
    bus[start].pBus=start;
    bus[start].length=1;

    while(!pq.empty()){
        int nowBus=pq.top().second;
        int nowCost=pq.top().first*-1;
        pq.pop();
        if(nowCost>minCost[nowBus])
            continue;
        
        for(int i=0;i<cityMap[nowBus].size();i++){

            int nextBus=cityMap[nowBus][i].first;
            int nextCost=nowCost+cityMap[nowBus][i].second;

            if(minCost[nextBus]>nextCost){
                minCost[nextBus]=nextCost;
                bus[nextBus].pBus=nowBus;
                bus[nextBus].length=bus[nowBus].length+1;
                pq.push(make_pair(nextCost*-1,nextBus));
            }
        }
    }
}
int main(){
    int n,m,from,to,cost;
    int start,end;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d %d",&from,&to,&cost);
        cityMap[from].push_back({to,cost});
    }
    scanf("%d %d",&start,&end);
    fill(minCost,minCost+CITY,MAX);
    dijkstra(start);
    printf("%d\n%d\n",minCost[end],bus[end].length);
    findRoot(end);
    return 0;
}