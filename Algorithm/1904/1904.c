#include<stdio.h>
long long m[1000002]={0,1,2};
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 3; i <= n; i++)
        m[i]=(m[i-1]+m[i-2])%15746;
    printf("%lld",m[n]);
    return 0;
}
//그냥, 간단한 DP문제...