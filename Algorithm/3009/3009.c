#include<stdio.h>
int main()
{
    int sq[2][4];
    for(int i=0;i<3;i++)
        scanf("%d %d",&sq[0][i],&sq[1][i]);
    if(sq[0][0]==sq[0][1])
    sq[0][3]=sq[0][2];
    else if(sq[0][0]==sq[0][2])
    sq[0][3]=sq[0][1];
    else
    sq[0][3]=sq[0][0];
    
    if(sq[1][0]==sq[1][1])
    sq[1][3]=sq[1][2];
    else if(sq[1][0]==sq[1][2])
    sq[1][3]=sq[1][1];
    else
    sq[1][3]=sq[1][0];

    printf("%d %d",sq[0][3],sq[1][3]);
    return 0;
}