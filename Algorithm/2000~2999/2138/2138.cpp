#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string toggle(int loc, string str){
    if(loc)
        str[loc-1] = str[loc-1]=='0'?'1':'0';
    if(loc<str.length()-1) 
        str[loc+1] = str[loc+1]=='0'?'1':'0';
    str[loc] = str[loc]=='0'?'1':'0';
    return str;
}
int main(){
    int n, ansA=0, ansB=1;
    string startA, startB, end, origin;
    cin>>n>>startA>>end;
    startB = startA;
    // B -> toggle from first bulb
    startB = toggle(0,startB);
    // A -> toggle from second bulb
    for(int i=1;i<n;i++){
        if(startA[i-1]!=end[i-1]){
            startA = toggle(i, startA);
            ansA++;
        }
        if(startB[i-1]!=end[i-1]){
            startB = toggle(i, startB);
            ansB++;
        }
    }
    
    if(startA.compare(end)) ansA=-1;
    if(startB.compare(end)) ansB=-1;
    if(ansA==-1) cout<<ansB;
    else if(ansB==-1) cout<<ansA;
    else cout<<min(ansA,ansB);
    return 0;
}