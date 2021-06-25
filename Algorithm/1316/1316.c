#include<stdio.h>
#include<string.h>
int main()
{
    int n,check[26]={0,},count=0,countb=0;
    char input[101];
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s",input);
        check[input[0]-97]++;
        for (int j=1;j<strlen(input);j++)
        {
            if(input[j]!=input[j-1])
            {
                check[input[j]-97]++;
            }
        }
        for(int k=0;k<26;k++)
        {
            if (check[k]>=2)
            {
                count=1;
            }
            check[k]=0;
        }
        countb+=count;
        count=0;
    }
    printf("%d",n-countb);
    return 0;
}