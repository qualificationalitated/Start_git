#include <stdio.h>
int main(){
    int n,m,cost = 0, count = 1;;
    int busTransperMap[101][101]={0,};
    int busTransperList[101]={0,};
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", &busTransperList[i]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &busTransperMap[i][j]);
    while(count!=m)
    for (int i = 1; i <= n; i++)
        if(i==busTransperList[count+1]){
            cost+=busTransperMap[busTransperList[count]][i];
            count++;
        }
    printf("%d",cost);
    return 0;
}