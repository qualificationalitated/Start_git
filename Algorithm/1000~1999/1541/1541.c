#include<stdio.h>
#include<string.h>
int main()
{
    char s[100],latestCal='+';
    int num[100]={0,},numloc=0,cnt=0,i,j;
    scanf("%s",s);
    int len=strlen(s);
    for(i=0;i<=len;i++)
        if(s[i]=='+'||s[i]=='-'||i==len)
        {
            int ten=1,r=0;
            for(j=i-1;j>= numloc;j--){//숫자 만들기
                r+=(s[j]-'0')*ten;
                ten*=10;
            }
            if (i!=len){
                latestCal=s[i];
                numloc=i+1;
                num[cnt]+=r;
                if(s[i]=='-')
                    cnt++;
            }
            else {
                if(latestCal=='+')
                    num[cnt]+=r;
                else
                    num[++cnt]+=r;   
            }
        }
    for(i=1;i<=cnt;i++)
        num[0]-=num[i];
    printf("%d",num[0]);
    return 0;
}