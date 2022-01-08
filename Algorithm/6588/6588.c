#include<stdio.h>
int numList[1000002]={0,1,},holsu[100000],hGaesu=0,t,n;
int sosu(int x,int end){
    for (int i = 2; i <= end; i++)
        numList[x*i]=1;
    return 0;
}
int main()
{
    for (int i = 2; i <= 1000; i++)
        if(!numList[i])
            sosu(i,1000000/i);
    for (int i = 2; i <= 1000000; i++)
        if(numList[i]==0&&i%2)
            holsu[hGaesu++]=i;
    while(1){
        scanf("%d",&n);
        if(!n)
            return 0;
        for (int i = 0; i < hGaesu; i++)
        {
            if(holsu[i]>n)
                break;
            if(!numList[n-holsu[i]]){
                printf("%d = %d + %d\n",n,holsu[i],n-holsu[i]);
                break;
            }
        }   
    }
}