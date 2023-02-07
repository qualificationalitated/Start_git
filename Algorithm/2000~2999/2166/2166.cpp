#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<pair<double,double>> list;
int main(){
    int n;
    double ans=0,x,y;
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        list.push_back(make_pair(x,y));
    }

    list.push_back(list[0]);
    ans+=list[0].first * list[1].second;
    for(int i=1;i<n;i++){
        ans += list[i].first*list[i+1].second;
        ans -= list[i].first*list[i-1].second;
    }
    ans-=list[n].first * list[n-1].second;

    ans=abs(ans)/2;
    cout<<fixed;
    cout.precision(1);
    cout<<ans;

    return 0;
}