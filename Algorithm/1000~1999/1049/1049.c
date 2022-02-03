#include<stdio.h>
int sells[52],sello[52];
int mins=__INT_MAX__,mino=__INT_MAX__;
int main()
{
    int n,m,s=0,min=__INT_MAX__,rep;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < m; i++){
        scanf("%d %d",&sells[i],&sello[i]);
        if(mins>sells[i]) mins=sells[i];
        if(mino>sello[i]) mino=sello[i];
    }
    rep=n/6+1;
    for (int i = 0; i <= rep; i++)
    {
        if(n<0) n=0;
        if(min>n*mino+s*mins)
            min=n*mino+s*mins;
        n-=6;
        s++;
    }
    printf("%d",min);
    return 0;
}