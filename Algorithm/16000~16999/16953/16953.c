#include<stdio.h>
int main()
{
    int n,m,cnt=0;
    scanf("%d %d",&n,&m);
    while(1)
    {
        if(n>=m){
            if(n==m)
                printf("%d",cnt+1);
            else
                printf("-1");
            return 0;
        }
        if(m%2==0)
            m=m/2;
        else if(m%10==1)
            m=m/10;
        else{
            printf("-1");
            return 0;
        }
        cnt++;
    }
    return 0;
}