#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int que[10002],from[10002]={0,};
bool visit[10002];
char move[10002],answer[100];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,h=0,t=1,now,next;
		memset(visit,false,sizeof(visit));
		scanf("%d %d",&a,&b);
		que[0]=a;
		from[a]=0;
		visit[a]=true;
		while(h<t)
		{
			now=que[h];
			if(now==b){
				int len=0;
				while(now!=a){
					answer[len++]=move[now];
					now=from[now];
				}
				for (int i=len-1;i>= 0;i--)
					printf("%c",answer[i]);
				printf("\n");
				break;
			}
			next=(now*2)%10000;
			if(!visit[next]){
				visit[next]=true;
				que[t++]=next;
				from[next]=now;
				move[next]='D';
			}
			next=now-1;
			if(next==-1)
				next=9999;
			if(!visit[next]){
				visit[next]=true;
				que[t++]=next;
				from[next]=now;
				move[next]='S';
			}
			next=(now%1000)*10 + now/1000;
			if(!visit[next]){
				visit[next]=true;
				que[t++]=next;
				from[next]=now;
				move[next]='L';
			}
			next=(now%10)*1000 + now/10;
			if(!visit[next]){
				visit[next]=true;
				que[t++]=next;
				from[next]=now;
				move[next]='R';
			}
			h++;
		}
	}
	return 0;
}