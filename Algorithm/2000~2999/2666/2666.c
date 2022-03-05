#include<stdio.h>
#include<stdlib.h>
int ans=__INT_MAX__;
int use[22];
int find(int k,int x,int move,int openA,int openB){
    // printf("[%d %d %d %d %d]\n",x,move,use[x],openA,openB);
    if(k==x){
        return ans=ans>move?move:ans;
    }
    find(k,x+1,move+abs(openA-use[x]),use[x],openB);
    find(k,x+1,move+abs(openB-use[x]),openA,use[x]);
    return 0;
}
int main(){
    int n,k;
    int openA,openB;
    scanf("%d %d %d %d",&n,&openA,&openB,&k);
    for (int i = 0; i < k; i++)
        scanf("%d",&use[i]);
    find(k,0,0,openA,openB);
    printf("%d",ans);
    return 0;
}