#include<stdio.h>
int list[1002]={0,};
int main()
{
    int n,input,top=0,height=0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int max=0;
        scanf("%d",&input);
        for (int i = input-1; i > 0; i--)
            if(max<list[i])
                max=list[i];
        if(list[input]<max+1){
            list[input]=max+1;
            if(height<list[input])
                height=list[input];
        }   
    }
    printf("%d",height);
    return 0;
}