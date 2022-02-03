#include<stdio.h>
char map[22][22];
int r,c,alpha[27],mx[4]={1,0,-1,0},my[4]={0,1,0,-1},max=0;
int find(int x,int y,int len)
{
    if(max<len)
        max=len;
    int nx,ny;
    for (int i = 0; i < 4; i++)
    {
        nx=x+mx[i];
        ny=y+my[i];
        if(0<=nx&&0<=ny&&nx<r&&ny<c&&alpha[map[nx][ny]-65]==0)
        {
            alpha[map[nx][ny]-65]=1;
            find(nx,ny,len+1);
            alpha[map[nx][ny]-65]=0;
        }
    }
    return 0;
}
int main()
{
    scanf("%d %d",&r,&c);
    for (int i = 0; i < r; i++){
        scanf("%s",map[i]);
    }
    alpha[map[0][0]-65]=1;
    find(0,0,1);
    printf("%d",max);
    return 0; 
}