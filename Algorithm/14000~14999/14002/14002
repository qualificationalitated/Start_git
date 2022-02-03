#include<stdio.h>
#define LIM 1002
int num[LIM],dp[LIM][2];
int find(int x)
{
    if(!dp[x][1])
        return printf("%d ",num[x]);
    find(dp[x][1]);
    return printf("%d ",num[x]);
}
int main()
{
    int n,aLen=0,loc=0;
    scanf("%d",&n);
    dp[1][0]=1; // 길이
    dp[1][1]=0; // 넘어온 위치
    for (int i = 1; i <= n; i++){
        int mLen=0;
        scanf("%d",&num[i]);
        for (int j = 1; j < i; j++)
            if(num[j]<num[i]){
                if(dp[j][0]>mLen){
                    mLen=dp[j][0];
                    dp[i][1]=j;
                }
            }
        dp[i][0]=mLen+1;
        if(dp[i][0]>aLen){
            aLen=dp[i][0];
            loc=i;
        }
    }
    printf("%d\n",aLen);
    find(loc);
    return 0;
}