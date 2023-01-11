#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int arr[10],ans[10]={0,};
int n,m;
int select(int loc){
    if(loc==m){
        for(int i=0;i<m;i++)
            printf("%d ",ans[i]);
        printf("\n");
        return 0;
    }
    for(int i=0;i<n;i++){
        ans[loc]=arr[i];
        select(loc+1);
    }
    return 0;
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    select(0);
    return 0;
}