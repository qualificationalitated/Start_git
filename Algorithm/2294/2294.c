#include<stdio.h>
int main()
{
    int n,k,coin[102]={0,},make[10002]={0,};
    for (int i = 1; i < 10002; i++)
        make[i]=100000;
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&coin[i]);
        if(coin[i]<=k)
            for (int j = coin[i]; j <= k; j++)
                if(make[j]>make[j-coin[i]]+1)
                    make[j]=make[j-coin[i]]+1;
    }
    if(make[k]!=100000)
        printf("%d",make[k]);
    else
        printf("-1");
    return 0;
}