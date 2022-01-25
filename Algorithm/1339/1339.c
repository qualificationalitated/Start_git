#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool isUsedAlpha[26]={0,};
int alphaToNum[26]={0,};
int inNum[11]={0,},usingalpha[11]={0,},ualcnt=0;
int setnumber[10]={0,},setalpha[11]={0,};
int n,ans=0;
char input[11][10];
int changeStringToNum(){
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        inNum[i]=0;
        int ten=1;
        for(int j=strlen(input[i])-1;j>=0;j--){
            inNum[i]+=alphaToNum[input[i][j]-'A']*ten;
            ten*=10;
        }
        sum+=inNum[i];
    }
    ans=sum>ans?sum:ans;
    return 0;
}
int find(int x,int cnt){
    if(cnt==ualcnt)
        return changeStringToNum();
    for (int i = 0; i < ualcnt; i++)
        if(!setalpha[i]){
            setalpha[i]=x;
            alphaToNum[usingalpha[i]]=x;
            find(x-1,cnt+1);
            setalpha[i]=0;
            alphaToNum[usingalpha[i]]=0;
        }
    return 0;
}
int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s",input[i]);
        for (int j = 0; j < strlen(input[i]); j++)
        {
            int x=input[i][j]-'A';
            if(!isUsedAlpha[x]){
                isUsedAlpha[x]=true;
                usingalpha[ualcnt++]=x;
            }
        }
    }
    find(9,0);
    printf("%d",ans);
    return 0;
}