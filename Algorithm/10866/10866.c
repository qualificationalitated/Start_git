#include<stdio.h>
int d[20002]={0,};
int main()
{
    int h=10000,t=9999;
    char s[12];
    scanf("%d",&d[20001]);
    while(d[20001]--){
    scanf("%s",s);
    if(s[0]=='p'){
        if(s[5]=='f')
            scanf("%d",&d[--h]);
        else if(s[5]=='b')
            scanf("%d",&d[++t]);
        else if(s[5]=='r')
            if(h<=t)
                printf("%d\n",d[h++]);
            else
                printf("-1\n");
        else if(s[5]=='a')
            if(h<=t)
                printf("%d\n",d[t--]);
            else
                printf("-1\n");
    }
    else if(s[0]=='s')
        printf("%d\n",t-h+1);
    else if(s[0]=='e')
        if(h<=t)
            printf("0\n");
        else
            printf("1\n");
    else if(s[0]=='f')
        if(h<=t)
            printf("%d\n",d[h]);
        else
            printf("-1\n");
    else if(s[0]=='b')
        if(h<=t)
            printf("%d\n",d[t]);
        else
            printf("-1\n");
    }
    return 0;
}