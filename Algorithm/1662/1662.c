#include<stdio.h>
#include<string.h>
int str,check=0;
char s[52];
int find(int x)
{
    int len=0;
    for (int i=x;i<str;i++)
    {
        if(s[i]=='(')
        {
            len=len-1+(s[i-1]-'0')*find(i+1);
            if(check){
                i=check;
                check=0;
            }
        }
        else if(s[i]==')'){
            check=i;
            return len;
        }
        else
            len++;
    }
    return len;
}
int main()
{
    scanf("%s",s);
    str=strlen(s);
    printf("%d",find(0));
    return 0;
}