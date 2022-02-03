#include<stdio.h>
int main(){
    int n,x,top=0,h[80002]={0,};
    long long ans=0;
    h[0]=__INT_MAX__;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        if(h[top]<=x) while(h[--top]<=x);
        ans+=top++;
        h[top]=x;
    }
    printf("%lld\n",ans);
    return 0;
}