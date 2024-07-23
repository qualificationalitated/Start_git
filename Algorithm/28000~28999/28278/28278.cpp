#include <iostream>
#include <stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N,X,num;
    stack<int> S;
    cin>>N;
    while(N--){
        cin>>X;
        switch(X){
            case 1:
                cin>>num;
                S.push(num);
                break;
            case 2:
                if(S.empty()){
                    cout<<-1<<"\n";
                    break;
                }
                cout<<S.top()<<'\n'; 
                S.pop();
                break;
            case 3:
                cout<<S.size()<<'\n';
                break;
            case 4:
                cout<<S.empty()<<"\n";
                break;
            case 5:
                S.empty()?cout<<-1<<'\n':cout<<S.top()<<'\n';
                break;
        }
    }
    return 0;
}