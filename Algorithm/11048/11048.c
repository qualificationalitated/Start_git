#include <stdio.h>
int map[1001][1001],find[1001][1001],mx[3]={1,0,1},my[3]={0,1,1};
int main(void){
 
    int n, m;
    scanf("%d %d",&n,&m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &map[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            int ans = 0;
            for (int k = 0; k < 3; k++)
            {
                if(ans<find[i-mx[k]][j-my[k]])
                    ans=find[i-mx[k]][j-my[k]];
            }
            find[i][j] = ans + map[i][j];
        }
    printf("%d\n", find[n][m]);
}