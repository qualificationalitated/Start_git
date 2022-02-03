#include<stdio.h>
int sum(int n){
    int m=n;
    while(n>0){
        m+=n%10;
        n=n/10;
    }
    return m;
}
int main()
{
    int number[10100]={0,};
    for(int i=1;i<=10000;i++)
        number[sum(i)]=1;
    for(int i=1;i<=10000;i++)
        if(number[i]==0)
            printf("%d\n",i);
    return 0;    
}
