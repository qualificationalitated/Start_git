#include<stdio.h>
int numListN[30],numListM[30];
int prime_factorization(int n,int nmSelect)
{
    int divideNum=2;
    while(1<n){
        if(n%divideNum==0){
            if(!nmSelect)//n배열용
                numListN[divideNum]++;
            else//m배열용
                numListM[divideNum]++;
            n=n/divideNum;
        }
        else
            divideNum++;
    }
    return 0;
}
int main()
{
    int t,n,m,result=1;
    scanf("%d",&t);
    while (t--)
    {
        for (int i=0;i<=30;i++){
            numListM[i]=0;
            numListN[i]=0;
            result=1;
        }
        scanf("%d %d",&n,&m);
        if(m-n<=m/2)
            n=m-n;
        for (int i=2;i<=m;i++) //소인수 분해로 곱해야 할 숫자들 구하기
        {
            if(i<=n)
                prime_factorization(i,0);//numListN 소인수 구하기
            if((m-n+1)<=i && i<=m)
                prime_factorization(i,1);//numListM 소인수 구하기
        }
        for (int i=2;i<=m;i++){ //소인수들 나눠주기
            numListM[i]=numListM[i]-numListN[i];
            for (int j = 0; j < numListM[i]; j++)
                result=result*i;
        }
        printf("%d\n",result);
    }
    return 0;
}