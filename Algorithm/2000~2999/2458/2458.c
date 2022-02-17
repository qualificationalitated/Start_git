#include<stdio.h>
int map[502][502];
int main(){
    int n,m,ans=0;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        map[a][b]=1;
        map[b][a]=-1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++){
                if(i==j) map[i][j]=-2;
                if((!map[i][j])&&map[i][k]==1&&map[k][j]==1)
                    map[i][j]=1;
                if((!map[i][j])&&map[i][k]==-1&&map[k][j]==-1)
                    map[i][j]=-1;
            }
    for (int i = 1; i <= n; i++){
        int check=1;
        for (int j = 1; j <= n; j++)
            if(!map[i][j])
                check=0;
        ans+=check;
    }
    printf("%d",ans);
    return 0;
}