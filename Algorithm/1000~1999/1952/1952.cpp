#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int m,n,cnt=0;
    scanf("%d %d",&m,&n);
    n++;
    while(1){
        n--;
        if(!n)
            break;
        cnt++;
        m--;
        if(!m)
            break;
        cnt++;

    }
    printf("%d",cnt-1);
    return 0;
}