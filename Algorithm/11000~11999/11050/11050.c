#include<stdio.h>
int cal(int s,int e){
    int r=1;
    for (int i=s;i<=e;i++)
        r*=i;
    return r;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%d\n",cal(n-k+1,n)/cal(1,k));
    return 0;
}