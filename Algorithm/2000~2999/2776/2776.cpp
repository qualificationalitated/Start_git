#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,m,tmp;
        unordered_map<int,bool> checkList;
        cin>>n;
        while(n--){
            cin>>tmp;
            checkList[tmp] = true;
        }
        cin>>m;
        while(m--){
            cin>>tmp;
            cout<<checkList[tmp]<<"\n";
        }
    }
    return 0;

}