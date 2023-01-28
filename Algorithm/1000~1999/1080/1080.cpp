#include<cstdio>
#define MAX 51
char befArr[MAX][MAX], aftArr[MAX][MAX];
int flip(int r, int c){
	for(int i=r;i<r+3;i++)
		for(int j=c;j<c+3;j++)
			befArr[i][j] = !(befArr[i][j]-'0') + '0';
	return 1;
}
bool isSame(int r, int c){
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			if(befArr[i][j]!=aftArr[i][j])  return false;
	return true;
}
int main(){
	int n,m,cnt=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)	scanf("%s",befArr[i]);
	for(int i=0;i<n;i++)	scanf("%s",aftArr[i]);
	for(int i=0;i<n-2;i++)
		for(int j=0;j<m-2;j++)
			if(befArr[i][j]!=aftArr[i][j])	cnt+=flip(i,j);
	if(isSame(n,m)) printf("%d",cnt);
	else printf("-1");
	return 0;
}