#include<stdio.h>
#include<stdlib.h>
int main()
{
    long long n,m,head=0,tail=0;
    scanf("%lld %lld",&n,&m);
    long long tree[n+1];
    for (int i = 0; i < n; i++){
        scanf("%lld",&tree[i]);
        if(tail<tree[i])
            tail=tree[i];
    }
    long long mid,sum;
    while(head<=tail)
    {
        sum=0;
        mid=(head+tail)/2;
        for (int i = 0; i < n; i++)
            if(mid<tree[i])
                sum+=tree[i]-mid;
        if(sum>=m)
            head=mid+1;
        else
            tail=mid-1;
    }
    printf("%lld",tail);
    return 0;
}