#include<stdio.h>
#define LIM 1002
int num[LIM]={0,},big[LIM]={0,},small[LIM]={0,};
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        int bGinn=0;
        scanf("%d",&num[i]);
        for (int j = 0; j < i; j++)
        {
            if(num[j]<num[i])
                bGinn=big[j]>bGinn?big[j]:bGinn;
        }
        big[i]=bGinn+1;
    }
    for (int i = n; i >= 1; i--){
        int sGinn=0;
        for (int j = n+1; j > i; j--)
        {
            if(num[j]<num[i])
                sGinn=small[j]>sGinn?small[j]:sGinn;
        }
        small[i]=sGinn+1;
    }
    for (int i = 1; i <= n; i++)
        ans=big[i]+small[i]>ans?big[i]+small[i]:ans;
    printf("%d",ans-1);
    
}