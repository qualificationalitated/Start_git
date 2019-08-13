#include <stdio.h>
int data=1;
int multiple(int x)
{
    data=data%10*x;
}
int main()
{
    int i;
    int a,b;
    scanf("%d",&i);
    for (int j = 0; j < i; ++j) {
        scanf("%d %d",&a,&b);
        if(a==1 || b==0){
            printf("1\n");
        }
        else {
            for (int k = 0; k < b; k++) {
                multiple(a);
            }
            printf("%d\n",data%10);
            data=1;
        }
    }
    return 0;
}