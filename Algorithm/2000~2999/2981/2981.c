#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void*a, const void *b)
{
    return *(int*)a-*(int*)b;
}
int gcd(int x,int y)//great common divisor find
{
    int z=x%y;
    while(z){
        x=y;
        y=z;
        z=x%y;
    }
    return y;
}
int main()
{
    int n,list[102],temp,ans[10000];
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&list[i]);
    temp=abs(list[0]-list[1]);
    for (int i = 1; i < n-1; i++){
        temp=gcd(temp,abs(list[i]-list[i+1]));
    }
    ans[0]=temp;
    int cnt=1;
    for (int i = 2; i <= sqrt(temp); i++)
        if(temp%i==0){
            ans[cnt++]=i;
            if (temp/i!=i)
                ans[cnt++]=temp/i;
        }
    qsort(ans,cnt,sizeof(int),cmp);
    for (int i = 0; i < cnt; i++)
        printf("%d ",ans[i]);
    return 0;
}
/**
 * @brief 풀이
 * N개의 수를 입력받을 때, 입력되는 인접한 숫자에 대한 차들을 구한다.
 * (Ni번째 수를 입력받으면, Ni-N(i+1)를 구한다.)
 * 구한 수들의 차(절대값)들의 "최대공약수"를 구한 뒤, 최대공약수의 약수를 출력한다.
 * - 왜 입력된 수들의 '차' 들의 "최대공약수"를 구하는게 답을 찾을 키 포인트인가.
 * N개의 숫자를 입력받을 때, i 번째의 수를 N(i)라고 하자.
 * N(i-1)%m==N(i)%m이고, N(i)%m==N(i+1)%m 이다.
 * 두 식의 우변, 좌변을 0으로 만들면, N(i)%m-N(i-1)%m==0, N(i+1)%m-N(i)%m==0 이다.
 * mod 연산의 교환법칙에 의해, (N(i)-N(i-1))%m==0,(N(i+1)-N(i))%m==0 이고, 이는 (N(i)-N(i-1))%m==(N(i+1)-N(i))%m이라는 식을 만들어 낼 수 있다.
 * (N(i)-N(i-1))%m==(N(i+1)-N(i))%m에서, (N(i)-N(i-1))과 (N(i+1)-N(i))는 같을수 없기에, 식을 만족할 수 있는 두 수의 최대 공배수가 m값이 된다.
 */