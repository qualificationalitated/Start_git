#include<stdio.h>
int list,num[202]={0,},ans=0;
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int max=0;
        scanf("%d",&list);
        for (int j = 0; j < list; j++)
        {
            if(max<num[j])
                max=num[j];
        }
        num[list]=max+1;
        if(ans<max+1)
            ans=max+1;
    }
    printf("%d",n-ans);
    return 0;
}