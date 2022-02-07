#include<stdio.h>
#define LIM 100002
int list[LIM][20],cnt[LIM]={0,},visit[LIM],que[LIM];
int main()
{
	int n,head=0,tail=1;
	scanf("%d",&n);
	for (int i = 1; i < n; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		list[a][cnt[a]++]=b;
		list[b][cnt[b]++]=a;
	}
	que[0]=1;
	visit[1]=1;
	while(head<tail){
		int now=que[head++];
		for (int i = 0; i < cnt[now]; i++){
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