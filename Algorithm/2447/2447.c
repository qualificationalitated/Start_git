#include<stdio.h>
int s(int x,int y,int d) {
    if(x/d==1&&y/d==1){ //if the coordinate is located in center, print space and return. 
        printf(" ");
        return 0;
    }
    if(d==1) printf("*");//if the devide level is the lowest, and the coordinate dose not located in center, print star
    else s(x%d,y%d,d/3);//if the level of devision is not the lowest, re-make the coordinate into the lower level
    return 0;
}
int main(){
    int n,i,j;
    scanf("%d",&n);
    for (i=0;i<n;i++){//check for each coordinate
        for (j=0;j<n;j++)
            s(i,j,n/3);
        printf("\n");
    }
    return 0;
}