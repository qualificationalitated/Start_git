//https://www.acmicpc.net/problem/11286
#include<stdio.h>
#include<stdlib.h>
int heap[100002],n,cmd,top=0;;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&cmd);
		if(cmd){
			int loc=++top;
			while(1<loc && (abs(cmd)<abs(heap[loc/2]) || (abs(cmd)==abs(heap[loc/2])&&cmd<heap[loc/2]))){
				heap[loc]=heap[loc/2];
				loc/=2;
			}
			heap[loc]=cmd;
		}
		else{
			if(top){
				printf("%d\n",heap[1]);
				heap[1]=heap[top--];
				int loc=1,cmp;
				while(1){
					cmp=loc*2;
					if(cmp+1<=top&&(abs(heap[cmp])>abs(heap[cmp+1])||(abs(heap[cmp])==abs(heap[cmp+1])&&heap[cmp]>heap[cmp+1])))
						cmp++;
					if(cmp>top||abs(heap[loc])<abs(heap[cmp])||(abs(heap[loc])==abs(heap[cmp])&&heap[loc]<=heap[cmp]))
						break;
					int temp=heap[loc];
					heap[loc]=heap[cmp];
					heap[cmp]=temp;
					loc=cmp;
				}
			}
			else printf("0\n");
		}
	}
	return 0;
}