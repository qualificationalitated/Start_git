#include<stdio.h>
#include<string.h>
char elecWave[202];
int waveLen=0,t;
int check(int len, int step){
    int now=elecWave[len]-'0';
    if(step==-1)
        return 0; //불가능
    if(len==waveLen)
        if(step==3||step==6||step==7) return 1;
        else return 0;
    if(!step)
        if(!now) return check(len+1,1);
        else return check(len+1,2);
    else if(step==1)
        if(!now) return check(len+1,-1);
        else return check(len+1,3);
    else if(step==2)
        if(!now) return check(len+1,4);
        else return check(len+1,-1);
    else if(step==3)
        if(!now) return check(len+1,1);
        else return check(len+1,2);
    else if(step==4)
        if(!now) return check(len+1,5);
        else return check(len+1,-1);
    else if(step==5)
        if(!now) return check(len+1,5);
        else return check(len+1,6);
    else if(step==6)
        if(!now) return check(len+1,1);
        else return check(len+1,7);
    else if(step==7)
        if(!now) return check(len+1,8);
        else return check(len+1,7);
    else if(step==8)
        if(!now) return check(len+1,5);
        else return check(len+1,3);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s",elecWave);
        waveLen=strlen(elecWave);
        if(waveLen<2) printf("NO\n");
        else{
            int contacted=check(0,0);
            if(contacted) printf("YES\n");
            else printf("NO\n");           
        }
    }
    return 0;
}