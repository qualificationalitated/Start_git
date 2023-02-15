#include<iostream>
#include<vector>
#define MAX 100002
using namespace std;
vector<int> list[MAX];
int childNode[MAX]={0,};
int find(int from, int now){
    for(int i=0;i<list[now].size();i++){
        if(list[now][i] == from) // 부모로 돌아가지 않게 하기
            continue;
        childNode[now]+=find(now,list[now][i]);
    }
    return childNode[now]+1;
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,r,q; // r이 루트
    int u,v; // 연결된 두 간선 u,v
    int x; // 쿼리
    cin>>n>>r>>q;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    find(-1,r);
    while(q--){
        cin>>x;
        cout<<childNode[x]+1<<"\n";
    }
    return 0;
}