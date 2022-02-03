#include<stdio.h>
#include<string.h>
char strA[1002],strB[1002];
int dp[1002][1002],lenA,lenB;
int print(int B,int A)
{
    if(dp[B][A]==0)
        return 0;
    if(strB[B-1]==strA[A-1])
    {
        print(B-1,A-1);
        printf("%c",strB[B-1]);
    }
    else
        if(dp[B-1][A]>dp[B][A-1])
            print(B-1,A);
        else
            print(B,A-1);
    return 0;
}
int main()
{
    scanf("%s%s",strA,strB);
    lenA=strlen(strA);
    lenB=strlen(strB);
    for (int i = 1; i <= lenB; i++)
        for (int j = 1; j <= lenA; j++)
            if(strB[i-1]==strA[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else{
                dp[i][j]=dp[i-1][j];
                if(dp[i-1][j]<dp[i][j-1])
                    dp[i][j]=dp[i][j-1];
            }
    printf("%d\n",dp[lenB][lenA]);
    print(lenB,lenA);
    return 0;
}