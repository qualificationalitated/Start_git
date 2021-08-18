#include<stdio.h>
#include<stdlib.h>
typedef struct time{//회의 시작, 끝.
    int start,end;
}time;
int n,count=0,endpoint=0;
time *meeting;
int compare(const void *m1,const void *m2)//정렬
{
    time *a=(time *)m1;
    time *b=(time *)m2;
    if(a->end==b->end)
        return a->start-b->start;//종료시간이 같으면 시작이 빠른게 먼저.
    else
        return a->end-b->end;// 아니라면, 종료시간이 빠른쪽으로.
}
int main()
{
    int i;
    scanf("%d",&n);
    meeting=(time*)malloc(sizeof(time)*n);
    for(i=0;i<n;i++)
        scanf("%d %d",&meeting[i].start,&meeting[i].end);
    qsort(meeting,n,sizeof(time),compare);//종료시간 및 시작시간별로 정렬
    for (i=0;i<n;i++){
        if(endpoint<=meeting[i].start){//현 시점에서 가장 빨리 끝나는 회의를 찾기.
            endpoint=meeting[i].end;
            count++;
        }
    }
    printf("%d",count);
    return 0;
}