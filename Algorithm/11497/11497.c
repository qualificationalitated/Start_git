#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int main() {
	int t, n;
	scanf("%d",&t);
	while(t--){
        int n,l[10002];
		scanf("%d",&n);
		for (int i = 0; i < n; i++)
			scanf("%d",&l[i]);
		qsort(l,n,sizeof(int),cmp);
		int max = 0;
		for (int k = 2; k < n; k++) {
			if(max<l[k]-l[k-2])
			max=l[k]-l[k-2];
		}
		printf("%d\n",max);
	}
	return 0;
}