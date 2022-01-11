#include<stdio.h>
#include<string.h>
#define MOD 1000000
long long int dp[5002]={0,};
int main(){
    char s[5002];
    scanf("%s",s);
    int len=strlen(s);
    if(s[0]!='0'){
        dp[1]=1;
        dp[0]=1;
        for (int i = 2; i <= len; i++)
        {
            int num=(s[i-2]-'0')*10+(s[i-1]-'0');
            if(s[i-1]!='0')
                dp[i]=(dp[i]+dp[i-1])%MOD;
            if(10<=num&&num<=26)
                dp[i]=(dp[i]+dp[i-2])%MOD;
        }
    }
    printf("%d",dp[len]);
    return 0;
}