#include<iostream>
#include<string>
using namespace std;
int main(){
    int n, count=0, code=660, ans;
    cin>>n;
    while(code++ && count<n){
        if(to_string(code).find("666")!=string::npos){
            ans = code;
            count++;
        }
    }
    cout<<ans;
    return 0;
}