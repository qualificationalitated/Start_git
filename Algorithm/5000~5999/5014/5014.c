#include<stdio.h>
int t[1000002],q[1000002];
int main()
{
    int f,s,g,u,d;
    scanf("%d%d%d%d%d",&f,&s,&g,&u,&d);
    int h=0,T=0;
    t[s]=1;
    while(h<=T){
        if(s==g)
            break;
        if(s+u<=f&&t[s+u]==0){
            q[T++]=s+u;
            t[s+u]=t[s]+1;
        }
        if(s-d>0&&t[s-d]==0){
            q[T++]=s-d;
            t[s-d]=t[s]+1;
        }
        s=q[h++];
    }
    if(t[g])
        printf("%d",t[g]-1);
    else
        printf("use the stairs");
    return 0;
}