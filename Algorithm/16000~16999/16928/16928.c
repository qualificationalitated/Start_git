#include<stdio.h>
int map[102],visit[102],que[10000];
int main()
{
	int n,m,a,b;
	scanf("%d %d",&n,&m);
	for (int i = 0; i < n+m; i++){
		scanf("%d %d",&a,&b);
		map[a]=b;
	}
	int now=1,head=0,tail=1,min=__INT_MAX__;
	while(head<tail)
	{
		if(now==100){
			printf("%d",visit[100]);
			return 0;
		}
		for (int i = 1; i <= 6; i++)
		{
			int next=now+i;
			if(map[next]&&visit[map[next]]==0)//안 가본 사다리를 찾았다면
			{
				visit[map[next]]=visit[now]+1;
				que[tail++]=map[next];
			}
			else if(map[next]==0&&visit[next]==0&&next<=100)
			{
				visit[now+i]=visit[now]+1;
				que[tail++]=now+i;
			}
		}
		now=que[++head];
		printf("[%d %d]\n",now,visit[now]);
	}
	return 0;
}