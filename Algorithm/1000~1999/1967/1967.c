#include<stdio.h>
#define MAX 10002
int map[MAX][50]={0,},value[MAX],ans=0;
int cCnt[MAX];
int find(int root){
    int bigger=0,big=0;
    for(int i = 0; i < cCnt[root]; i++){
        int x=find(map[root][i]);
        big=x>big?x:big;
        if(big>bigger){
            int temp=big;
            big=bigger;
            bigger=temp;
        }
    }
    if(bigger+big>ans)
        ans=bigger+big;
    return bigger+value[root];
}
int main(){
    int n;
    int a,b,c;
    scanf("%d",&n);
    for (int i = 0; i < n-1; i++){
        scanf("%d %d %d",&a,&b,&c);
        map[a][cCnt[a]++]=b;
        value[b]=c;
    }
    find(1);
    printf("%d",ans);
    return 0;
}