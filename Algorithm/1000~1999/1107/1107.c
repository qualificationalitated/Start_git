#include<stdio.h>
int button[11];
int makeplus(int x){
    if (x<0)
        x*=-1;
    return x;
}
int length(int x)
{
    int len=0;
    if(x==0)
        if(button[0])
            return 0;
        else
            return 1;
    while(x){
        int temp=x%10;
        if(button[temp])
            return 0;
        x/=10;
        len+=1;
    }
    return len;
}
int main()
{
    int channel,broken,minmove;
    scanf("%d %d",&channel,&broken);
    for (int i = 0; i < broken; i++)
    {
        int num;
        scanf("%d",&num);
        button[num]=1;
    }
    minmove=makeplus(channel-100);
    for (int i=0;i<=1000000;i++)
    {
        int len=length(i);
        if(len)
            if(makeplus(i-channel)+len<minmove)
                minmove=makeplus(i-channel)+len;
    }
    printf("%d",minmove);
    return 0;
}