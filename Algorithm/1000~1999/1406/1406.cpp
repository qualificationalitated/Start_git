#include<cstdio>
#include<iostream>
#include<list>
using namespace std;
int main(){
    string initial,cmd;
    int cmdCnt;
    list<char> ans;
    
    // init ans list
    cin>>initial;
    for(int i=0;i<initial.length();i++)
        ans.push_back(initial[i]);
    
    // set iterator
    list<char>::iterator loc=ans.end();
    
    // get command
    scanf("%d",&cmdCnt);
    cin.ignore();
    while(cmdCnt--){
        getline(cin,cmd);
        switch (cmd.front())
        {
        case 'L':
            if(loc!=ans.begin()) loc--;
            break;
        case 'D':
            if(loc!=ans.end()) loc++;
            break;
        case 'B':
            if(loc!=ans.begin()) loc=ans.erase(--loc);
            break;
        case 'P':
            ans.insert(loc,cmd[2]);
        }
    }
    for(loc=ans.begin();loc!=ans.end();loc++)
        cout<<*loc;
    return 0;
}