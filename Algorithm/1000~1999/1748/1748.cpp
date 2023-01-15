#include<iostream>
#include<cstdio>
#include<algorithm>
int main(){
    int n,sum=0;;
    scanf("%d",&n);
    // n+(n-9)+(n-99)+(n-999)...
    for(int i=1;i<=n;i*=10)
        sum+=n-i+1;
    printf("%d",sum);
    return 0;
}