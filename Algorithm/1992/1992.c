#include<stdio.h>
int map[65][65],i,j;
char input[66];
int find(int n,int x,int y){
    int s=0;
    for(i=x;i<x+n;i++)
        for(j=y;j<y+n;j++)
            s+=map[i][j];
    if(0<s&&s<n*n){
        printf("(");
        find(n/2,x,y);
        find(n/2,x,y+n/2);
        find(n/2,x+n/2,y);
        find(n/2,x+n/2,y+n/2);
        printf(")");
    }
    else
        printf("%d",s/(n*n));
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",input);
        for(j=0;j<n;j++)
            map[i][j]=input[j]-'0';   
    }
    find(n,0,0);
    return 0;
}