#include<stdio.h>
#include<string.h>
int xLen=0,xCnt=0;
char str[52];
int fillup(int e,int x,char c){
    for (int i=e-x+1;i<=e;i++)
        str[i]=c;
    return 0;
}
int main()
{
    scanf("%s",str);
    for (int i = 0; i < strlen(str) ; i++){
        str[i]-'X'?xLen=0:xLen++;
        if(xLen&&xLen%4==0) fillup(i,4,'A');
        else if(xLen&&xLen%2==0) fillup(i,2,'B');
    }
    for (int i = 0; i < strlen(str) ; i++)
        if(str[i]=='X'){
            printf("-1");
            return 0;
        }
    printf("%s",str);
    return 0;
}