#include<iostream>
#include<queue>
#include<vector>
#define COM 10002
#define LIM 2147483647
#define PII pair<int,int>
int minTime[COM];
using namespace std;
int dijkstra(int start, vector<PII> *nwk){
    priority_queue<PII,vector<PII>,greater<PII>> pq;
    pq.push(make_pair(0,start));
    minTime[start]=0;
    while (!pq.empty())
    {
        int nowTime = pq.top().first;
        int nowCom = pq.top().second;
        pq.pop();
        if(nowTime>minTime[nowCom])
            continue;
        for (int i = 0; i < nwk[nowCom].size(); i++)
        {
            int nextCom = nwk[nowCom][i].second;
            int nextTime = nowTime + nwk[nowCom][i].first;
            if(nextTime < minTime[nextCom]){
                minTime[nextCom] = nextTime;
                pq.push(make_pair(nextTime,nextCom));
            }
        }
    }
    return 0;
}
int main(){
    int t;
    int n,d,c; // 컴퓨터 수 - 의존성갯수 - 해킹번호
    int a,b,s; // 의존정보 & 감염시간, b 감염시 a도 감염됨
    cin>>t;
    while(t--){
        int ansCnt=0,ansTime=0;
        vector<PII> network[COM];
        cin>>n>>d>>c;
        fill(minTime,minTime+n+1,LIM);
        while(d--){
            cin>>a>>b>>s;
            network[b].push_back(make_pair(s,a));
        }
        dijkstra(c,network);
        for(int i=1;i<=n;i++)
            if(minTime[i]!=LIM){
                ansCnt++;
                ansTime = ansTime<minTime[i]?minTime[i]:ansTime;
            }
        cout<<ansCnt<<" "<<ansTime<<"\n";
    }
    return 0;
}