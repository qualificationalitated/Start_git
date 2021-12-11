#include<stdio.h>
int main()
{
    int n,map[50002];
    for (int i = 1; i <= 50000; i++)
        map[i]=i;
    scanf("%d",&n);
    for (int j = 2; j <= 223; j++){
        map[j*j]=1;
        for (int k = j*j+1; k <= 50000; k++)
            if(map[k]>map[k-(j*j)]+1)
                map[k]=map[k-(j*j)]+1;
    }
    printf("%d",map[n]);
    return 0;
}