#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct line{
    int start;
    int end;
    int cost;
    line(int x,int y,int z):start(x),end(y),cost(z){}
}; 
struct cmp{
    bool operator() (line x, line y){
        return x.cost > y.cost;
    }
};
int root[1002]={0,}, depth[1002]={0,}; // union find를 위한 배열
priority_queue<line,vector<line>,cmp> pq_list;
int root_find(int x){
    if(root[x]==x)
        return x;
    return root_find(root[x]);
}
int merge(int x,int y){
    int rx = root_find(x);
    int ry = root_find(y);
    if(rx == ry)
        return 0;
    if(depth[rx] > depth[ry])
        root[ry] = rx;
    else{
        root[rx] = ry;
        if(depth[rx] == depth[ry])
            depth[ry]+=1;
    }
    return 0;
}
int main(){
    int n,m; int x,y,z;
    int selected=0,ans=0;
    cin>>n>>m;
    for(int i=0;i<=n;i++)   root[i]=i;
    for(int i=0;i<m;i++){
        cin>>x>>y>>z; // 시작, 끝, 비용
        pq_list.push(line(x,y,z));
    }
    while(selected != n-1){
        line top = pq_list.top();
        pq_list.pop();
        if( root_find(top.start) != root_find(top.end) ){
            merge(top.start,top.end);
            selected++;
            ans+=top.cost;
        }
    }
    cout<<ans;
    return 0;
}
