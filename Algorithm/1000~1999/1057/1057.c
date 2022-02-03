#include<stdio.h>
int main()
{
    int n,kjm,ihs,cnt=0,s,b;
    scanf("%d%d%d",&n,&kjm,&ihs);
    if(kjm<ihs){
        s=kjm;
        b=ihs;
    }
    else{
        s=ihs;
        b=kjm;
    }
    while(++cnt)
    {
        if(s/2==b/2-1&&b%2==0&&s%2==1){
            printf("%d",cnt);
            break;
        }
        s=(s+1)/2;
        b=(b+1)/2;
    }
    return 0;
}
