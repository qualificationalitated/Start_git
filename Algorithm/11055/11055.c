#include<stdio.h>
int num[1002];
int main(){
    int n,m,mmax=0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&m);
        int max=0;
        for (int i = 1; i < m; i++)
        {
            if(max<num[i])
                max=num[i];
        }
        num[m]=max+m;
        if(mmax<num[m])
            mmax=num[m];
    }
    printf("%d",mmax);
    return 0;
}