#include<stdio.h>
#include<stdlib.h>
typedef struct score{
    int paper;
    int meet;
}score;
score list[100002];
int cmp(const void *a, const void *b)
{
    score *numa=(score*)a;
    score *numb=(score*)b;
    return numa->paper-numb->paper;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,cnt=1,hire=0;
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
            scanf("%d %d",&list[i].paper,&list[i].meet);
        qsort(list,n,sizeof(score),cmp);
        for (int i = 1; i < n; i++)
        {
            if(list[i].meet<list[hire].meet){
                cnt++;
                hire=i;
            }
        }
        printf("%d\n",cnt);
        
    }
    return 0;
}