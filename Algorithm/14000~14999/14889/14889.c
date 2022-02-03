#include<stdio.h>
int s[21][21],visit[21]={0,},min=200,aT[11],bT[11],c;
int team(int n,int start,int count)
{
    int r,c,st1=0,st2=0;
    if(count>n/2-1)
    {
        c=0;
        for (int i=0;i<n;i++)
            if(!visit[i])
                bT[c++]=i;
        for (int i=0;i<count;i++)
            for (int j=i+1;j<count;j++)
            {
                st1+=s[aT[i]][aT[j]]+s[aT[j]][aT[i]];
                st2+=s[bT[i]][bT[j]]+s[bT[j]][bT[i]];
            }
        r=st1-st2;
        if(r<0) r=r*-1;
        if (min>r) min=r;
        return 0;
    }
    for (int i=start;i<n;i++){
        if(visit[i]==0)
        {
            visit[i]=1;
            aT[count++]=i;
            team(n,i+1,count);
            count--;
            visit[i]=0;
        }
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            scanf("%d",&s[i][j]);
    team(n,0,0);
    printf("%d",min);
    return 0;
}