#include<stdio.h>
int goods[102][2];
int wei[100002];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; i++)
        scanf("%d %d",&goods[i][0],&goods[i][1]);
    for (int i = 0; i < n; i++)
        for (int j = k; j > 0; j--)
            if(j>=goods[i][0])
                if(wei[j]<wei[j-goods[i][0]]+goods[i][1])
                    wei[j]=wei[j-goods[i][0]]+goods[i][1];
    printf("%d",wei[k]);
    return 0;
}