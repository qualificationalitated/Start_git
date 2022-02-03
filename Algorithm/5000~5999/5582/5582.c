#include<stdio.h>
#include<string.h>
int map[4002][4002]={0,},max=0;
int main()
{
    char sA[4002],sB[4002];
    scanf("%s %s",sA,sB);
    for (int i = 1; i <= strlen(sB); i++){
        for (int j = 1; j <= strlen(sA); j++){
            if(sA[j-1]==sB[i-1])
                map[i][j]=map[i-1][j-1]+1;
            if(map[i][j]>max)
                max=map[i][j];
        }
    }
    printf("%d",max);
    return 0;
}