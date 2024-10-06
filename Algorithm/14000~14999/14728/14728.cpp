#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,t,k,s;
    cin>>n>>t; // 단원 수, 공부 시간
    vector<int> highScoreByTime(t+1,0);
    while(n--){
        cin>>k>>s;//공부시간, 배점
        for(int i=t;i>=k;i--)
            highScoreByTime[i] = max(highScoreByTime[i],highScoreByTime[i-k]+s);
    }
    cout<<highScoreByTime[t];
    return 0;
}