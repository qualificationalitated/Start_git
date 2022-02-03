#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    char s[50]={0,},temp;
    int count,check;
    scanf("%d",&n);
    while(n--)
    {
        count=0;
        check=0;
        scanf("%s",s);
        for (int i=0;i<strlen(s);i++)
        {
            if(s[i]=='(')
                count++;
            else
                count--;
            if(count<0)
                check=1;
        }
        if(count==0&&check==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}