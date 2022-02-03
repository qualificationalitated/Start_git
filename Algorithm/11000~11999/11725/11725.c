#include<stdio.h>
int list[100002][20],cnt[100002]={0,},visit[100002];
int que[100002];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 1; i < n; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		list[a][cnt[a]++]=b;
		list[b][cnt[b]++]=a;
	}
	int head=0,tail=0;
	que[tail++]=1;
	visit[1]=1;
	while(head<tail){
		int now=que[head++];
		for (int i = 0; i < cnt[now]; i++)
		{
			int linked=list[now][i];
			if(!visit[linked]){
				visit[linked]=now;
				que[tail++]=linked;
			}
		}
	}
	for (int i = 2; i <= n; i++)
		printf("%d\n",visit[i]);
	return 0;
}