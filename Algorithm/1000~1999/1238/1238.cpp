#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#define CITY 1002
using namespace std;
vector<pair<int,int>> cityList[CITY];
int partyToHome[CITY]={0,},minTime[CITY];
int dijkstra(int start){
    fill(minTime,minTime+CITY,__INT_MAX__);
    priority_queue<pair<int,int>> pq;
    minTime[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        int nowLoc=pq.top().second;
        int nowTime=pq.top().first*-1;
        pq.pop();

        if(minTime[nowLoc]<nowTime)
            continue;
             
        for(int i=0;i<cityList[nowLoc].size();i++){
            int nextLoc=cityList[nowLoc][i].first;
            int nextTime=cityList[nowLoc][i].second+nowTime;

            if(minTime[nextLoc]>nextTime){
                minTime[nextLoc]=nextTime;
                pq.push({nextTime*-1,nextLoc});
            }
        }
    }
    return 0;
}
int main(){
    int n,m,x,ans=0;
    scanf("%d %d %d",&n,&m,&x); // n명의 학생이x번 마을에 모여서 파티를 한다. 총 m개의 도로가 있고 도로를 지나는데 t만큼의 시간이 걸린다.
    for(int i=0;i<m;i++){
        int to,from,t;
        scanf("%d %d %d",&to,&from,&t);
        cityList[to].push_back({from,t});
    }
    dijkstra(x);
    for(int i=1;i<=n;i++)
        partyToHome[i]=minTime[i];
    for(int i=1;i<=n;i++){
        dijkstra(i);
        if(ans<partyToHome[i]+minTime[x])
            ans=partyToHome[i]+minTime[x];
    }
    printf("%d",ans);
    return 0;
}