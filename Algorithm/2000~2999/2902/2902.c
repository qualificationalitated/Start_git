#include<stdio.h>
#include<string.h>
int main()
{
    char s[103];
    char out[53];
    int c=0;
    scanf("%s",s);
    for (int i = 0; i < strlen(s); i++)
    {
        if(s[i]>=65&&s[i]<=90)
            out[c++]=s[i];
    }
    for (int i = 0; i < c; i++)
    {
        printf("%c",out[i]);
    }
    return 0;
}