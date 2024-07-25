#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
using psi = pair<string,int>;
bool cmp(const psi a, const psi b){
    if(a.second == b.second)
        return stoll(a.first)<stoll(b.first);
    return a.second>b.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    string c,ans;
    unordered_map<string, int> card;
    
    cin>>n;
    while(n--){
        cin>>c;
        card[c]++;
    }
    vector<pair<string,int>> cardList(card.begin(), card.end());
    sort(cardList.begin(), cardList.end(), cmp);
    cout<<cardList[0].first;
    return 0;
}