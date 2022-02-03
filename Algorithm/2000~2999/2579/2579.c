// https://www.acmicpc.net/problem/2579
#include<stdio.h>
int stair[302]={0,};
int sum[2][202]={0,},n;//sum[0][] - 연속 없이 따로 따로 올라감, sum[1][] - 연속해서 올라감, 다음은 무조건 2칸 가야됨
int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		scanf("%d",&stair[i]);
	sum[0][0]=stair[0];//1칸 올라가며 시작
	sum[0][1]=stair[1];//2칸 올라가며 시작
	sum[1][1]=stair[0]+stair[1];//1,2 올라가며 시작
	for (int i = 2; i < n; i++)
	{
		sum[0][i]=sum[0][i-2]+stair[i];
		sum[1][i]=sum[0][i-1]+stair[i];//이전값에서 바로 1칸 올라옴
		if(sum[0][i-2]<sum[1][i-2])//2칸 올라옴
			sum[0][i]=sum[1][i-2]+stair[i];//연속->2칸 or 연속X->2칸 비교, 더 큰거 선택
	}
	if(sum[0][n-1]<sum[1][n-1])
		printf("%d",sum[1][n-1]);
	else
		printf("%d",sum[0][n-1]);
	return 0;
}