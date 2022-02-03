#include<stdio.h>
#include<stdlib.h>
typedef struct number{
	int score;
	int number;
}num;
int cmpS(const void *a, const void *b)
{
	num *A=(num*) a;
	num *B=(num*) b;
	return B->score-A->score;
}
int cmpI(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int sum=0,ans[5];
	num list[8];
	for (int i = 0; i < 8; i++){
		scanf("%d",&list[i].score);
		list[i].number=i;
	}
	qsort(list,8,sizeof(num),cmpS);
	for (int i = 0; i < 5; i++){
		sum+=list[i].score;
		ans[i]=list[i].number+1;
	}
	printf("%d\n",sum);
	qsort(ans,5,sizeof(int),cmpI);
	for (int i = 0; i < 5; i++)
	{
		printf("%d ",ans[i]);
	}
	
	return 0;
}