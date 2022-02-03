#include<stdio.h>
int numList[100002]={0,};
int main()
{
    int k,n,top=0;
    long long sum=0;
    scanf("%d",&k);
    for (int i=0;i<k;i++)
    {
        scanf("%d",&n);
        if(n!=0){
            top++;
            numList[top]=n;
            sum+=n;
        }
        else{
            sum=sum-numList[top];
            top--;
        }
    }
    printf("%lld\n",sum);
    return 0;
}