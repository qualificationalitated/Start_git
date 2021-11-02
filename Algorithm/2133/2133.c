#include<stdio.h>
long long int tile[32];
int main()
{
    int n;
    scanf("%d",&n);
    tile[2]=3;
        for (int i = 4; i <= n+1; i+=2)
        {
            tile[i]=tile[i-2]*3;
            for (int j = 4; j <= i; j+=2)
                tile[i]+=tile[i-j]*2;
            tile[i]+=2;
        }
    printf("%lld",tile[n]);
    return 0;
}