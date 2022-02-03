#include<stdio.h>
int tower[500002][2],top=1,ans[500002],check=0;
int main()
{
    int n,h;
    scanf("%d",&n);
    scanf("%d",&tower[1][0]);
    tower[1][1]=1;
    for (int i = 2; i <= n; i++)
    {
        scanf("%d",&h);
        while(tower[top][0]<h&&top>0)
            top--;
        if(top){
            check=1;
            ans[i]=tower[top][1];
        }
        top++;
        tower[top][0]=h;
        tower[top][1]=i;
    }
    if(check)
        for (int i = 1; i <= n; i++)
            printf("%d ",ans[i]);
    else
        printf("0");
    
    return 0;
}