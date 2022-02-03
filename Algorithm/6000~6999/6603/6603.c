#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int k,s[15],visit[50],ans[7];
int cmp(const void *a, const void *b){
	return *(int*)a-*(int*)b;
}
int find(int now,int len){
	if(len==6){
		for (int i = 0; i < 6; i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	for (int i = now; i < k; i++)
		if(visit[s[i]]==0){
			ans[len]=s[i];
			visit[s[i]]=1;
			find(i,len+1);
			visit[s[i]]=0;
		}
	return 0;
}
int main()
{
	scanf("%d",&k);
	while(k)
	{
		memset(visit,0,50);
		for(int i=0;i<k;i++)
			scanf("%d",&s[i]);
		qsort(s,k,sizeof(int),cmp);
		find(0,0);
		printf("\n");
		scanf("%d",&k);
	}
	return 0;
}