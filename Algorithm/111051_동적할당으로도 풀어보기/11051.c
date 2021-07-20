#include <stdio.h>
int nList[2][1003]={0,}; //[0][] - For N [1][0] - For K
int dcom(int sNum,int eNum,int check)
{
    int dNum,n;
    for (int i=sNum;i<=eNum;i++){
        n=i;
        dNum=2;
        while (n>1){
            if (n%dNum==0){
                nList[check][dNum]++;
                n=n/dNum;
            }
            else
                dNum++;
        }
    }
    return 0;
}
int main()
{
    int n,k,re=1;
    scanf("%d %d",&n,&k);
    if (n/2+1<=k)
        k=n-k;
    dcom(2,k,1);
    dcom(n-k+1,n,0);
    for (int i=2;i<=n;i++){
        nList[0][i]=nList[0][i]-nList[1][i];
        for (int j=0;j<nList[0][i];j++){
            re=(re*i)%10007;
        }
    }
    printf("%d",re);
    return 0;
}