#include<stdio.h>
int main()
{
    int testCase;
    int xNow,yNext;
    unsigned int distance;
    unsigned int count=0;
    scanf("%d",&testCase);
    for (int i=0;i<testCase;i++)
    {
        scanf("%d %d",&xNow,&yNext);
        distance=yNext-xNow;
        if(distance<4){
            printf("%u\n",distance);
        }
        else{
            while(count*count<distance)
            {
                count++;
            }
            if(distance>((count*count) + (count-1)*(count-1))/2)
                printf("%u\n",count*2-1);
            else
                printf("%u\n",count*2-2);
        }
        count=0;
    }
    return 0;
}