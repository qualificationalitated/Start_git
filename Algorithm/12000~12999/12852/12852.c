#include<stdio.h>
#define LIM 1000002
int map[LIM],route[LIM];
int find(int n)
{
    map[1]=0;
    for (int i = 2; i <= n; i++)
    {
        map[i]=map[i-1]+1;
        route[i]=i-1;
        if(i%3==0&&map[i]>map[i/3]+1){
                map[i]=map[i/3]+1;
                route[i]=i/3;
            }
        if (i%2==0&&map[i]>map[i/2]+1){
                map[i]=map[i/2]+1;
                route[i]=i/2;
            }
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    find(n);
    printf("%d\n",map[n]);
    while(1)
    {
        printf("%d ",n);
        n=route[n];
        if(!n)
            break;
    }
    return 0;
}