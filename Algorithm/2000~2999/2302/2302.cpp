#include<iostream>
#include<cstdio>
#define LIM 42
int arr[LIM]={0,},ans=1;
int pat[LIM]={1,1,2,};
int main(){
    int n,m,x,chechPoint=1;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d",&x);
        arr[x]=1;
    }
    for(int i=3;i<LIM;i++)
        pat[i]=pat[i-1]+pat[i-2];
    for(int i=1;i<=n;i++)
        if(arr[i]){
            ans*=pat[i-chechPoint];
            chechPoint=i+1;
        }
    if(!arr[n])
        ans*=pat[n-chechPoint+1];
    printf("%d",ans);
}