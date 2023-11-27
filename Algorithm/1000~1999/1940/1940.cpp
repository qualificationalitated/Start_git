#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int nums[n+1];
    int head=0, tail=n-1,count=0;
    for(int i=0;i<n;i++)
        cin>>nums[i];
    sort(nums,nums+n);
    while(head<tail){
        int temp = nums[head] + nums[tail];
        if(temp == m){ 
            count++;
            head++;
            tail--;
        }
        else
            temp<m? head++ : tail--;
    }
    cout<<count;
    return 0;
}