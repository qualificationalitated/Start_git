#include<stdio.h>
int max(int x,int y){
    return x>y?x:y;
}
int min(int x,int y){
    return x>y?y:x;
}
int arrMax[3]={0,},arrMin[3]={0,},input[3]={0,},n,tempA,tempB;
int main(){
    scanf("%d",&n);
    for (int i = 0; i < 3; i++){
        scanf("%d",&input[i]);
        arrMax[i]=input[i];
        arrMin[i]=input[i];
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int i = 0; i < 3; i++)
            scanf("%d",&input[i]);
        tempA = arrMax[0]; tempB = arrMax[2];
        arrMax[0] = max(arrMax[0], arrMax[1]) + input[0];
        arrMax[2] = max(arrMax[1], arrMax[2]) + input[2];
        arrMax[1] = max(max(tempA, arrMax[1]), tempB) + input[1];

        tempA = arrMin[0]; tempB = arrMin[2];
        arrMin[0] = min(arrMin[0], arrMin[1]) + input[0];
        arrMin[2] = min(arrMin[1], arrMin[2]) + input[2];
        arrMin[1] = min(min(tempA, arrMin[1]), tempB) + input[1];
    }
    printf("%d ",max(max(arrMax[0],arrMax[1]),arrMax[2]));
    printf("%d ",min(min(arrMin[0],arrMin[1]),arrMin[2]));
    
    return 0;
}