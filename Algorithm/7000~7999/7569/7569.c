#include<stdio.h>
int box[102][102][102];
int que[1000002][3];
int mx[6]={1,0,-1,0,0,0},my[6]={0,1,0,-1,0,0},mz[6]={0,0,0,0,1,-1};
int count[3]={0,};//-1 0 1 순으로 갯수 확인
int main()
{
    int m,n,h,max=0;
    int head=0,tail=1;
    scanf("%d%d%d",&m,&n,&h);
    for (int i = 0; i < h; i++)//높이
        for (int j = 0; j < n; j++)//행
            for (int k = 0; k < m; k++){//열
                scanf("%d",&box[i][j][k]);
                count[box[i][j][k]+1]+=1;
                if(box[i][j][k]==1){
                    que[tail][0]=i;//높이
                    que[tail][1]=j;//행
                    que[tail][2]=k;//열
                    tail++;
                }
            }
    if(count[0]+count[2]==m*n*h){
        printf("0");
        return 0;
    }
    if(count[0]+count[1]==m*n*h){// <- 이거 없으면 에러남, 왜지? -1로만 채워진거도 못익힌다고 보는건가
        printf("-1");
        return 0;
    }
    while(head<tail){
        int nx,ny,nz;
        head++;
        for (int i = 0; i < 6; i++)
        {
            nz=que[head][0]+mz[i];
            ny=que[head][1]+my[i];
            nx=que[head][2]+mx[i];
            if(0<=nz&&0<=ny&&0<=nx&&nz<h&&ny<n&&nx<m&&box[nz][ny][nx]==0)
            {
                count[1]--;
                box[nz][ny][nx]=box[que[head][0]][que[head][1]][que[head][2]]+1;
                if(max<box[nz][ny][nx])
                    max=box[nz][ny][nx];
                que[tail][0]=nz;//높이
                que[tail][1]=ny;//행
                que[tail][2]=nx;//열
                tail++;
            }
        }
    }
    if(!count[1])
        printf("%d",max-1);
    else
        printf("-1");
    return 0;
}