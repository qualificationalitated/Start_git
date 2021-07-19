#include<stdio.h>
#include<string.h>
int main()
{
    char s[105],stack[105]={0,};
    int top,error;
    while(strlen(s)!=1||s[0]!='.')
    {
        top=0;
        error=0;
        gets(s);
        for (int i=0;i<strlen(s);i++)
        {
            if (s[i]=='('||s[i]=='[')
                stack[++top]=s[i];
            else if (s[i]==')'||s[i]==']'){
                if((s[i]==')'&&stack[top]=='[')||(s[i]==']'&&stack[top]=='('))
                    error=1;
                top--;
                if(top<0){
                    top=0;
                    error=1;
                }
            }
        }
        if(strlen(s)!=1||s[0]!='.'){
            if(error||top>0)
                printf("no\n");
            else
                printf("yes\n");
        }
    }
    return 0;
}