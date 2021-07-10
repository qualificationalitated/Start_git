#include<stdio.h>
int main(){
int t,a,b,targetNum,divideCount,result;
scanf("%d",&t);
while (t--){
scanf("%d %d",&a,&b);
if(a%10==0) printf("10\n");
else{ result=1;
targetNum=a%10;
divideCount=b%4;
if(!divideCount) divideCount=4;
for(int i=0;i<divideCount;i++) result*=targetNum;
printf("%d\n",result%10);}}
return 0;}