#include<stdio.h>
int stack[1000002][2],check[1000002],n,m,top=0,i;
int answer(int loc,int x){
    while(stack[top][0]<x&&top>0){
        check[stack[top][1]]=x;
        top--;
    }
    return 0;
}
int main()
{
    stack[0][0]=__INT_MAX__;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&m);
        if(stack[top][0]<m)
            answer(i,m);
        stack[++top][0]=m;
        stack[top][1]=i;
    }
    for(i=1;i<=n;i++){
        if(!check[i])
            check[i]=-1;
        printf("%d ",check[i]);
    }
    return 0;
}