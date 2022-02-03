#include<stdio.h>
#include<string.h>
#define LEN 1000003
char input[LEN],bomb[38],ans[LEN];
int ansLen=0;
int main(){
    scanf("%s",input);
    scanf("%s",bomb);
    int bombLen=strlen(bomb),inputLen=strlen(input);
    for (int i = 0; i < inputLen; i++){
        ans[ansLen++]=input[i];
        if(ansLen<bombLen)  continue;
        if(ans[ansLen-1]==bomb[bombLen-1]){
            int isExploded=1;
            for (int j = 0; j < bombLen; j++)
                if(ans[ansLen-bombLen+j]!=bomb[j])
                    isExploded=0;
            if(isExploded)
                ansLen=ansLen-bombLen;
        }
    }
    ans[ansLen]='\0';
    if(ansLen)
        printf("%s",ans);
    else
        printf("FRULA");
    return 0;
}