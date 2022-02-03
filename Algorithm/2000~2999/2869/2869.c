/*
 *2869번 달팽이는 올라가고 싶다.
*/
#include<stdio.h>
#include<math.h>
int main()
{
    double oneday,a,b,v;
    int count=0;
    scanf("%lf %lf %lf",&a,&b,&v);
    oneday=a-b;
    count=ceil((v-a)/oneday);
    printf("%d",count+1);
    return 0;
}