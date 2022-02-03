#include<stdio.h>
int num[10002]={0,},ans[10],n,m;
int find(int loc){
	if(loc==m){
		for (int i = 0; i < loc; i++)
			printf("%d ",ans[i]);
		printf("\n");
		return 0;
	}
	for (int i = 0; i < 10002; i++)
		if(num[i]){
			ans[loc]=i;
			num[i]--;
			find(loc+1);
			num[i]++;
		}
	return 0;
}
int main()
{
	scanf("%d %d",&n,&m);
	for (int i = 0; i < n; i++){
		int x;
		scanf("%d",&x);
		num[x]++;
	}
	find(0);
	return 0;
}