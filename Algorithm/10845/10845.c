//https://www.acmicpc.net/problem/10845
#include<stdio.h>
#include<string.h>
int main()
{
    int n,m,head=0,tail=0,que[10001]={0,};
    char command[6];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",command);
        if(!strcmp(command,"push")){
            scanf("%d",&m);
            que[tail++]=m;
        }
        else if(!strcmp(command,"pop"))
        {
            if(head<tail)
            {
                printf("%d\n",que[head++]);
            }
            else
            printf("-1\n");

        }
        else if(!strcmp(command,"size"))
        {
            printf("%d\n",tail-head);
        }
        else if(!strcmp(command,"empty"))
        {
            if(head<tail)
                printf("0\n");
            else
                printf("1\n");
        }
        else if(!strcmp(command,"front"))
        {
            if(head<tail)
                printf("%d\n",que[head]);
            else
                printf("-1\n");
        }
        else if(!strcmp(command,"back"))
            if(head<tail)
                printf("%d\n",que[tail-1]);
            else
                printf("-1\n");
    }
    return 0;
}