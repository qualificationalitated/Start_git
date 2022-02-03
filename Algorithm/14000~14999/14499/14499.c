#include<stdio.h>
int map[22][22]={0,},mx[5]={0,0,0,-1,1},my[5]={0,1,-1,0,0};
typedef struct status{
    /*
      E
    C A D
      F
      B
    */
    int A,B,C,D,E,F;
}status;
status dice;
int setdice(){
    dice.A=0;
    dice.B=0;
    dice.C=0;
    dice.D=0;
    dice.E=0;
    dice.F=0;
    return 0;
}
int roll(int x){
    int temp;
    if(x==1){
        temp=dice.A;
        dice.A=dice.D;
        dice.D=dice.B;
        dice.B=dice.C;
        dice.C=temp;
    }
    else if(x==2){
        temp=dice.A;
        dice.A=dice.C;
        dice.C=dice.B;
        dice.B=dice.D;
        dice.D=temp;
    }
    else if(x==3){
        temp=dice.B;
        dice.B=dice.F;
        dice.F=dice.A;
        dice.A=dice.E;
        dice.E=temp;
    }
    else{
        temp=dice.E;
        dice.E=dice.A;
        dice.A=dice.F;
        dice.F=dice.B;
        dice.B=temp;
    }
    printf("%d\n",dice.B);
    return 0;
}
int main()
{
    setdice();
    int n,m,x,y,k,cmd;
    scanf("%d%d%d%d%d",&n,&m,&x,&y,&k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d",&map[i][j]);
    while(k--){
        scanf("%d",&cmd);
        int nx=x+mx[cmd],ny=y+my[cmd];
        if(0<=nx&&nx<n&&0<=ny&&ny<m)
        {
            roll(cmd);
            if(!map[nx][ny])
                map[nx][ny]=dice.A;
            else{
                dice.A=map[nx][ny];
                map[nx][ny]=0;
            }
            x=nx;
            y=ny;
        }
    }
    return 0;
}