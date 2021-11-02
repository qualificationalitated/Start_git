#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,coin[22],gaesu[10002]={0,};
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
            scanf("%d",&coin[i]);
        scanf("%d",&m);
        for (int i = 0; i < n; i++)
        {
            if(coin[i]<=m){
                gaesu[coin[i]]+=1;
                for (int j = coin[i]+1; j <= m; j++)
                {
                    gaesu[j]=gaesu[j]+gaesu[j-coin[i]];
                }
            }
        }
        printf("%d\n",gaesu[m]);
    }
    return 0;
}