#include<stdio.h>
#include<string.h>
int main()
{
    char s[6]="a";
    int check=2;
    while(strlen(s)!=1||s[0]!='0')
    {
        if(check==1)
            printf("no\n");
        else if(check==0)
            printf("yes\n");
        check=0;
        scanf("%s",s);
        for (int i=0;i<strlen(s)/2;i++){
            if(s[i]!=s[strlen(s)-1-i])
                check=1;
        }
    }
    return 0;
}