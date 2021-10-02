#include<stdio.h>
int n,len,newOil,usingOil;
long long money=0,distance[100002];
int main()
{
	scanf("%d",&n);
	for (int i = 1; i < n; i++){
		scanf("%d",&len);
		distance[i]+=len+distance[i-1];//구간별 길이 누적
	}
	scanf("%d",&usingOil);
	money=usingOil*distance[n-1];//초기 비용 설정
	for (int i = 2; i <= n; i++)
	{
		scanf("%d",&newOil);
		if(newOil<usingOil)//지금 쓰고있는 기름보다 더 싼 기름 찾을시, 초기비용에서 감소
		{
			money-=(distance[n-1]-distance[i-1])*(usingOil-newOil);
			usingOil=newOil;//더 싼 기름으로 바꾸기
		}
	}
	printf("%lld",money);
	return 0;
}