#include<stdio.h>
int que[1502],top=0,n,m;
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&m);
		int loc=++top;
		while(loc>1&&m<que[loc/2]){
			que[loc]=que[loc/2];
			loc/=2;
		}
		que[loc]=m;
	}
	for (int i=0;i<n-1;i++)
		for (int j=0;j<n;j++){
			int loc=1,cmp,temp;
			scanf("%d",&m);
			if(que[1]<m){
				que[1]=m;
				while(1){
					cmp=loc*2;
					if(que[cmp]>que[cmp+1]&&cmp+1<=top) cmp++;
					if(cmp>top||que[loc]<que[cmp]) break;
					temp=que[loc];
					que[loc]=que[cmp];
					que[cmp]=temp;
					loc=cmp;
				}
			}
		}
	printf("%d",que[1]);
	return 0;
}