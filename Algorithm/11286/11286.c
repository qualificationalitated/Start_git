//https://www.acmicpc.net/problem/11286
#include<stdio.h>
int heap[100002];
int ab(int x)
{
	if(x<0)
		return x*-1;
	return x;
}
int main()
{
	int n,cmd,top=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&cmd);
		if(cmd){
			int loc=++top;
			while(1<loc && (ab(cmd)<ab(heap[loc/2]) || (ab(cmd)==ab(heap[loc/2])&&cmd<heap[loc/2]))){
				heap[loc]=heap[loc/2];
				loc/=2;
			}
			heap[loc]=cmd;
		}
		else
		{
			if(top==0)
				printf("0\n");
			else
			{
				printf("%d\n",heap[1]);
				heap[1]=heap[top--];
				int loc=1,cmp;
				while(1)
				{
					cmp=loc*2;
					if(cmp+1<=top&&(ab(heap[cmp])>ab(heap[cmp+1])||(ab(heap[cmp])==ab(heap[cmp+1])&&heap[cmp]>heap[cmp+1])))
						cmp++;
					if(cmp>top||ab(heap[loc])<ab(heap[cmp])||(ab(heap[loc])==ab(heap[cmp])&&heap[loc]<=heap[cmp]))
						break;
					int temp=heap[loc];
					heap[loc]=heap[cmp];
					heap[cmp]=temp;
					loc=cmp;
				}
			}
		}
	}
	return 0;
}