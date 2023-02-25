#include<iostream>
#include<vector>
#include<queue>
#define MIN -1000002
#define LIM 10002
using namespace std;
struct edge{
    int st,ed,cost;
    edge(int x,int y,int z):st(x),ed(y),cost(z){} // 객체 생성자
    bool operator<(const edge x) const{ // 비교연산자 재정의를 통한 정렬 기준 설정
        return this->cost > x.cost; // cost가 작게 정렬하기
    }
}; 
priority_queue<edge> pq_list;
int root[LIM], depth[LIM]={0,};
int parent(int x){
    if(root[x]==x)
        return x;
    return parent(root[x]);
}
int merge(int x, int y){
    int rx = parent(x), ry = parent(y);
    if(rx == ry)
        return 0;
    if(depth[rx] > depth[ry]) // 깊이가 더 깊은곳을 부모로 삼기
        root[ry] = rx;
    else{
        root[rx] = ry;
        if(depth[rx]==depth[ry])
            depth[ry]+=1;
    }
    return 0;
}
int main(){
    int v,e; int x,y,z;
    int selected=0,ans=0;
    cin>>v>>e;
    for(int i=0;i<=v;i++) root[i]=i; // MST 구현을 위해 루트 설정해주고
    for(int i=0;i<e;i++){
        cin>>x>>y>>z;
        pq_list.push(edge(x,y,z));
    }
    while(selected != v-1){
        edge temp = pq_list.top();
        pq_list.pop();
        if( parent(temp.st) != parent(temp.ed) ){
            merge(temp.st, temp.ed);
            selected++;
            ans+=temp.cost;
        }
    }
    cout<<ans;
    return 0;
}