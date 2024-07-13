#include<iostream>
#include<vector>
using namespace std;
int main(){
    int h,w,ans=0;
    int maxH=-1,wDrop=0;
    vector<int> wMap;
    cin>>h>>w;
    wMap.resize(w);
    // left to right
    for(int i=0;i<w;i++){ 
        cin>>wMap[i];
        if(wMap[i]>=maxH){
            maxH = wMap[i]; 
            ans+=wDrop; wDrop=0;
        }
        else
            wDrop += maxH - wMap[i];
    }
    // right to left
    maxH=-1,wDrop=0;
    for(int i=w-1;i>=0;i--)
        if(wMap[i]>maxH){
            maxH = wMap[i];
            ans+=wDrop; wDrop=0;
        }
        else
            wDrop += maxH - wMap[i];
    cout<<ans;
    return 0;
}