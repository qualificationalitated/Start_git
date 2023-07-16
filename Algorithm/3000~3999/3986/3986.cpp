#include <iostream>
#include <stack>
using namespace std;
int main() {
    int n,ans=0;
    cin>>n;
    while(n--) {
        stack<char> stk;
        string input;
        cin>>input;
        for (int i=0; i<input.length(); i++) {
            if(stk.empty())
                stk.push(input[i]);
            else
                if (stk.top() == input[i])
                    stk.pop();
                else
                    stk.push(input[i]);
        }
        if (stk.empty())// 좋은 단어는 스택이 비어진다
            ans++;
    }
    cout<<ans;
}