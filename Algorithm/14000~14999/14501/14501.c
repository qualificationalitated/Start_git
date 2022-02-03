#include<stdio.h>
int main()
{
    int n,time[17]={0,},money[17]={0,},ans=0;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d",&time[i],&money[i]);
    for (int i = n; i > 0; i--)
    {
        if(i+time[i]>n+1)
            money[i]=money[i+1];
        else
            if(money[i+1]>money[i]+money[i+time[i]])
                money[i]=money[i+1];
            else
                money[i]=money[i]+money[i+time[i]];
        if(ans<money[i])
            ans=money[i];
    }
    printf("%d",ans);
    return 0;
}