#include<stdio.h>
int main()
{
    char a;
    int charCount=0,before=0;
    while(a!='\n'){
        scanf("%c",&a);
        if(a==' '||a=='\n'){
            if(before){
                charCount++;
            }
            before=0;
        }
        else before=1;
    }
    printf("%d",charCount+before);
    return 0;
}