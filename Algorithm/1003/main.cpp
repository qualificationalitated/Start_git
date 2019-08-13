#include<stdio.h>
int fibonacci(int n) {
    int list[40]={1,1,};
    for (int i = 2; i < n; i++) {
        list[i]=list[i-1]+list[i-2];
    }
    printf("%d %d\n",list[n-2],list[n-1]);
}
int main()
{
    int a;
    int fibo;
    scanf("%d",&a);
    {
        for (int i = 0; i < a ; ++i) {
            scanf("%d",&fibo);
            if(fibo==0){
                printf("1 0\n");
            }
            else if(fibo==1){
                printf("0 1\n");
            }
            else
            {
                fibonacci(fibo);
            }
        }
    }
    return 0;
}