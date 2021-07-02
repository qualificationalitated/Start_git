#include<stdio.h>
int main()
{
    int n;
    double max=-1;
    double scoreList,sum=0,scoreNew;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf",&scoreList);
        sum+=scoreList;
        if(max<scoreList)
        max=scoreList;
    }
    scoreNew=(sum/max*100)/(double)n;
    printf("%.8g",scoreNew);
    return 0;
    //??? 소수저 자릿수 고려해서 해야되는 그런거 아니였나, 이게 왜되지
}