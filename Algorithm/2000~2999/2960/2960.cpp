#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool arr[1002]={0,};
int solve(int n,int k,int cnt){
    for(int p=2;p<=n;p++){
        if(arr[p])
            continue;
        for(int j=1;j<=n/p;j++){
            if(!arr[p*j]){
                arr[p*j]=true;
                cnt++;
            }
            if(cnt==k)
                return p*j;
        }
    }
    return 0;
}
int main(){
    int k,n,cnt=0;
    scanf("%d %d",&n,&k);
    cout<<solve(n,k,0);
    return 0;
}