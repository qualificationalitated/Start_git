#include<stdio.h>
int wuri[100002][3];
int main()
{
    int n;
    scanf("%d",&n);
    wuri[1][0]=1;
    wuri[1][1]=2;
    wuri[1][2]=wuri[1][0]+wuri[1][1];
    for (int i = 2; i <= n; i++)
    {
        wuri[i][0]=wuri[i-1][2];
        wuri[i][1]=wuri[i-1][0]+wuri[i][0];
        wuri[i][2]=(wuri[i][0]+wuri[i][1])%9901;
    }
    printf("%d",wuri[n][2]);
    return 0;
}