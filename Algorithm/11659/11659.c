#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m,*list,*sum,a,b;
	scanf("%d %d",&n,&m);
	list=(int*)malloc(sizeof(int)*(n+1));
	sum=(int*)malloc(sizeof(int)*(n+1));
	scanf("%d",&list[1]);
	sum[0]=0;
	sum[1]=list[1];
	for (int i=2;i<=n;i++){
		scanf("%d",&list[i]);
		sum[i]=sum[i-1]+list[i];
	}
	while(m--){
		scanf("%d %d",&a,&b);
		printf("%d\n",sum[b]-sum[a-1]);
	}
	return 0;
}