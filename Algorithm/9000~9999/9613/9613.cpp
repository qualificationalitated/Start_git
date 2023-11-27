#include<iostream>
using namespace std;
int gcd(int x, int y){
    if(!y) return x;
    return gcd(y,x%y);
}
int main(){
    int n,t;
    cin>>t;
    while(t--){
        int nums[101];
        long long sum=0;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>nums[i];
        for (int i = 0; i < n-1; i++)
            for (int j = i+1; j < n; j++)
                sum+=gcd(nums[i],nums[j]);
        cout<<sum<<"\n";
    }
    return 0;
}