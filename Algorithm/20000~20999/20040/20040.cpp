#include<iostream>
#include<queue>
#define LIM 500002 // 점 수
using namespace std;
int parent[LIM],depth[LIM];
int init_root(int x){
    for(int i=0;i<=x;i++){
        parent[i] = i;
        depth[i]=0;
    }
    return 0;
}
int find_root(int x){
    if(x==parent[x])
        return x;
    return find_root(parent[x]);
}
int merge(int rx,int ry){
    if(depth[rx] > depth[ry])
        parent[ry] = rx;
    else{
        parent[rx] = ry;
        if(depth[rx] == depth[ry])
            depth[ry]++;
    }
    return 0;
}
int main(){
    int n,m, x,y, rx,ry;//시작점, 끝점
    int loop_time=0;
    cin>>n>>m;
    init_root(n);
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        if(loop_time)
            continue;
        rx = find_root(x);
        ry = find_root(y);
        if(rx == ry) // 루프
            loop_time = i;
        else
            merge(rx,ry);
    }
    cout<<loop_time;
    return 0;
}