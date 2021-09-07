#include<stdio.h>
int list[100001]={0,};
int max=-1001;
int main(){
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		scanf("%d",&list[i]);
	for (int i = n-1; i >= 0; i--)
	{
		if(i!=n-1&&list[i]<list[i]+list[i+1])
			list[i]=list[i]+list[i+1];
		if(max<list[i])
			max=list[i];
	}
	printf("%d",max);
	return 0;
}