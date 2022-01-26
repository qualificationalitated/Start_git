#include<stdio.h>
#define LIM 102
int n,map[LIM][LIM],goAble[LIM][LIM];
int find(int x,int now){
	for (int i = 0; i < n; i++)
		if(map[now][i]&&(!goAble[x][i])){
			goAble[x][i]=1;
			find(x,i);
		}
	return 0;
}
int main(){
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d",&map[i][j]);
	for (int i = 0; i < n; i++)
		find(i,i);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			printf("%d ",goAble[i][j]);
		printf("\n");
	}
	return 0;
}