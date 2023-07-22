#include<iostream>
#define MAX 2000
using namespace std;
int main(){
    int n,m,map[1002]={0,};
    cin>>n;
    for(int i=1;i<n;i++)
        map[i]=MAX;
    for(int i=0;i<n;i++){
        cin>>m;
        for(int j=1;j<=m;j++){
            if(i+j<n && map[i+j]>map[i]+1)
                map[i+j] = map[i]+1;
        }
    }
    map[n-1]!=MAX?cout<<map[n-1]:cout<<"-1";
    return 0;
}