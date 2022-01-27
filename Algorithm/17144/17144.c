#include<stdio.h>
typedef struct grid{
    int x,y;
}grid;
int map[52][52],dustCounter,refresher[2],rfs,ans=0;
grid dust[2502];
int refreshing(int r,int c){
    int i;
    // upside circulate
    for (i = refresher[0]; i > 0; i--)
        map[i][0]=map[i-1][0];
    ans-=map[refresher[0]][0];
    map[refresher[0]][0]=0;
    for (i = 0; i < c-1 ; i++)
        map[0][i]=map[0][i+1];
    for (i = 0; i < refresher[0] ; i++)
        map[i][c-1]=map[i+1][c-1];
    for (i = c-1; i > 0; i--)
        map[refresher[0]][i]=map[refresher[0]][i-1];
    // downside circulate
    for (i = refresher[1]; i < r-1; i++)
        map[i][0]=map[i+1][0];
    ans-=map[refresher[1]][0];
    map[refresher[1]][0]=0;
    for (i = 0; i < c-1 ; i++)
        map[r-1][i]=map[r-1][i+1];
    for (i = r-1; i > refresher[1]-1 ; i--)
        map[i][c-1]=map[i-1][c-1];
    for (i = c-1; i > 0; i--)
        map[refresher[1]][i]=map[refresher[1]][i-1];
    dustCounter=0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++){
            if(map[i][j]){
                dust[dustCounter].x=i;
                dust[dustCounter].y=j;
                dustCounter++;
            }
        }
    return 0;
}
int spreadDust(int r,int c){
    grid now,next;
    int mx[4]={1,0,-1,0},my[4]={0,1,0,-1},nextmap[52][52]={0,};
    for (int cnt = 0; cnt < dustCounter; cnt++){
        now=dust[cnt];
        int spreadedCount=0,devidedDust=map[now.x][now.y]/5;
        for (int i = 0; i < 4; i++)
        {
            next.x=now.x+mx[i];
            next.y=now.y+my[i];
            if(next.x<0||r<=next.x||next.y<0||c<=next.y)
                continue;
            if((next.x==refresher[0]||next.x==refresher[1])&&next.y==0)
                continue;
            nextmap[next.x][next.y]+=devidedDust;
            spreadedCount++;
        }
        nextmap[now.x][now.y]+=map[now.x][now.y]-(spreadedCount*devidedDust);
    }
    ans=0;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++){
            map[i][j]=nextmap[i][j];
            ans+=nextmap[i][j];
        }
    return 0;
}
int main()
{
    int r,c,t;
    scanf("%d %d %d",&r,&c,&t);
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            scanf("%d",&map[i][j]);
            if(map[i][j]>0){
                dust[dustCounter].x=i;
                dust[dustCounter].y=j;
                dustCounter++;
            }
            if(map[i][j]==-1)
                refresher[rfs++]=i;
        }
    while(t--){
        spreadDust(r,c);
        refreshing(r,c);
    }
    printf("%d\n",ans);
    return 0;
}