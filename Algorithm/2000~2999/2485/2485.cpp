#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int main(){
    int n,ans=0,gcdNum;
    cin>>n;
    vector<int> loc(n);
    for(int i=0;i<n;i++){
        cin>>loc[i];
        if(i==1) gcdNum = loc[i]-loc[i-1];
        else if(i>1) gcdNum = gcd(gcdNum,loc[i]-loc[i-1]); 
    }
    for(int i=0;i<n-1;i++){
        int diff = loc[i+1] - loc[i];
        ans+=(diff/gcdNum)-1;
    }
    cout<<ans;
    return 0;
}