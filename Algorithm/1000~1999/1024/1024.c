#include<stdio.h>
int sum(int s,int l){
    int r=0,i;
    for(i=0;i<l;i++){
        r+=s;
        s++;
    }
    return r;
}
int main()
{
    int n,l,s,i;
    scanf("%d%d",&n,&l);
    s=n/l;
    while(l<=100&&s>=0)
    {
        int ans=sum(s,l);
        if(ans==n){
            for(i=0;i<l;i++)
                printf("%d ",s+i);
            return 0;
        }
        else if(ans>n)
            s--;
        else{
            l++;
            s=n/l;
        }
    }
    printf("-1");
    return 0;
}