#include<stdio.h>
int main()
{
    int n,sum=0;
    char a[100],b;
    scanf("%d",&n);
    scanf("%c",&b);
    scanf("%s",a);
    for(int i=0;i<n;i++){
        sum+=a[i]-'0';
    }
    printf("%d",sum);
    return 0;
}