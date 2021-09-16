#include<stdio.h>
int n,numbers[12],op[4];
int max=-__INT_MAX__,min=__INT_MAX__;
int make(int x,int loc){
    if(loc==n){
        if(max<x)
            max=x;
        if(min>x)
            min=x;
        return 0;
    }
        for(int j=0;j<4;j++)
            if(op[j]){
                op[j]--;
                if(j==0) make(x+numbers[loc],loc+1);
                else if(j==1) make(x-numbers[loc],loc+1);
                else if(j==2) make(x*numbers[loc],loc+1);
                else make(x/numbers[loc],loc+1);
                op[j]++;
            }
    return 0;
}
int main(){
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&numbers[i]);
    scanf("%d %d %d %d",&op[0],&op[1],&op[2],&op[3]);
    make(numbers[0],1);
    printf("%d\n%d",max,min);
    return 0;
}