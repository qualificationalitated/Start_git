#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
bool dispInfo[10][8] = {
        {1,1,1,0,1,1,1}, // 0
        {0,0,1,0,0,1,0}, // 1
        {1,0,1,1,1,0,1}, // 2
        {1,0,1,1,0,1,1}, // 3
        {0,1,1,1,0,1,0}, // 4
        {1,1,0,1,0,1,1}, // 5
        {1,1,0,1,1,1,1}, // 6
        {1,0,1,0,0,1,0}, // 7
        {1,1,1,1,1,1,1}, // 8
        {1,1,1,1,0,1,1},}; //9
int change(int a, int b){
    int diff=0;
    for(int i=0;i<8;i++)
        diff+=abs(dispInfo[a][i] - dispInfo[b][i]);
    return diff;
}
int findPossibles(vector<int> original, vector<int> turnInto,int loc,int P,int N){
    int ans=0;
    if(loc==original.size()){
        int diff=0,num=0;
        for(int i=0;i<loc;i++){
            num*=10;
            num+=turnInto[i];
            diff+=change(original[i],turnInto[i]);
        }
        if(diff>0 && diff<=P && num<=N && num>0) ans++;
        return ans;
    }
    for(int i=0;i<=9;i++){
        turnInto[loc] = i;
        ans+=findPossibles(original, turnInto, loc+1,P,N);
    }
    return ans;
}
int main(){
    int N,K,P,X;
    cin>>N>>K>>P>>X;
    vector<int> num(K,0);
    while(X){
        num[K-1] = X%10;
        K--; X/=10;
    }
    cout<<findPossibles(num, vector<int>(num.size(),0),0,P,N);
    return 0;
}