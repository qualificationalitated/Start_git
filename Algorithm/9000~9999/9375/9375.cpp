#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
typedef struct{
    string name;
    string type;
}clothes;
bool cmp(clothes a, clothes b){
    return a.type<b.type;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,ans=1;
        int type[32]={0,},typeCnt=0;
        clothes list[32];
        
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            cin>>list[i].name>>list[i].type;
        sort(list,list+n,cmp); // 타입별로 정렬
        if(n){
            type[0]=1;
            for(int i=1;i<n;i++)
                if(list[i].type == list[i-1].type)
                    type[typeCnt]++;
                else
                    type[++typeCnt]=1;
        }
        else
            type[0]=0; // n이 0인경우 처리
        
        for(int i=0;i<=typeCnt;i++)
            ans*=(type[i]+1);
        printf("%d\n",ans-1);
    }
    return 0;
}