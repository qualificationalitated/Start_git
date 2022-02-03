#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char noL[500001][23];
char both[500001][23];
char noH[23];
int sort(const void *a, const void *b)
{
	return strcmp((char *)a,(char *)b);
}
int main()
{
	int n,m,cnt=0;
	scanf("%d %d",&n,&m);
	for (int i = 0; i < n; i++)
		scanf("%s",noL[i]);
	qsort(noL,n,sizeof(noL[0]),sort);
	for (int j = 0; j < m; j++)
	{
		scanf("%s",noH);
		int head=0,tail=n-1;
		while(head<=tail)
		{
			int mid=(head+tail)/2,check;
			check=strcmp(noL[mid],noH);
			if(!check){
				strcpy(both[cnt++],noH);
				break;
			}
			else if(check>0)
				tail=mid-1;
			else
				head=mid+1;
		}
	}
	printf("%d\n",cnt);
	qsort(both,cnt,sizeof(both[0]),sort);
	for (int k = 0; k < cnt; k++)
		printf("%s\n",both[k]);
	
	return 0;
}
/*
strcmp 반환값은 -101이 아니라, 음 0 양이다
*/