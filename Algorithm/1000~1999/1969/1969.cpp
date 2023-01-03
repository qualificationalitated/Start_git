// prob. 1969
// https://www.acmicpc.net/problem/1969
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,diffCnt=0,wordCount[51][27]={0,};
char ans[51];
string input[1000];
int diff(string x, string y){
    int count=0;
    for(int i=0;i<m;i++)
        if(x[i]!=y[i])
            count++;
    return count;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        cin>>input[i]; 
        for(int j=0;j<m;j++)
            wordCount[j][input[i][j]-'A']++;
    }
    for(int i=0;i<m;i++){
        int maxC=0,maxIndex;
        for(int j=0;j<26;j++){
            if(maxC<wordCount[i][j]){
                maxC=wordCount[i][j];
                maxIndex=j;
            }
        }
        ans[i]=maxIndex+'A';
    }
    for(int i=0;i<n;i++)
        diffCnt+=diff(ans,input[i]);
    cout<<ans<<"\n"<<diffCnt;
    return 0;
}