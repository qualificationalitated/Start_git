#include<stdio.h>
#define MOD 1000000000
int main(){
    int map[201][201]={0,},n,k,i,j;
    scanf("%d %d", &n, &k);
    for (i = 0; i <= n; i++)
        map[1][i]=1;
    for (i = 0; i <= k; i++)
        map[i][0]=1;
    for(i = 2; i <= k; i++)
        for (j = 1; j <= n; j++) 
            map[i][j]=(map[i][j-1]+map[i-1][j])%MOD;
    printf("%d\n", map[k][n]);
    return 0;
}