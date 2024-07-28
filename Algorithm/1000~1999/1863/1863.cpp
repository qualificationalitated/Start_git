#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
bool compare(const pair<int,int> a,const pair<int,int> b){
    return a.first<b.first;
}
int main(){
    int n,ans=0;
    stack<pair<int,int>> skyline;
    cin>>n;
    vector<pair<int,int>> input(n,{0,0});
    for(int i=0;i<n;i++)
        cin>>input[i].first>>input[i].second;
    for(int i=0;i<n;i++){
        int building=0;
        while(skyline.size() && input[i].second<skyline.top().second ){
            skyline.pop();
            ans++;
        }
        if(skyline.empty() || input[i].second > skyline.top().second)
            skyline.push(input[i]);
    }
    while(skyline.size()){
        if(skyline.top().second) ans++;
        skyline.pop();
    }
    cout<<ans;
    return 0;
}