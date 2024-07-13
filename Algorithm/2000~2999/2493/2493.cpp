#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct twr{int hei, loc;};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,h;
    stack<twr> st;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h;
        while(st.size() && st.top().hei < h) st.pop();
        st.size()?cout<<st.top().loc<<" ":cout<<0<<" ";
        st.push({h,i});
    }
    return 0;
}