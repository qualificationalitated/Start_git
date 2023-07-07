#include<iostream>
#include<algorithm>
using namespace std;
#define CTRY 1001
int map[CTRY][CTRY],cnt=0,n;
int visited[CTRY]={0,};
int init(){
    for (int i = 1; i <= n; i++)
        visited[i]=0;
    return 0;
}
int find(int x){
    for (int i = 0; i < n; i++){
        if(map[x][i+1] && visited[i+1] == 0){
            visited[i+1]=1;
            cnt++;
            find(i+1);
        }
    }
    return 0;
}
int main()
{
    int t, m, dep, dst;
    cin>>t;
    while (t--){
        init();
        cin>>n>>m;
        while(m--){
            cin>>dep>>dst;
            map[dep][dst]=1; map[dst][dep]=1;
        }
        cnt=0;
        visited[1]=1;
        find(1);
        cout<<cnt<<"\n";
    }
    return 0;
}