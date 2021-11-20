#include<stdio.h>
int map[502],max=0,maxloc=0,sum=0;
int A(int loc){
    for (int i = maxloc+1; i < loc; i++)
        if(map[i]<map[loc])
        {
            sum+=map[loc]-map[i];
            map[i]=map[loc];
        }
    return 0;
}
int B(int loc){
    for (int i = maxloc+1; i < loc; i++)
        if(map[i]<=max)
        {
            sum+=map[maxloc]-map[i];
            map[i]=max;
        }
    return 0;
}
int main(){
    int h,w;
    scanf("%d %d",&h,&w);
    scanf("%d",&map[0]);
    max=map[0];
    for (int i = 1; i < w; i++){
        scanf("%d",&map[i]);
        if(map[i]>map[i-1])
            if(map[i]<max)
                A(i);
            else{
                B(i);
                max=map[i];
                maxloc=i;
            }
    }
    printf("%d",sum);
    return 0;
}