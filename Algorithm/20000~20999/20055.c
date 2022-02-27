#include<stdio.h>
typedef struct status
{
    int duracell;
    int robot;
}status;
status conveyor[203];
int main()
{
    int n,k,score=1;
    scanf("%d %d",&n,&k);
    for (int i = 1; i <= 2*n; i++){
        conveyor[i].robot=0;
        scanf("%d",&conveyor[i].duracell);
    }
    while(score++){
        status temp=conveyor[2*n];
        for (int i = 2*n; i > 1; i--)
            conveyor[i]=conveyor[i-1];
        conveyor[1]=temp;
        if(conveyor[n].robot)
            conveyor[n].robot=0;
        for (int i = n-1; i >= 1; i--)
        {
            if(conveyor[i].robot){
                if(conveyor[i+1].duracell && conveyor[i+1].robot==0){
                    conveyor[i+1].robot=1;
                    conveyor[i+1].duracell--;
                    conveyor[i].robot=0;
                }
            }
            if(conveyor[n].robot)
                conveyor[n].robot=0;
        }
        if(conveyor[1].duracell){
            conveyor[1].robot=1;
            conveyor[1].duracell-=1;
        }
        int needToStop=0;
        for (int i = 1; i <= 2*n; i++)
            if(!conveyor[i].duracell)
                needToStop++;
        if(needToStop>=k)
            break;
        
    }
    printf("%d",score-1);
    return 0;
}