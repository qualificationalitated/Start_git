#include<stdio.h>
int que[200002]={0,},top=0;
int main()
{
    int n,h,t,gh,num;
    scanf("%d %d %d",&n,&h,&t);
    for (int i = 0; i < n; i++){
        scanf("%d",&num);
        int now=i;
        while(now>0&&que[(now-1)/2]<num){
            que[now]=que[(now-1)/2];
            now=(now-1)/2;
        }
        que[now]=num;
    }
    int check=0,size=n-1,cnt=0;
    for (int i = 0; i < t; i++)
    {
        if(que[0]<h)
            break;
        cnt++;
        if(que[0]>1)
            que[0]/=2;
        int loc=0,cmp;
        while(1)
        {
            cmp=loc*2+1;
            if(cmp+1<n&&que[cmp]<que[cmp+1])
                cmp++;
            if(cmp>n||que[loc]>que[cmp])
                break;
            int temp=que[cmp];
            que[cmp]=que[loc];
            que[loc]=temp;
            loc=cmp;
        }
    }
    if(que[0]<h)
        printf("YES\n%d",cnt);
    else
        printf("NO\n%d",que[0]);
    
    return 0;
}