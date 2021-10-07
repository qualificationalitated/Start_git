#include<stdio.h>
int main()
{
	int n,k,money[102]={0,},num[10002]={0,};
	scanf("%d %d",&n,&k);
	for (int i = 0; i < n; i++)
		scanf("%d",&money[i]);
	for (int i = 0; i < n; i++){
		if(money[i]<=k){
			num[money[i]]+=1;
			for (int j = money[i]+1; j<=k; j++)
				num[j]+=num[j-money[i]];
		}
	}
	printf("%d",num[k]);
	return 0;
}