#include<stdio.h>
int n,m,ans=0,count=0;
char p[1000003];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",p);
	for (int i = 0; i < m-2; i++)
	{
		if(p[i]=='I'&&p[i+1]=='O'&&p[i+2]=='I')
		{
			count++;
			if(count==n){
				ans++;
				count--;
			}
			i++;
		}
		else
			count=0;
	}
	printf("%d",ans);
	return 0;
}