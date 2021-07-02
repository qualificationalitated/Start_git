#include<stdio.h>
int main()
{
    int a=1,b=1,c=1;
    int check;
    while(1)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a!=0&&b!=0&&c!=0){
        if(a>b&&a>c)
            check=a*a-(b*b+c*c);
        else if(b>a&&b>c)
            check=b*b-(a*a+c*c);
        else
            check=c*c-(a*a+b*b);
        
        if(!check)
            printf("right\n");
        else
            printf("wrong\n");
        }
        else
        return 0;
    }
    return 0;
}