#include<stdio.h>
#include<stdlib.h>
int gear[4][8],move[4]={0,};
int rotate(int gNum,int dir){
    int temp;
    if(dir==1){//시계방향
        temp=gear[gNum][7];
        for (int i = 7; i > 0 ; i--)
            gear[gNum][i]=gear[gNum][i-1];
        gear[gNum][0]=temp;
    }
    else if(dir==-1){//반시계방향
        temp=gear[gNum][0];
        for (int i = 0; i < 7 ; i++)
            gear[gNum][i]=gear[gNum][i+1];
        gear[gNum][7]=temp;
    }
    return 0;
}
int l_check(int x,int dir){
    if(x<1)
        return 0;
    if(gear[x][6]!=gear[x-1][2]){
        move[x-1]=dir*-1;
        l_check(x-1,dir*-1);
    }
    return 0;
}
int r_check(int x,int dir){
    if(x>2)
        return 0;
    if(gear[x][2]!=gear[x+1][6]){
        move[x+1]=dir*-1;
        r_check(x+1,dir*-1);
    }
    return 0;
}
int check(int g, int dir){
    l_check(g,dir);
    r_check(g,dir);
    for (int i = 0; i < 4; i++)
        rotate(i,move[i]);
    return 0;
}
int main(){
    int t,ans=0,db=1;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 8; j++)
            scanf("%1d",&gear[i][j]);
    scanf("%d",&t);
    while(t--){
        int num,dir;
        for (int i = 0; i < 4; i++)
            move[i]=0;
        scanf("%d%d",&num,&dir);
        move[num-1]=dir;
        check(num-1,dir);
    }
    for (int i = 0; i < 4; i++) {
		if (gear[i][0] == 1)
			ans+=db;
		db*=2;
	}
    printf("%d",ans);
    return 0;
}