// https://www.acmicpc.net/problem/1927
#include<stdio.h>
int heap[100002];
int main()
{
	int n,cmd,top=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&cmd);
		if(cmd)
		{
			int loc=++top;
			while(1<loc&&cmd<heap[loc/2]){
				heap[loc]=heap[loc/2];
				loc/=2;
			}
			heap[loc]=cmd;
		}
		else
		{
			if(top==0)
				printf("0\n");
			else{
			printf("%d\n",heap[1]);
			heap[1]=heap[top--];
			int loc=1,cmp;
			while(1)
			{
				cmp=loc*2;
				if(cmp+1<=top&&heap[cmp]>heap[cmp+1])
					cmp++;
				if(cmp>top||heap[loc]<heap[cmp])
					break;
				int temp=heap[cmp];
				heap[cmp]=heap[loc];
				heap[loc]=temp;
				loc=cmp;
			}
			}
		}
	}
	return 0;
}