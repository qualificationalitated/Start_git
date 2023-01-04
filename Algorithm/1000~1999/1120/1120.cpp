// prob. 1120
// https://www.acmicpc.net/problem/1120
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int diffCount(string a, string b){
    int cnt=0;
    for(int i=0;i<a.length();i++)
        cnt+=(a[i]!=b[i]);
    return cnt;
}
int main(){
    string a,b;
    int minDiff=51;
    cin>>a>>b;
    if(a.length()==b.length())
        minDiff=diffCount(a,b);
    else
        for(int i=0;i<=b.length()-a.length();i++){
            int diff=diffCount(a,b.substr(i,a.size()));
            minDiff=minDiff>diff?diff:minDiff;
        }
    printf("%d",minDiff);
    return 0;
}