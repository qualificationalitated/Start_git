#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 200002
using namespace std;
vector<pair<int,int>> cls_time;
priority_queue<int, vector<int>, greater<int>> pq_endTime;
int find(int cnt){
    // 첫 수업의 종료시간 우선순위 큐에 넣어주기
    pq_endTime.push(cls_time[0].second);
    // 필요한 강의실 수 탐색
    for(int i=1;i<cnt;i++){
        // 시작 시간에 따라 정렬된 i번째 수업의 종료 시간을 우선순위 큐에 삽입하고
        pq_endTime.push(cls_time[i].second);
        // top 번째 수업의 종료시간보다 i번째 수업이 늦게 시작하면, 같은 강의실을 사용할 수 있다는거니까, top을 빼주기
        if(pq_endTime.top() <= cls_time[i].first)
            pq_endTime.pop();
    }
    // 마지막에 우선순위 큐에 남아있는 수업의 수를 확인해주면 됩니다.
    return pq_endTime.size();
}
int main(){
    int n,st,ed;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>st>>ed;
        cls_time.push_back(make_pair(st,ed));
    }
    // 시작시간 기준으로 우선 정렬 하고
    sort(cls_time.begin(),cls_time.end());
    // 탐색해주기
    cout<<find(n)<<"\n";
    return 0;
}