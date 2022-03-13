#include<stdio.h>
#define MAX 100002
int dBoss[MAX]={0,};
int naeri[MAX]={0,};
int findBoss(int x){
    if(x==1||naeri[x]){
        return naeri[x];
    }
    return naeri[x]+=findBoss(dBoss[x]);
}
int main(){
    int n,m,i,w;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&dBoss[i]);
    }
    while(m--){
        scanf("%d %d",&i,&w);
        naeri[i]+=w;
    }
    printf("0 ");
    for(int i=2;i<=n;i++){
        naeri[i]+=findBoss(dBoss[i]);
        printf("%d ",naeri[i]);
    }
    return 0;
}