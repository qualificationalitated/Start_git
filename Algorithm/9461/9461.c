#include<stdio.h>
long long rec[101]={1,1,1,2,2,};
int main()
{
	for (int i = 5; i <= 100; i++)
		rec[i]=rec[i-1]+rec[i-5];
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%lld\n",rec[n-1]);
	}
	return 0;
}