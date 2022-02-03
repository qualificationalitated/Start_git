#include<stdio.h>
typedef struct grid{
    int x,y;
}grid;
int check=1,ans=0,mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
char map[14][8];
int main()
{
    for (int i = 0; i < 12; i++)
        scanf("%s",map[i]);
    while(check){
        check=0;
        //visit배열 생성 및 초기화
        int visit[13][7]={0,};
        for (int i = 0; i < 12; i++)
            for (int j = 0; j < 6; j++)
                //방문하지 않은 뿌요 탐색
                if(map[i][j]!='.'&&visit[i][j]==0){
                    grid que[100],now,next;
                    int head=0,tail=1;
                    visit[i][j]=1;
                    que[0].x=i;
                    que[0].y=j;
                    //BFS로 같은 색의 뿌요가 얼만큼 인접해있는지 확인하기
                    while(head<tail){
                        now=que[head++];
                        for (int k = 0; k < 4; k++){
                            next.x=now.x+mx[k];
                            next.y=now.y+my[k];
                            if(0<=next.x&&next.x<12&&0<=next.y&&next.y<6){
                                if(map[next.x][next.y]==map[now.x][now.y]&&visit[next.x][next.y]==0){
                                    visit[next.x][next.y]=1;
                                    que[tail++]=next; 
                                }
                            }
                        }
                    }
                    //tail이 4 이상? -> 같은 블록이 4개 이상, que 배열에 아직 좌표가 남아 있으니 재 탐색 없이 que 내부 좌표를 0으로 만들기
                    if(4<=tail){
                        check=1;
                        for (int k = 0; k < tail; k++)
                            map[que[k].x][que[k].y]='.';
                    }
                }
        //모두 다 부서지면 중력의 영향을 받도록 함, 한칸 한칸씩 떨어트리기
        for (int j = 0; j < 6; j++)
            while(1){
                int fall=0;
                for (int i = 11; i >=1 ; i--)
                    if(map[i][j]=='.'&&map[i-1][j]!='.'){
                        map[i][j]=map[i-1][j];
                        map[i-1][j]='.';
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