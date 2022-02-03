#include<stdio.h>
int n,ans=0;
int queen[200][2],num=0;
int attack(int x,int y,int queenNum)//공격 당하지 않을 적합한 위치인가?
{
    for (int i=0;i<queenNum; i++)
        if(queen[i][0]==x||queen[i][1]==y||queen[i][0]+queen[i][1]==x+y||queen[i][0]-queen[i][1]==x-y)
            return 1;
    return 0;
}
int find(int stx,int x)
{
    if(x==n){
        ans++;
        return 0;
    }
    for (int j=0;j<n;j++)
        if(attack(stx,j,x)==0){
            queen[x][0]=stx;
            queen[x][1]=j;
            find(stx+1,x+1);
        }
    return 0;
}
int main()
{
    scanf("%d",&n);
    find(0,0);
    printf("%d",ans);
    return 0;
}