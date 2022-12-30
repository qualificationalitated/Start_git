#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    string in,ans;
    int temp=0,cnt=1;
    cin>>in;
    if(in.length()==1)
        cnt=0;
    for(int i=0;i<in.length();i++)
        temp+=in[i]-'0';
    while(temp>=10){
        int nTemp=temp;
        temp=0;
        cnt++;
        while(nTemp){
            temp+=nTemp%10;
            nTemp/=10;
        }
    }
    ans=temp%3?"NO":"YES";
    cout<<cnt<<"\n"<<ans;
    return 0;
}