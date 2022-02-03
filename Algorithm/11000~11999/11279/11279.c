#include<stdio.h>
int que[100002];
int main()
{
	int n,x,top=0;
	scanf("%d",&n);
	while(n--)
	{
		int temp,now;
		scanf("%d",&x);
		if(x)//양수
		{
			now=++top;
			while(now!=1&&x>que[now/2]){
				que[now]=que[now/2];
				now/=2;
			}
			que[now]=x;
		}
		else//0, 출력
		{
			if(top==0)
				printf("0\n");
			else{
				printf("%d\n",que[1]);
				que[1]=que[top--];
				now=1;
				int find;
				while(1)
				{
					find=now*2;
					if(find+1<=top&&que[find]<que[find+1])
						find++;
					if(find>top||que[find]<que[now])
						break;
					temp=que[now];
					que[now]=que[find];
					que[find]=temp;
					now=find;
				}
			}
		}
	}
	return 0;
}
