#include<stdio.h>
int check(int n)
{
    int num[5]={0,},cnt=0,check;
    while(n!=0){
        num[cnt++]=n%10;
        n=n/10;
    }
    for (int i=1;i<cnt-1;i++)
        if(num[i]-num[i-1]!=num[i+1]-num[i])
            return 0;
    return 1;
}
int main()
{
    int n,list[1001]={0,};
    for (int i=1;i<=1000;i++)
    {
        if(i<=99) list[i]=i;
        else
            if(check(i))
                list[i]=list[i-1]+1;
            else
                list[i]=list[i-1];
    }
    scanf("%d",&n);
    printf("%d",list[n]);
    return 0;
}