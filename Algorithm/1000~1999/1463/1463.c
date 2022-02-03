#include<stdio.h>
int list[1000002]={0,};
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		list[i]=list[i-1]+1;//3번규칙
		if(i%2==0)//만일 2로 나눠지면,
			if(list[i]>list[i/2]+1)//2로 나누는게 1 뺴는것보다 적은 횟수라면
				list[i]=list[i/2]+1;
		if(i%3==0)
			if(list[i]>list[i/3]+1)//3으로 나누는게 1 뺴는것보다 적은 횟수라면
				list[i]=list[i/3]+1;
	}
	printf("%d",list[n]);
	return 0;
}