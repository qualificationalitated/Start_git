#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 100001
using namespace std;
int mbtiGap(string a, string b){
    int gap=0;
    for(int i=0;i<a.length();i++)
        gap+=a[i]!=b[i]?1:0;
    return gap;
}
int main(){
    int t,n;
    string mbti_list[MAX];
    int gapCount,min_gap;
    cin>>t;
    while(t--){
        min_gap=MAX;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>mbti_list[i];
        if(n>48)
            cout<<"0\n";
        else{
            for(int i=0;i<n-2;i++)
                for (int j=i+1;j<n-1;j++){
                    for (int k=j+1;k<n;k++){
                        gapCount=mbtiGap(mbti_list[i],mbti_list[j]);
                        gapCount+=mbtiGap(mbti_list[j],mbti_list[k]);
                        gapCount+=mbtiGap(mbti_list[i],mbti_list[k]);
                        if(min_gap>gapCount)
                            min_gap = gapCount;
                    }
                }
            cout<<min_gap<<"\n";
        }
    }
    return 0;
}