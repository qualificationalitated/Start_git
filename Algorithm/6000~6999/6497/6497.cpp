#include<cstdio>
#include<vector>
#include<algorithm>
#define LIM 200002
using namespace std;
struct road{
    int st,ed,cost;
};
vector<road> list;
int cmp(road x,road y){
    return x.cost<y.cost;
}

int parent[LIM]={0,}, depth[LIM]={0,};
int root(int x){
    if(x == parent[x])
        return x;
    return parent[x] = root(parent[x]);
}
int merge(int x, int y){
    int rx = root(x), ry = root(y);
    parent[rx] = ry; // 무조건 y 루트로 병합
    return 0;
}
int main(){
    int m,n; int x,y,z;
    int ans=0,selected=0,total_cost=0;
    while(1){
        scanf("%d %d",&m,&n);
        if(m==0 && n==0)    break;
        ans=0;selected=0;total_cost=0;
        list.clear();
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&x,&y,&z);
            list.push_back({x,y,z});
            total_cost+=z;
        }
        for(int i=0;i<=m;i++)   parent[i] = i;
        sort(list.begin(),list.end(),cmp);
        for(int i=0;i<n;i++){
            int x = root(list[i].st), y=root(list[i].ed);
            if(x!=y){
                merge(x,y);
                ans+=list[i].cost;
                selected++;
            }
            if(selected==m-1)
                break;
        }
        printf("%d\n",total_cost-ans);
    }
    return 0;
}