#include<iostream>
#include<algorithm>
using namespace std;
#define SWC_COUNT 101
int print(int* swc, int n){
    for (int i = 0; i < n; i++){
        if(i && i%20 ==0 )
            cout<<"\n";
        cout<<swc[i+1]<<" ";
    }
    return 0;
}
int main(){
    int n,m;
    int sex,loc,tmp=1;
    int swc[SWC_COUNT] ={-1,0,};
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>swc[i+1];
    cin>>m;
    while(m--){
        tmp=1;
        cin>>sex>>loc;
        if(sex==1){ // 남자
            while(loc*tmp<=n){
                swc[loc*tmp] = swc[loc*tmp]?0:1;
                tmp++;
            }
        }
        else{ // 여자
            swc[loc] = swc[loc]?0:1;
            while(swc[loc-tmp] == swc[loc+tmp] && loc-tmp>0 && loc+tmp <= n){
                swc[loc-tmp]=swc[loc-tmp]?0:1;
                swc[loc+tmp]=swc[loc+tmp]?0:1;
                tmp++;
            }
        }
    }
    print(swc,n);
    return 0;
}