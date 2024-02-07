#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio;
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,k,apple,ans=0,currLoc=1,move;
    cin>>n>>m>>k;
    while (k--)
    {
        cin>>apple;
        if(currLoc + m - 1 < apple){
            ans+=apple - (currLoc+m-1);
            currLoc+=apple - (currLoc+m-1);
        }
        else if(apple < currLoc){
            ans += currLoc - apple;
            currLoc -= currLoc - apple;
        }
    }
    cout<<ans;
    return 0;
}