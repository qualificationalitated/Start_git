#include<iostream>
#include<cstdio>
#include<algorithm>
#define LIM 100000000
int main(){
    int n,k,max=LIM*-1;
    int input,arrSum[100002]={0,};
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&input);
        arrSum[i]=arrSum[i-1]+input;
        
        if(i>=k && max<arrSum[i]-arrSum[i-k])
            max=arrSum[i]-arrSum[i-k];
    }
    printf("%d",max);
    return 0;
}