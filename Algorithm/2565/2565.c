// https://www.acmicpc.net/problem/2565
#include <stdio.h>
int pole[502],pos[502];
int main()
{
	int n,m=0,ans=0,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		pole[a]=b;
		if(m<a)
			m=a;
	}
	for(i=1;i<=m;i++)
		if(pole[i]){
			int max=0;
			for(j=i-1;j>0;j--)
				if(pole[j]<pole[i]&&max<pos[j])
					max=pos[j];
			pos[i]=max+1;
			if(ans<pos[i])
				ans=pos[i];
		}
	printf("%d",n-ans);
	return 0;
}