#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
short nums[300002];
int main()
{
    int n,cut;
    double ans=0;
    cin>>n;
    cut = round((double)n*0.15);
    if(!n)
        cout<<"0";
    else{
        for (int i = 0; i < n; i++)
            cin>>nums[i];
        sort(nums,nums+n);
        for (int i = cut; i < n-cut; i++)
            ans+=nums[i];
        cout<<round(ans/(n-2*cut));
    }
    return 0;
}