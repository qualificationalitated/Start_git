#include<stdio.h>
#include<stdlib.h>
int list[10],n,used[10]={0,},made[10]={0,};
int sum(int x){
    int r=0;
    for (int i = 0; i < x-1; i++)
        r+=abs(made[i+1]-made[i]);
    return r;
}
int make(int x){
    int max=0,r;
    if(x==n)
        return sum(x);
    for (int i = 0; i < n; i++)
        if(!used[i]){
            made[x]=list[i];
            used[i]=1;
            r=make(x+1);
            if(max<r)
                max=r;
            used[i]=0;
        }
    return max;
}
int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&list[i]);
    printf("%d",make(0));
    return 0;
}