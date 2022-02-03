#include<stdio.h>
long long findnum(int e,int d)
{
    long long sum=0,num=d;
    while(e>=num){
        sum+=e/num;
        num=num*d;
    }
    //printf("[%d %d]\n",num,sum);
    return sum;
}
int main()
{
    int n,m;
    long long two,five;
    scanf("%d %d",&n,&m);
    two=findnum(n,2)-findnum(n-m,2)-findnum(m,2);//the number of two in n;
    five=findnum(n,5)-findnum(n-m,5)-findnum(m,5);//the number of five in n;
    if(two<five)
        printf("%lld",two);
    else
        printf("%lld",five);
    return 0;
}

/*
개념
정수를 2로 나눠가면서 소인수의 갯수를 찾는 것 -> 시간복잡도에 걸림.
하지만, 짜잔! 정수를 2의 배수로 나눈 것의 몫의 합 == 소인수 2의 갯수
빠르게 2와 5를 찾아 넘겨주기.
*/