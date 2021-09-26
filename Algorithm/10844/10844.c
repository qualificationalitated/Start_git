#include<stdio.h>
int main() {

    int n,i,j;
    int possible[101][11] = { 0, };
    scanf("%d", &n);
    for(i = 0; i <= 9; i++) 
        possible[1][i] = 1;
    for(i = 2; i <= n; i++) {
        possible[i][0]=possible[i-1][1];
        possible[i][10]=0;
        for (j=0;j<=9;j++)
            possible[i][j]=(possible[i-1][j-1]+possible[i-1][j+1])%1000000000;
    }
    int sum=0;
    for (i = 1; i <= 9; i++)
        sum = (sum + possible[n][i]) % 1000000000;
    printf("%d\n", sum);
    return 0;
}