#include<stdio.h>
int n,m[130][130],i,j;
int wS=0,bS=0;
int f(int x,int y,int r)
{
	int s=0;
	for(i=x;i<x+r;i++)
		for(j=y;j<y+r;j++)
			s+=m[i][j];
	if(!s)
		wS++;//white
	else if(s==r*r)
		bS++;//blue
	else{//네 귀퉁이 찾기
		f(x,y,r/2);
		f(x+r/2,y,r/2);
		f(x,y+r/2,r/2);
		f(x+r/2,y+r/2,r/2);
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&m[i][j]);
	f(0,0,n);
	printf("%d\n%d",wS,bS);
	return 0;
}