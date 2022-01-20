#include<stdio.h>
#include<stdlib.h>
typedef struct grid{
    int x,y;
}grid;
int n,r,l,map[52][52],mx[4]={1,0,-1,0},my[4]={0,1,0,-1},ans=0;
int main(){
    scanf("%d%d%d",&n,&l,&r);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&map[i][j]);
    while(1){
        int check[52][52]={0,},moved=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                int h=0,t=0,df,sum=0;
                grid q[2500],A,B;
                if(!check[i][j]){
                    q[t].x=i;
                    q[t].y=j;
                    t++;
                    while(h<t){
                        A=q[h++];
                        sum+=map[A.x][A.y];
                        check[A.x][A.y]=1;
                        for (int i=0;i<4;i++){
                            B.x=A.x+mx[i];
                            B.y=A.y+my[i];
                            df=abs(map[A.x][A.y]-map[B.x][B.y]);
                            if(0<=B.x&&B.x<n&&0<=B.y&&B.y<n&&check[B.x][B.y]==0&&l<=df&&df<=r){
                                check[B.x][B.y]=1;
                                q[t++]=B;
                            }
                        }
                    }
                    if(t>1) moved=1;
                    for(int i=0;i<t;i++)
                        map[q[i].x][q[i].y]=sum/t;
                }
            }
        if(moved) ans++;
        else break;
    }
    printf("%d",ans);
    return 0;
}