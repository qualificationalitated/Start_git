#include<stdio.h>
int main()
{
    int n[10]={0,},m;
    scanf("%d",&m);
    while(m!=0){
        n[m%10]++;
        m=m/10;
    }
    for (int i=9;i>=0;i--)
        if(n[i])
            for (int j=0;j<n[i];j++)
                printf("%d",i);
    return 0;
}