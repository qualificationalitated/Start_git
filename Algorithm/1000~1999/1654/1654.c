#include<stdio.h>
int main()
{
    int k,n,kList[10001]={0,};
    unsigned long long start=1,end=0,sum=0,mid,max=0;
    scanf("%d %d",&k,&n);
    for (int i=0;i<k;i++){
        scanf("%d",&kList[i]);
        end+=kList[i];
    }
    end=end/n;
    while(start<=end)
    {
        sum=0;
        mid=(start+end)/2;
        for (int i=0;i<k;i++)
            sum+=kList[i]/mid;
        if(sum>=n){
            start=mid+1;
            if(mid>max)
            max=mid;
        }
        else if(sum<n)
            end=mid-1;
    }
    printf("%lld",max);
    return 0;
}