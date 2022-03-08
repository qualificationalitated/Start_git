#include<stdio.h>
int marble[101][101]={0,};
int main(){
    int n,m,ans=0;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < m; i++){
        int b,s;
        scanf("%d %d",&b,&s);
        marble[b][s]=1;
        marble[s][b]=-1;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j&&marble[i][j]==0)
                    if(marble[i][k]==-1&&marble[k][j]==-1)
                        marble[i][j]=-1;
                    else if(marble[i][k]==1&&marble[k][j]==1)
                        marble[i][j]=1;
    for(int i=1;i<=n;i++){
        int bigger=0,smaller=0;
        for(int j=1;j<=n;j++)
            if(marble[i][j])
                marble[i][j]==1?bigger++:smaller++;
        if(bigger<=n/2&&smaller<=n/2)
            ans++;
    }
    printf("%d",n-ans);
    return 0;
}