#include<stdio.h>
long long f(int a,int b,int c){
    if(b==1) return a%c;
    if(b%2==0) return (f(a,b/2,c)*f(a,b/2,c))%c;
    else return (f(a,b/2,c)*f(a,1+b/2,c))%c;
}
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    printf("%lld",f(a,b,c)%c);
    return 0;
}