#include<iostream>
#include<vector>
#include<cstdio>
#define MAX 10002
using namespace std;

int visit[MAX]={0,},hacked=1;
vector<int> linked[MAX];
vector<pair<int,int>> v;

void findLink(int target){
    visit[target]=1;
    for(int i=0;i<linked[target].size();i++){
        int next=linked[target][i];
        if(!visit[next]){
            visit[next]=1;
            findLink(next);
            hacked++;
        }
    }
}
void init(int n){
    for(int i=1;i<=n;i++)
        visit[i]=0;
}
int main(){
    int n,m,max=0,a,b;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        linked[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        findLink(i);
        init(n);
        v.push_back({i,hacked});
        max=max>hacked?max:hacked;
        hacked=1;
    }
    for(int i=0;i<v.size();i++){
        if(v[i].second==max)
            printf("%d ",v[i].first);
    }
    return 0;
}