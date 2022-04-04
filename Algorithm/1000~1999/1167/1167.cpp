#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100002
using namespace std;
bool visit[MAX];
int checkPoint,maxMoney=0;
vector<pair<int,int>> linked[MAX];
int find(int x,int money){
    visit[x]=true;
    if(money>maxMoney){
        maxMoney=money;
        checkPoint=x;
    }
    for(int i=0;i<linked[x].size();i++){
        int linkedNode=linked[x][i].first;
        int linkedNodeMoney=linked[x][i].second;
        if(visit[linkedNode]==false){
            find(linkedNode,money+linkedNodeMoney);
        }
    }
    return 0;
}
int main(){
    int v,x,a,b;
    scanf("%d",&v);
    for(int i=0;i<v;i++){
        scanf("%d",&x);
        while(1){
            scanf("%d",&a);
            if(a==-1)
                break;
            scanf("%d",&b);
            linked[x].push_back({a,b});
        }
    }
    fill(visit,visit+MAX,false);
    find(1,0);
    fill(visit,visit+MAX,false);
    maxMoney=0;
    find(checkPoint,0);
    printf("%d",maxMoney);
    return 0;
}