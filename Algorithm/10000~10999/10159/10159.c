#include<stdio.h>
int wei[102][102]={0,};
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    while (m--){
        int a,b;
        scanf("%d %d",&a,&b);
        wei[a][b]=1;
        wei[b][a]=-1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if(wei[i][j]==0){
                    if(wei[i][k]==1&&wei[k][j]==1)
                        wei[i][j]=1;
                    else if(wei[i][k]==-1&&wei[k][j]==-1)
                        wei[i][j]=-1;
                }

    for (int i = 1; i <= n; i++){
        int ans=0;
        for (int j = 1; j <= n; j++)
            if(!wei[i][j])
                ans++;
        printf("%d\n",ans-1);
    }
    return 0;
}