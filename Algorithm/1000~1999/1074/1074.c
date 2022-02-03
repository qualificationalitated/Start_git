#include<stdio.h>
int cnt=0;
int find(int len,int x,int y)
{
    if(len==2)
        printf("%d",cnt+x*2+y);
    else
        if(x<len/2&&y<len/2)
            find(len/2,x,y);
        else if(x<len/2&&len/2<=y){
            cnt+=len*len/4;
            find(len/2,x,y-len/2);
        }
        else if(len/2<=x&&y<len/2){
            cnt+=len*len/2;
            find(len/2,x-len/2,y);
        }
        else{
            cnt+=len*len/4*3;
            find(len/2,x-len/2,y-len/2);
        }
    return 0;
}
int main(){
    int n,r,c,rep=1,i;
    scanf("%d %d %d",&n,&r,&c);
    for (i=0;i<n;i++)
        rep*=2;
    find(rep,r,c);
    return 0;
}