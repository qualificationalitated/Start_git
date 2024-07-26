#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,ans=0;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    sort(nums.begin(),nums.end(),less<int>());
    for(int i=0;i<n;i++){
        int h=0, t=n-1;
        bool isGood = false;
        while(h<t){
            if(nums[h]+nums[t]<nums[i])         h++;
            else if(nums[h]+nums[t]>nums[i])    t--;
            else{
                if(h==i) h++;
                else if(t==i) t--;
                else {
                    ans++;
                    break;
                }
            }
        }
        ans+=isGood;
    }
    cout<<ans;
    return 0;
}