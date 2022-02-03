#include<stdio.h>
#include<string.h>
int que[2000001],head=0,tail=0;
int main()
{
    int n,m;
    char command[7];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",command);
        if(!strcmp(command,"push")){
            scanf("%d",&m);
            que[++tail]=m;
        }
        else if(!strcmp(command,"pop"))
            if(head<tail)
                printf("%d\n",que[++head]);
            else
                printf("-1\n");
        else if(!strcmp(command,"size"))
            printf("%d\n",tail-head);
        else if(!strcmp(command,"empty"))
            if(head==tail)
                printf("1\n");
            else
                printf("0\n");
        else if(!strcmp(command,"front"))
            if(head<tail)
                printf("%d\n",que[head+1]);
            else
                printf("-1\n");
        else if(!strcmp(command,"back"))
            if(head<tail)
                printf("%d\n",que[tail]);
            else
                printf("-1\n");
    }
    return 0;
}