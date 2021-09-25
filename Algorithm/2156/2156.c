#include<stdio.h>
int main()
{
    int n,max;
    scanf("%d",&n);
    int wine[n+1],drink[n+1][2];//drink[][0]-> 새로 마시기 drink[][1]-> 2번 연속 마시기
    scanf("%d",&wine[0]);
    drink[0][0]=wine[0];
    drink[0][1]=wine[0];
    max=wine[0];
    for (int i = 1; i < n; i++)
    {
        scanf("%d",&wine[i]);
        //지금까지 봤을때, 연속으로 마시는 최대값 찾기
        drink[i][1]=drink[i-1][0]+wine[i];
        if(drink[i-1][0]+wine[i]<drink[i-1][1])
            drink[i][1]=drink[i-1][1];
        
        if(i==1)
            drink[1][0]=wine[1];
        else {
            int sum=drink[i-2][0];
            if(drink[i-2][0]<drink[i-2][1])
                sum=drink[i-2][1];
            //지금까지 봤을때, 지금 값을 새로 한타임 마셨을때의 최대값 찾기.
            drink[i][0]=sum+wine[i];
            if(sum+wine[i]<drink[i-1][0])
                drink[i][0]=drink[i-1][0];
        }
        for (int j = 0; j < 2; j++)
            if(max<drink[i][j])
                max=drink[i][j];
    }
    printf("%d",max);
    return 0;
}