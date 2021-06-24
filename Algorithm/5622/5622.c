#include<stdio.h>
int main()
{
    char a;
    int time=0;
    while(a!='\n')
    {
        scanf("%c",&a);
        if (a<87){
            if(a<84){
                if(a<80){
                    if(a<77){
                        if(a<74){
                            if(a<71){
                                if(a<68){
                                    time+=3;
                                }
                                else
                                time+=4;
                            }
                            else
                            time+=5;
                        }
                        else
                        time+=6;
                    }
                    else
                    time+=7;
                }
                else
                time+=8;
            }
            else
            time+=9;
        }
        else
        time+=10;  
    }
    printf("%d",time-3);
    return 0;
}