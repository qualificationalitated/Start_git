#include<stdio.h>
int mapcheck(char map[51][51],int verticalS,int horizonS)
{
    int count=0,compare;
    for(int i=0;i<8;i++)//왼쪽 모서리 W
    {
        for(int j=0;j<=6;j+=2)
        {
            if(map[i+verticalS][j+horizonS+(i%2)]!='W')
            count++;
            if(map[i+verticalS][j+horizonS+((i+1)%2)]!='B')
            count++;
        }
    }
    compare=count;
    count=0;
    for(int i=0;i<8;i++)//왼쪽 모서리 B
    {
        for(int j=0;j<=6;j+=2)
        {
            if(map[i+verticalS][j+horizonS+(i%2)]!='B')
            count++;
            if(map[i+verticalS][j+horizonS+((i+1)%2)]!='W')
            count++;
        }
    }
    if(compare<count)
    return compare;
    else
    return count;
}
int main()
{
    int n,m,result=0,min=100;
    char map[51][51],temp;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s",map[i]);
        scanf("%c",&temp);
    }
    for(int i=0;i<=n-8;i++)
    {
        for(int j=0;j<=m-8;j++)
        {
            result=mapcheck(map,i,j);
            if(min>result)
            min=result;
        }
    }
    printf("%d",min);
    return 0;
}