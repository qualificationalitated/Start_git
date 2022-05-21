#include<iostream>
#include<cstdio>
#define CITY 11
#define MAX 10000001
int costMap[CITY][CITY],ans=MAX,n;
bool visit[CITY]={0,};
int find(int start,int loc,int cnt,int Cost){
    if(cnt==n){
        if(!costMap[loc][start])
            return 0;
        if(ans>Cost+costMap[loc][start])
            ans=Cost+costMap[loc][start];
        return 0;
    }
    for(int i=0;i<n;i++){
        if(visit[i]||costMap[loc][i]==0)
            continue;
        visit[i]=true;
        find(start,i,cnt+1,Cost+costMap[loc][i]);
        visit[i]=false;
    }
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&costMap[i][j]);
        
    for(int i=0;i<n;i++){
        visit[i]=true;
        find(i,i,1,0);
        visit[i]=false;
    }
    printf("%d",ans);
    return 0;
}