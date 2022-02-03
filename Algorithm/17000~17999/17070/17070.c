#include<stdio.h>
int n,wall[18][18];//rot 0-가로 1-대각 2-세로
int mx[3]={0,1,1},my[3]={1,1,0},result=0;
int find(int x,int y,int r)
{
    if(x==n-1&&y==n-1){
        result++;
        return 0;
    }
    for (int i = 0; i < 3; i++)
    {
        if((r==0&&i==2)||(r==2&&i==0))
            continue;
        int nx=x+mx[i],ny=y+my[i];
        if(i==1&&(wall[nx][ny-1]||wall[nx-1][ny]))
            continue;
        if(nx<n&&ny<n&&wall[nx][ny]==0)
            find(nx,ny,i);
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d",&wall[i][j]);
    find(0,1,0);
    printf("%d",result);
}