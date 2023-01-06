#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n,i,ansIndex=0,dupCount[1002],maxCount=1;
    string list[1002];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        cin>>list[i];
    sort(list,list+n);
    dupCount[0]=1;ansIndex=0;
    for(int i=1;i<n;i++){
        if(!list[i].compare(list[i-1]))
            dupCount[i]=dupCount[i-1]+1;
        else
            dupCount[i]=1;
        if(dupCount[i]>maxCount){
            maxCount=dupCount[i];
            ansIndex=i;
        }
    }
    cout<<list[ansIndex];
}