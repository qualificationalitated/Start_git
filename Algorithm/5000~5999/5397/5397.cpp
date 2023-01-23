#include<cstdio>
#include<iostream>
#include<list>
using namespace std;
int main(){
    string input;
    int t;
    scanf("%d",&t);
    while(t--){
        cin>>input;
        list<char> ans;
        list<char>::iterator loc=ans.begin();
        for(int i=0;i<input.length();i++){
            switch (input[i])
            {
            case '<':
                if(loc!=ans.begin()) loc--;
                break;
            case '>':
                if(loc!=ans.end()) loc++;
                break;
            case '-':
                if(loc!=ans.begin()) loc = ans.erase(--loc);
                break;
            default:
                ans.insert(loc,input[i]);
            }
        }
        for(loc=ans.begin();loc!=ans.end();loc++)
            cout<<*loc;
        printf("\n");
    }
    return 0;
}