#include<stdio.h>
int n,m,list[100002],check=0,len=__INT_MAX__;
int find(int head,int tail,int sum){
    if(head>tail||tail>n+1)
        return 0;
    if(sum>=m){
        if(tail-head<len)
            len=tail-head;
        find(head+1,tail,sum-list[head]);
    }
    else
        find(head,tail+1,sum+list[tail]);
    return 0;
}
int main(){
    scanf("%d %d",&n,&m);
    for (int i = 1; i <= n; i++){
        scanf("%d",&list[i]);
        check+=list[i];
    }
    if(check<m)
        printf("0");
    else{
        find(0,0,0);
        printf("%d",len);
    }
    return 0;
}