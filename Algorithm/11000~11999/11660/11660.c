#include<stdio.h>
#define LIM 1025
int numArr[LIM][LIM]={0,};
int main()
{
    int n,m;
    int ax,ay,bx,by;
    scanf("%d %d",&n,&m);
    for (int i = 1; i <= n; i++){
        int columnSum=0,x;
        for (int j = 1; j <= n; j++)
        {
            scanf("%d",&x);
            columnSum+=x;
            numArr[i][j]=columnSum+numArr[i-1][j];
        }
    }
    while (m--){
        scanf("%d %d %d %d",&ax,&ay,&bx,&by);
        printf("%d\n",numArr[bx][by]+numArr[ax-1][ay-1]-numArr[bx][ay-1]-numArr[ax-1][by]);
    }
    return 0;
}