#include<stdio.h>
int n,map[2189][2189];
int zero=0,minus=0,plus=0;
int find(int x,int y,int r)
{
	int check[3]={0,};
	for (int i = x; i < x+r; i++)
		for (int j = y; j < y+r; j++)
			check[map[i][j]+1]++;
	if(check[0]==r*r)//-1
		minus++;
	else if(check[1]==r*r)//0
		zero++;
	else if(check[2]==r*r)//1
		plus++;
	else{//네 귀퉁이 찾기
		r=r/3;
		find(x,y,r);
		find(x+r,y,r);
		find(x+2*r,y,r);
		find(x,y+r,r);
		find(x+r,y+r,r);
		find(x+2*r,y+r,r);
		find(x,y+2*r,r);
		find(x+r,y+2*r,r);
		find(x+2*r,y+2*r,r);
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d",&map[i][j]);
	find(0,0,n);
	printf("%d\n%d\n%d",minus,zero,plus);
	return 0;
}