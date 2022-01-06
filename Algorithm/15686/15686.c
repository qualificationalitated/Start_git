#include<stdio.h>
typedef struct grid{
    int x,y;
}grid;
int map[52][52],m,n,cNum=0,hNum=0,mx[4]={1,0,-1,0},my[4]={0,1,0,-1},ans=__INT_MAX__;
grid kyochon[2502],home[2502];
int findChickenDistance(){
    int sum=0;
    for (int i = 0; i < hNum; i++){
        int visit[52][52]={0,},h=0,t=1;
        grid a,b,que[2500];
        que[0]=home[i];
        while(h<t){
            a=que[h++];
            if(map[a.x][a.y]==3){ //nearist chicken is found
                sum+=visit[a.x][a.y];
                break;
            }
            for (int i = 0; i < 4; i++){
                b.x=a.x+mx[i];
                b.y=a.y+my[i];
                if(0<=b.x&&b.x<n&&0<=b.y&&b.y<n&&visit[b.x][b.y]==0){
                    que[t++]=b;
                    visit[b.x][b.y]=visit[a.x][a.y]+1;
                }
            }
        }
    }
    if(ans>sum)
        ans=sum;
    return 0;
}
int selectChicken(int loc,int cnt){
    if(cnt==m){
        findChickenDistance();
        return 0;
    }
    for (int i = loc; i < cNum; i++){
        map[kyochon[i].x][kyochon[i].y]=3; //selected chicken=3
        selectChicken(i+1,cnt+1);
        map[kyochon[i].x][kyochon[i].y]=2;
    }
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            scanf("%d",&map[i][j]);//치킨집 2, 집 1, 빈공간 0
            if(map[i][j]==1){
                home[hNum].x=i;
                home[hNum].y=j;
                hNum++;
            }
            if(map[i][j]==2){
                kyochon[cNum].x=i;
                kyochon[cNum].y=j;
                cNum++;
            }
        }
    selectChicken(0,0);
    printf("%d",ans);
    return 0;
}