#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int n,p[100002],mixed,ans[2];
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&p[i]);
    qsort(p,n,sizeof(int),cmp);
    mixed=abs(p[0]+p[n-1]);
    ans[0]=p[0];
    ans[1]=p[n-1];
    int head=0,tail=n-1,mix;
    while(1){
        if(head>=tail)
            break;
        mix=abs(p[head]+p[tail]);
        if(mix<mixed){
            ans[0]=p[head];
            ans[1]=p[tail];
            mixed=mix;
        }
        if(!mix)
            break;
        if(abs(p[head])>abs(p[tail]))
            head++;
        else
            tail--;
    }
    printf("%d %d",ans[0],ans[1]);
    return 0;
}