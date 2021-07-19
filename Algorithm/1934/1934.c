#include<stdio.h>
int find(int a,int b)
{
    int result=0;
    while(a%b!=0)
    {
        result=a%b;
        a=b;
        b=result;
    }
    return b;
}
int main()
{
    int t;
    int a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",a*b/find(a,b));
    }
    return 0;
}