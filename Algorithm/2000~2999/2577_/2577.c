#include<stdio.h>
int main()
{
    int n;
    int calnum=1;
    int count[10]={0,};
    for (int i = 0; i < 3; i++)
    {
        scanf("%d",&n);
        calnum*=n;
    }
    while(calnum)
    {
        count[calnum%10]++;
        calnum=calnum/10;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n",count[i]);
    }
    
}