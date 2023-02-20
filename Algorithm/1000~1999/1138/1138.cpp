#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<pair<int,int>> line;
bool cmp(pair<int,int> x, pair<int,int> y){
    if(x.first == y.first)
        return x.second<y.second;
    else
        return x.first<y.first;
}
int main(){
    int n, loc=0;
    int x,y;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        line.push_back(make_pair(x,i));
    }
    sort(line.begin(),line.end(),cmp);

    for(int i=0;i<n;i++){
        int loc = i, cnt=0;
        for(int j=0;j<i;j++){
            if(line[j].second>line[loc].second)   cnt++;
        }
        if(cnt>line[loc].first){
            int tmp = cnt-line[loc].first;
            while(tmp--){
                swap(line[loc],line[loc-1]);
                loc--;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<line[i].second<<" ";
    return 0;
}