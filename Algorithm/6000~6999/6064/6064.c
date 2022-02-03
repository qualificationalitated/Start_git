#include<stdio.h>
int find(int x,int y){
    int z;
    while(x%y)
    {
        z=x%y;
        x=y;
        y=z;
    }
    return y;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,n,x,y,r;
        scanf("%d%d%d%d",&m,&n,&x,&y);
        r=m*n/find(m,n);
        y=y%n;
        while(1){
            if(r<x){
                printf("-1\n");
                break;
            }
            if(y==x%n){
                printf("%d\n",x);
                break;
            }
            x=x+m;
        }
    }
    return 0;
}