#include<stdio.h>
long long map[66][11],cnt[66];
int main(){
    int t,i,j;
    scanf("%d",&t);
    for(i=0;i<10;i++)
        map[1][i]=1;
    for(i=1;i<65;i++){
        cnt[i]=1;
        map[i][0]=1;
    }
    cnt[1]=10;
    for(i=2;i<65;i++)
        for(j=1;j<10;j++){
            map[i][j]=map[i-1][j]+map[i][j-1];
            cnt[i]+=map[i][j];
        }
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%lld\n",cnt[n]);
    }
}