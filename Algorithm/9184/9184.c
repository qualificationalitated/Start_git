#include<stdio.h>
int num[22][22][22];
int w(int a,int b,int c)
{
    if(a<=0||b<=0||c<=0)
        return 1;
    else if(a>20||b>20||c>20)
        return w(20,20,20);
    if(num[a][b][c])
        return num[a][b][c];
    else
    {
        if(a<b&&b<c)
            num[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
        else
            num[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    }
    return num[a][b][c];
}
int main()
{
    int a,b,c;
    while(1)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a==b&&b==c&&c==-1)
            return 0;
        printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
    }
}