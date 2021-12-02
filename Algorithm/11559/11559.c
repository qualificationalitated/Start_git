#include<stdio.h>
int map[13][7],visit[13][7]={0,},check=1,ans=0;
int mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
char s[8];
int main()
{
    for (int i = 0; i < 12; i++){
        scanf("%s",s);
        for (int j = 0; j < 6; j++)
            if(s[j]=='R') map[i][j]=1;
            else if(s[j]=='G') map[i][j]=2;
            else if(s[j]=='B') map[i][j]=3;
            else if(s[j]=='P') map[i][j]=4;
            else if(s[j]=='Y') map[i][j]=5;
            else map[i][j]=0;
    }
    while(check)
    {
        check=0;
        //visit배열 초기화
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 6; j++)
                visit[i][j]=0;
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 6; j++)
                //탐색하며 부숴지는게 있는지 판단
                if(map[i][j]&&visit[i][j]==0){
                    int head=0,tail=1,que[100][2];
                    visit[i][j]=1;
                    que[head][0]=i;
                    que[head][1]=j;
                    //BFS 활용해서 부수기
                    while(head<tail){
                        int x=que[head][0],y=que[head][1],nx,ny;
                        head++;
                        for (int k = 0; k < 4; k++){
                            nx=x+mx[k];
                            ny=y+my[k];
                            if(0<=nx&&nx<12&&0<=ny&&ny<6&&map[nx][ny]==map[x][y]&&visit[nx][ny]==0){
                                visit[nx][ny]=1;
                                que[tail][0]=nx;
                                que[tail][1]=ny;
                                tail++;
                                
                            }
                        }
                    }
                    //tail이 4 이상? -> 같은 블록이 4개 이상, que 배열에 아직 좌표가 남아 있으니 재 탐색 없이 que 내부 좌표를 0으로 만들기
                    if(4<=tail){
                        check=1;
                        for (int k = 0; k < tail; k++)
                            map[que[k][0]][que[k][1]]=0;
                    }
                }
        //모두 다 부서지면 중력의 영향을 받도록 함, 한칸 한칸씩 떨어트리기
        for (int j = 0; j < 6; j++)
            while(1){
                int fall=0;
                for (int i = 11; i >=1 ; i--)
                    if(map[i][j]==0&&map[i-1][j]!=0){
                        map[i][j]=map[i-1][j];
                        map[i-1][j]=0;
                        fall=1;
                    }
                if(!fall)
                    break;
            }
        ans++;
    }
    printf("%d",ans-1);
    return 0;
}