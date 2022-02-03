// https://www.acmicpc.net/problem/1966
// 프린터 큐
#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b)
{
    return *(int*)b-*(int*)a;
}
int main()
{
    int t,n,m,list[102]={0,},importance[102]={0,},priority,count;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&list[i]);
            importance[i]=list[i];
        }
        qsort(importance,n,sizeof(int),compare);
        ////
        priority=0;
        count=0;
        while(m>=0&&n)
        {
            if(list[0]==importance[priority])//que의 첫번째 값이 가장 중요한 값일경우
            {
                priority++;
                count++;
                if(!m){//만일 m이 첫번째 값일경우
                    printf("%d\n",count);
                    m--;
                }
                else{//m이 첫번째가 아니면, que를 회전시키고 que의 길이와, m의 위치를 최신화 한다,
                    int tmp=list[0];
                    for (int i = 0; i < n-1; i++)
                        list[i]=list[i+1];
                    list[n-1]=tmp;
                    n--;
                    m--;
                }
            }
            else
            {
                int tmp=list[0];
                    for (int i = 0; i < n-1; i++)
                        list[i]=list[i+1];
                    list[n-1]=tmp;
                if(m==0)
                    m=n-1;
                else
                    m--;
            }
        }
        ////
    }
    return 0;
}