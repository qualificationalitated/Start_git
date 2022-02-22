#include<stdio.h>
#include<string.h>
int main(){
    char s[103]={0,},stack[103]={0,};
    int top=0;
    scanf("%s",s);
    for (int i = 0; i < strlen(s); i++)
    {
        if('A'<=s[i]&&s[i]<='Z')
            printf("%c",s[i]);
        else if(s[i]=='(')
            stack[++top]='(';
        else if(s[i]==')'){
            while(stack[top]!='(')
                printf("%c",stack[top--]);
            top--;
        }
        else{
            if(s[i]=='*'||s[i]=='/')
                while(top&&(stack[top]=='*'||stack[top]=='/'))
                    printf("%c",stack[top--]);
            else
                while(top&&stack[top]!='(')
                    printf("%c",stack[top--]);
            stack[++top]=s[i];
        }
    }
    while(top)
        printf("%c",stack[top--]);
    return 0;
}