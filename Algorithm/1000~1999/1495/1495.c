#include<stdio.h>
int n,s,m,v,find[52][1002];
int main()
{
    scanf("%d%d%d",&n,&s,&m);
    find[0][s]=1;
    for(int i = 1; i <= n; i++)
    {
        int check=0;
        scanf("%d",&v);
        for (int j = 0; j < 1002; j++){
            if(find[i-1][j]){
                if(j+v<=m){
                    find[i][j+v]=1;
                    check=1;
                }
                if(j-v>=0){
                    find[i][j-v]=1;
                    check=1;
                }
            }
        }
        if (!check){
            printf("-1");
            return 0;
        }
    }
    int ans=0;
    for (int i = 0; i < 1002; i++)
        if(find[n][i])
            ans=i;
    printf("%d",ans);
    return 0;
}