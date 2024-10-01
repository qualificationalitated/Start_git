#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,ans=0;
    string chat;
    set<string> messages;
    cin>>n;
    while(n--){
        cin>>chat;
        if(chat.compare("ENTER") == 0){
            ans+=messages.size();
            messages.clear();
            continue;
        }
        messages.insert(chat);
    }
    ans+=messages.size();
    cout<<ans;
    return 0;
}