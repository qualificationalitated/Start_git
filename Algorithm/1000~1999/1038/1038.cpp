#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> list;
int make(string num,int x,int len){
    if(num.length()==len)
        list.push_back(num);
    else{
        for(int i=0;i<x;i++){
            num+=char(i+'0');
            make(num,i,len);
            num.pop_back();
        }
    }
    return 0;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<10;i++)
        make("",10,i+1);
    if(n>=list.size())  cout<<"-1";
    else                cout<<list[n];
    return 0;
}