#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string s,t;
    cin>>s>>t;
    while(t.size()>s.size()){
        char tmp = t.back();
        t.pop_back();
        if(tmp=='B')
            reverse(t.begin(),t.end());
    }
    cout<<!(s.compare(t));
    return 0;
}