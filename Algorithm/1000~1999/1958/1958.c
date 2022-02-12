#include<stdio.h>
#include<string.h>
#define MLEN 102
int max(int x,int y,int z){
    int ans=x>y?x:y;
    return ans>z?ans:z;
}
int dp[MLEN][MLEN][MLEN]={0,};
int main()
{
    char strA[MLEN],strB[MLEN],strC[MLEN];
    scanf("%s %s %s",strA,strB,strC);
    int lenA=strlen(strA),lenB=strlen(strB),lenC=strlen(strC);
    for (int i = 1; i <= lenA; i++)
        for (int j = 1; j <= lenB; j++)
            for (int k = 1; k <= lenC; k++)
                if(strA[i-1]==strB[j-1]&&strB[j-1]==strC[k-1])
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                else
                    dp[i][j][k]=max(dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1]);
    printf("%d",dp[lenA][lenB][lenC]);
    return 0;
}