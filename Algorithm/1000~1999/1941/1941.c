#include<stdio.h>
int mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
int ans=0,lank= 1;
char gyosil[6][6];
int selected[5][5]={0,};
int visit[5][5]={0,};
int isitLink(int x, int y) {
	int deep = 1;
	visit[x][y]=lank;
	for (int i = 0; i < 4; i++) {
		int nx=x+mx[i];
		int ny=y+my[i];
		if (nx<0||ny<0||nx>=5||ny>= 5)
            continue;
        if(visit[nx][ny]==lank||selected[nx][ny]==0)
            continue;
		deep+=isitLink(nx, ny);
	}
	return deep;
}

int selectSeven(int index, int som, int cnt) {
	if(cnt==7) {
		if (som>=4 && isitLink((index-1)/5,(index-1)%5)==7)
            ans++;
		lank++;
		return 0;
	}
	for (int i = index; i < 25; i++) {
		int x=i/5,y=i%5;
		selected[x][y]=1;
		selectSeven(i+1,som+(gyosil[x][y]=='S'),cnt+1);
		selected[x][y]=0;
	}
    return 0;
}
int main() {
	for (int i = 0; i < 5; i++)
		scanf("%s", gyosil[i]);
	selectSeven(0,0,0);
	printf("%d", ans);
}