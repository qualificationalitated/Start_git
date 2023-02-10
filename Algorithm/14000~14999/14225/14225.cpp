#include<iostream>
using namespace std;
bool num[2000002]={0,};
int n,s[21];
int find(int loc, int sum){
    num[sum]=1;
    for(int j=loc+1;j<n;j++){
        find(j,sum+s[j]);
    }
    return 0;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
        find(i,s[i]);
    for(int i=1;i<=2000000;i++){
        if(!num[i]){
            cout<<i;
            break;
        }
    }
    return 0;
}