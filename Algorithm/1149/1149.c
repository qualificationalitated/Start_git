#include<stdio.h>
int main(){
    int n,min=__INT_MAX__,i,H[1001][3];
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d%d%d",&H[i][0],&H[i][1],&H[i][2]);
        if(i){
            H[i][0]+=H[i-1][1]<H[i-1][2]?H[i-1][1]:H[i-1][2];
            H[i][1]+=H[i-1][0]<H[i-1][2]?H[i-1][0]:H[i-1][2];
            H[i][2]+=H[i-1][0]<H[i-1][1]?H[i-1][0]:H[i-1][1];
        }
    }
    for (i=0;i<3;i++)
        if(H[n-1][i]<min)
            min=H[n-1][i];
    printf("%d",min);   
    return 0;
}