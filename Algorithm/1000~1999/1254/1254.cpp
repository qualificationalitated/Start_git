#include<iostream>
#include<string>
using namespace std;
bool isPal(string S){
    bool isPal = true;
    for(int i=0;i<S.length()/2;i++){
        if(S[i]!=S[S.length()-1-i]) isPal = false;
    }
    return isPal;
}
int main(){
    string s;
    cin>>s;
    for (int cnt = 0; cnt <= s.length(); cnt++) // 1개 붙이고, 2개 붙이고..
    {
        string aped="";
        for(int i=cnt;i>0;i--)
            aped+=s[i-1];
        if(isPal(s+aped)){
            cout<<(s+aped).length();
            break;
        }
    }
    return 0;
}