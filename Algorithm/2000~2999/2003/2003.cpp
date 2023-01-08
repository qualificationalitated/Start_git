#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int n,m,num,sum[10002]={0,},ans=0;
    int head=1,tail=1;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        sum[i]+=sum[i-1]+num;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=n-i;j++){
            if(sum[j+i]-sum[j-1]==m)
                ans++;
        }
    }
    printf("%d",ans);
    return 0;
}